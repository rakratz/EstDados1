#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// O(1)
void inicializarLista(Lista *lista){
    lista->cabeca = (No *)malloc(sizeof(No));
    lista->calda = (No *)malloc(sizeof(No));
    if (!lista->cabeca || !lista->calda)
    {
        printf("Erro: sem memória para criar a lista\n");
        exit(1);
    }

    lista->cabeca->ant = NULL;
    lista->cabeca->prox = lista->calda;

    lista->calda->prox = NULL;
    lista->cabeca->ant = lista->cabeca;

    lista->tamanho = 0;
}

// O(1)
int estaVazia(Lista *lista){
    if (lista->cabeca->prox == lista->calda){
        return 1;
    } else {
        return 0;
    }
}

// O(1)
void insereInicio(Lista *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        printf("Erro: sem memória para inserir\n");
        return;
    }
    novo->dado = valor;
    // Insere entre cabeca e o primeiro nó de dados (ou a calda, se vazia)
    novo->ant = lista->cabeca;
    novo->prox = lista->cabeca->prox;

    lista->cabeca->prox->ant = novo;
    lista->cabeca->prox = novo;

    lista->tamanho++;
}

void imprimeLista(Lista *lista){
    if (estaVazia(lista))
    {
            printf("Lista está vazia!\n");
            return;
    }
    printf("NULL <-> ");
    for (No *aux = lista->cabeca->prox; aux != lista->calda; aux = aux->prox) {
        printf("%d <-> ", aux->dado);
    }
    printf("NULL \n");
}

// O(1)
void insereFim(Lista *lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        printf("Erro: sem memória para inserir!\n");
        return;
    }
    novo->dado = valor;

    // Insere imediatamente antes da calda
    novo->prox = lista->calda;
    novo->ant = lista->calda->ant;

    lista->calda->ant->prox = novo;
    lista->calda->ant = novo;

    lista->tamanho++;
}