// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Beltrán Rodrigo Barrios González
// Correo: alu0101718330@ull.edu.es
// Fecha: 24/09/2026
// Archivo alphabet.h: Definición de la clase Alphabet.
//      Representa un conjunto finito y no vacío de símbolos mediante std::set.
// Referencias:
//      Guía de estilo de Google C++
// Historial de revisiones:
//      24/09/2026 - Creación inicial del código.

#ifndef ALPHABET_H_
#define ALPHABET_H_

#include <iostream>
#include <set>
#include <string>

#include "symbol.h"

class Alphabet {
 public:
  Alphabet() = default;
  explicit Alphabet(const std::string& symbols_str);

  void Insert(const Symbol& s);
  bool Contains(const Symbol& s) const;
  size_t Size() const { return symbols_.size(); }
  const std::set<Symbol>& GetSymbols() const { return symbols_; }

  friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

 private:
  std::set<Symbol> symbols_;
};

#endif  // ALPHABET_H_
