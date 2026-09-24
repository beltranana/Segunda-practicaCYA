// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Beltrán Rodrigo Barrios González
// Correo: alu0101718330@ull.edu.es
// Fecha: 24/09/2026
// Archivo symbol.h: Definición de la clase Symbol.
//      Representa un símbolo individual de un alfabeto.
// Referencias:
//      Guía de estilo de Google C++
// Historial de revisiones:
//      24/09/2026 - Creación inicial del código.

#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <iostream>

class Symbol {
 public:
  Symbol() : character_('\0') {}
  explicit Symbol(char c) : character_(c) {}

  char GetCharacter() const { return character_; }

  bool operator<(const Symbol& other) const {
    return character_ < other.character_;
  }
  bool operator==(const Symbol& other) const {
    return character_ == other.character_;
  }
  bool operator!=(const Symbol& other) const {
    return !(*this == other);
  }

  friend std::ostream& operator<<(std::ostream& os, const Symbol& sym);
  friend std::istream& operator>>(std::istream& is, Symbol& sym);

 private:
  char character_;
};

#endif  // SYMBOL_H_
