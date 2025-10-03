#ifndef LISTA_H
#define LISTA_H
#include <stddef.h>

typedef struct No
{
    int dado;
    struct No *ant;
    struct No *prox;
} No;

typedef struct
{
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

// O(1)
int removeInicio(Lista *lista);

// O(1)
int removeFim(Lista *lista);

// O(n) (Ω(1) no melhor caso)
int removeElemento(Lista *lista, int valor);

// O(n)
No *busca(Lista *lista, int valor);

// O(n) (Ω(1) no melhor caso)
int atualizaElemento(Lista *lista, int valor, int novo_valor);

// O(n)
void imprimeLista(Lista *lista);

// O(n) - opcional, útil para checar os ponteiros "ant"
void imprimeListaReversa(Lista *lista);

// Libera todos os nós de dados e mantém as sentinelas prontas para reuso (lista vazia)
void liberaLista(Lista *lista);

// Destroi completamente a lista, inclusive as sentinelas
void destroiLista(Lista *lista);

#endif