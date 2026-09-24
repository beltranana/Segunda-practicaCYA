// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Beltrán Rodrigo Barrios González
// Correo: alu0101718330@ull.edu.es
// Fecha: 24/09/2026
// Archivo chain.h: Definición de la clase Chain.
//      Representa una secuencia finita de símbolos.
// Referencias:
//      Guía de estilo de Google C++
// Historial de revisiones:
//      24/09/2026 - Creación inicial del código.

#ifndef CHAIN_H_
#define CHAIN_H_

#include <iostream>
#include <string>
#include <vector>

#include "alphabet.h"
#include "symbol.h"

class Language;

class Chain {
 public:
  Chain();
  explicit Chain(const std::string& str);
  explicit Chain(const std::vector<Symbol>& symbols);

  size_t Length() const;
  bool IsEmpty() const;
  Chain Inverse() const;
  Language Prefixes() const;
  Language Suffixes() const;
  bool Validate(const Alphabet& alphabet) const;

  bool operator<(const Chain& other) const;
  bool operator==(const Chain& other) const;

  friend std::ostream& operator<<(std::ostream& os, const Chain& chain);
  friend std::istream& operator>>(std::istream& is, Chain& chain);

 private:
  std::vector<Symbol> symbols_;
};

#endif  // CHAIN_H_
