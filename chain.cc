// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Beltrán Rodrigo Barrios González
// Correo: alu0101718330@ull.edu.es
// Fecha: 24/09/2026
// Archivo chain.cc: Implementación de la clase Chain.
// Referencias:
//      Guía de estilo de Google C++
// Historial de revisiones:
//      24/09/2026 - Creación inicial del código.

#include "chain.h"

#include <algorithm>
#include "language.h"

Chain::Chain() = default;

Chain::Chain(const std::string& str) {
  if (str != "&") {
    for (char c : str) {
      symbols_.emplace_back(c);
    }
  }
}

Chain::Chain(const std::vector<Symbol>& symbols) : symbols_(symbols) {}

size_t Chain::Length() const {
  return symbols_.size();
}

bool Chain::IsEmpty() const {
  return symbols_.empty();
}

Chain Chain::Inverse() const {
  if (IsEmpty()) {
    return Chain();
  }
  std::vector<Symbol> rev_syms = symbols_;
  std::reverse(rev_syms.begin(), rev_syms.end());
  return Chain(rev_syms);
}

Language Chain::Prefixes() const {
  Language result;
  result.Insert(Chain());  // Cadena vacía (&)
  std::vector<Symbol> current;
  for (size_t i = 0; i < symbols_.size(); ++i) {
    current.push_back(symbols_[i]);
    result.Insert(Chain(current));
  }
  return result;
}

Language Chain::Suffixes() const {
  Language result;
  result.Insert(Chain());  // Cadena vacía (&)
  for (size_t i = symbols_.size(); i > 0; --i) {
    std::vector<Symbol> current(symbols_.begin() + (i - 1), symbols_.end());
    result.Insert(Chain(current));
  }
  return result;
}

bool Chain::Validate(const Alphabet& alphabet) const {
  for (const auto& sym : symbols_) {
    if (!alphabet.Contains(sym)) {
      return false;
    }
  }
  return true;
}

// Criterio de ordenación natural: primero por longitud y a igualdad por valor lexicográfico
bool Chain::operator<(const Chain& other) const {
  if (Length() != other.Length()) {
    return Length() < other.Length();
  }
  for (size_t i = 0; i < symbols_.size(); ++i) {
    if (symbols_[i] != other.symbols_[i]) {
      return symbols_[i] < other.symbols_[i];
    }
  }
  return false;
}

bool Chain::operator==(const Chain& other) const {
  if (Length() != other.Length()) {
    return false;
  }
  for (size_t i = 0; i < symbols_.size(); ++i) {
    if (symbols_[i] != other.symbols_[i]) {
      return false;
    }
  }
  return true;
}

std::ostream& operator<<(std::ostream& os, const Chain& chain) {
  if (chain.IsEmpty()) {
    os << "&";
  } else {
    for (const auto& sym : chain.symbols_) {
      os << sym;
    }
  }
  return os;
}

std::istream& operator>>(std::istream& is, Chain& chain) {
  std::string s;
  if (is >> s) {
    chain = Chain(s);
  }
  return is;
}
