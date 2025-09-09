#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct
{
    int dados[MAX];
    int qtd; // quantidade de elementos válidos [0..MAX]
} Lista;

// --- CRUD básico (apoio aos testes) ---
Lista *lista_cria(void);
void lista_libera(Lista *l);
bool lista_vazia(const Lista *l);
bool lista_cheia(const Lista *l);
int lista_tamanho(const Lista *l);
int lista_insere_final(Lista *l, int x); // O(1) amortizado
void lista_imprime(const Lista *l);

// --- Ordenações desta aula ---
void insertion_sort(Lista *l);
void selection_sort(Lista *l); 

#endif
