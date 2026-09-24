// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Beltrán Rodrigo Barrios González
// Correo: alu0101718330@ull.edu.es
// Fecha: 24/09/2026
// Archivo cya-P02-strings.cc: Programa cliente principal.
//      Procesa un fichero de cadenas y alfabetos aplicando la operación indicada por opcode.
// Referencias:
//      Guía de estilo de Google C++
// Historial de revisiones:
//      24/09/2026 - Creación inicial del código.

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "alphabet.h"
#include "chain.h"
#include "language.h"

void ShowUsage(const std::string& program_name) {
  std::cout << "Modo de empleo: " << program_name << " filein.txt fileout.txt opcode\n";
  std::cout << "Pruebe '" << program_name << " --help' para más información.\n";
}

void ShowHelp(const std::string& program_name) {
  std::cout << "Uso: " << program_name << " filein.txt fileout.txt opcode\n\n";
  std::cout << "Parámetros:\n";
  std::cout << "  filein.txt   Fichero de texto con las cadenas y sus alfabetos asociados (uno por línea).\n";
  std::cout << "  fileout.txt  Fichero donde se escribirá la salida resultante.\n";
  std::cout << "  opcode       Código numérico de la operación a ejecutar (1-6):\n";
  std::cout << "                 1: Alfabeto asociado a cada cadena.\n";
  std::cout << "                 2: Longitud de cada cadena.\n";
  std::cout << "                 3: Inversa de cada cadena.\n";
  std::cout << "                 4: Conjunto de prefijos (lenguaje ordenado por longitud).\n";
  std::cout << "                 5: Conjunto de sufijos (lenguaje ordenado por longitud).\n";
  std::cout << "                 6: Validación (OK si la cadena pertenece a su alfabeto, ERROR si no).\n";
}

int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    ShowHelp(argv[0]);
    return 0;
  }

  if (argc != 4) {
    ShowUsage(argv[0]);
    return 1;
  }

  std::string input_filename = argv[1];
  std::string output_filename = argv[2];
  int opcode = 0;

  try {
    opcode = std::stoi(argv[3]);
  } catch (...) {
    std::cerr << "Error: El opcode debe ser un valor entero entre 1 y 6.\n";
    return 1;
  }

  if (opcode < 1 || opcode > 6) {
    std::cerr << "Error: Opcode no reconocido. Debe ser un número del 1 al 6.\n";
    return 1;
  }

  std::ifstream input_file(input_filename);
  if (!input_file.is_open()) {
    std::cerr << "Error: No se pudo abrir el fichero de entrada: " << input_filename << "\n";
    return 1;
  }

  std::ofstream output_file(output_filename);
  if (!output_file.is_open()) {
    std::cerr << "Error: No se pudo crear/abrir el fichero de salida: " << output_filename << "\n";
    return 1;
  }

  std::string line;
  while (std::getline(input_file, line)) {
    if (line.empty()) {
      continue;
    }
    std::istringstream iss(line);
    std::string chain_str;
    std::string alphabet_str;

    if (!(iss >> chain_str)) {
      continue;
    }
    // Se toma el resto de la línea como alfabeto para admitir varios símbolos
    // separados por espacios o tabuladores.
    std::getline(iss, alphabet_str);

    Chain chain(chain_str);
    Alphabet alphabet(alphabet_str);

    switch (opcode) {
      case 1:
        output_file << chain << ": " << alphabet << "\n";
        break;
      case 2:
        output_file << chain.Length() << "\n";
        break;
      case 3:
        output_file << chain << " -> " << chain.Inverse() << "\n";
        break;
      case 4:
        output_file << chain.Prefixes() << "\n";
        break;
      case 5:
        output_file << chain.Suffixes() << "\n";
        break;
      case 6:
        output_file << (chain.Validate(alphabet) ? "OK" : "ERROR") << "\n";
        break;
      default:
        break;
    }
  }

  input_file.close();
  output_file.close();
  return 0;
}
