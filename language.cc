// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Beltrán Rodrigo Barrios González
// Correo: alu0101718330@ull.edu.es
// Fecha: 24/09/2026
// Archivo language.cc: Implementación de la clase Language.
// Referencias:
//      Guía de estilo de Google C++
// Historial de revisiones:
//      24/09/2026 - Creación inicial del código.

#include "language.h"

void Language::Insert(const Chain& chain) {
  chains_.insert(chain);
}

std::ostream& operator<<(std::ostream& os, const Language& language) {
  os << "{";
  bool first = true;
  for (const auto& chain : language.chains_) {
    if (!first) {
      os << ", ";
    }
    os << chain;
    first = false;
  }
  os << "}";
  return os;
}
