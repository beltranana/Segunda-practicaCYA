// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Beltrán Rodrigo Barrios González
// Correo: alu0101718330@ull.edu.es
// Fecha: 24/09/2026
// Archivo symbol.cc: Implementación de operadores de E/S para Symbol.
// Referencias:
//      Guía de estilo de Google C++
// Historial de revisiones:
//      24/09/2026 - Creación inicial del código.

#include "symbol.h"

std::ostream& operator<<(std::ostream& os, const Symbol& sym) {
  os << sym.character_;
  return os;
}

std::istream& operator>>(std::istream& is, Symbol& sym) {
  is >> sym.character_;
  return is;
}
