#ifndef LISTA_SORT_H
#define LISTA_SORT_H

#include "lista.h"

// Ordenação
void bubble_sort(Lista* lista);               // ordena em ordem crescente

// Buscas
int busca_linear(const Lista* lista, int x);  // O(n), funciona em qualquer lista
int busca_binaria(const Lista* lista, int x); // O(log n), exige lista ordenada

#endif
