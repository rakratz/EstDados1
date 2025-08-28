#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // tamanho máximo do vetor interno

// Estrutura da lista (vetor estático não ordenado)
typedef struct lista {
    int dados[MAX];  // armazena os elementos
    int qtd;         // quantidade atual de elementos
} Lista;

// Funções básicas do TAD Lista
Lista* cria_lista(void);               // cria uma nova lista vazia
void   lista_libera(Lista* lista);         // libera a memória da lista
int    insere_final(Lista* lista, int e);  // insere elemento no final
int    remove_elem(Lista* lista, int e);   // remove a primeira ocorrência
int    busca_elem(const Lista* lista, int e); // busca linear (índice ou -1)
void   imprime_lista(const Lista* lista);  // imprime todos os elementos
int    lista_tamanho(const Lista* lista);  // retorna qtd de elementos
int    insere_ordenado(Lista* lista, int elem); // insere mantendo ordem crescente

#endif
