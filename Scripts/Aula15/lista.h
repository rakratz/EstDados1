#ifndef LISTA_H
#define LISTA_H
#include <stddef.h>


typedef struct No
{
   int dado;
   struct No *ant;
   struct No *prox;
} No;

typedef struct {
    No *cabeca; // ponteiro do inicio da lista
    No *calda;  // ponteiro do final da lista
    size_t tamanho;
} Lista;

// O(1)
void inicializarLista(Lista *lista);

// O(1)
int estaVazia(Lista *lista);

// O(1)
void insereInicio(Lista *lista, int valor);

// O(1)
void insereFim(Lista *lista, int valor);

//O(n)
void imprimeLista(Lista *lista);

// O(1)
int removeInicio(Lista *lista);

// O(1)
int removeFim(Lista *lista);

#endif