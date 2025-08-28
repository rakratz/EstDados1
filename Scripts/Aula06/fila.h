#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FCAP 8  // capacidade padrão (pode alterar)

typedef struct fila {
    int dados[FCAP]; // buffer circular
    int ini;         // índice do primeiro elemento (frente)
    int fim;         // índice da próxima posição livre (traseira)
    int qtd;         // quantidade de elementos na fila
} Fila;

// criação / destruição
Fila* fila_cria(void);
void  fila_libera(Fila* f);

// estado
bool  fila_vazia(const Fila* f);
bool  fila_cheia(const Fila* f);
int   fila_tamanho(const Fila* f);

// operações básicas
int incluir(Fila* f, int x);            // enqueue no fim
static inline int inserir_final(Fila* f, int x) { return incluir(f, x); }
int excluir(Fila* f, int* out);         // dequeue da frente

// utilidades
int  pesquisar(const Fila* f, int x);   // retorna posição lógica [0..qtd-1] ou -1
void listar(const Fila* f);

// extras
int inserir_ordenado(Fila* f, int x);   // mantém ordem crescente (O(n))
int excluir_valor(Fila* f, int x);      // remove 1ª ocorrência (O(n))

#endif
