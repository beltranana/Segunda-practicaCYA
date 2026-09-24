// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Beltrán Rodrigo Barrios González
// Correo: alu0101718330@ull.edu.es
// Fecha: 24/09/2026
// Archivo alphabet.cc: Implementación de la clase Alphabet.
// Referencias:
//      Guía de estilo de Google C++
// Historial de revisiones:
//      24/09/2026 - Creación inicial del código.

#include "alphabet.h"

Alphabet::Alphabet(const std::string& symbols_str) {
  for (char ch : symbols_str) {
    if (ch != '&' && ch != ' ' && ch != '\t') {
      symbols_.insert(Symbol(ch));
    }
  }
}

void Alphabet::Insert(const Symbol& s) {
  if (s.GetCharacter() != '&') {
    symbols_.insert(s);
  }
}

bool Alphabet::Contains(const Symbol& s) const {
  return symbols_.find(s) != symbols_.end();
}

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  os << "{";
  bool first = true;
  for (const auto& sym : alphabet.symbols_) {
    if (!first) {
      os << ", ";
    }
    os << sym;
    first = false;
  }
  os << "}";
  return os;
}
