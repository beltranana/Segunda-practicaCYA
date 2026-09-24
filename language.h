// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Beltrán Rodrigo Barrios González
// Correo: alu0101718330@ull.edu.es
// Fecha: 24/09/2026
// Archivo language.h: Definición de la clase Language.
//      Representa un conjunto de cadenas ordenadas según longitud.
// Referencias:
//      Guía de estilo de Google C++
// Historial de revisiones:
//      24/09/2026 - Creación inicial del código.

#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include <iostream>
#include <set>

#include "chain.h"

class Language {
 public:
  Language() = default;

  void Insert(const Chain& chain);
  size_t Size() const { return chains_.size(); }
  const std::set<Chain>& GetChains() const { return chains_; }

  friend std::ostream& operator<<(std::ostream& os, const Language& language);

 private:
  std::set<Chain> chains_;
};

#endif  // LANGUAGE_H_
