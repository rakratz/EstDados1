#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializaLista(Lista *l) {
    l->cabeca = (No*) malloc(sizeof(No));
    if (l->cabeca == NULL) {
        printf("Erro: sem memória!\n");
        exit(1);
    }
    l->cabeca->prox = NULL; // lista vazia
}

int estaVazia(Lista *l) {
    return l->cabeca->prox == NULL;
}

void insereInicio(Lista *l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = l->cabeca->prox;
    l->cabeca->prox = novo;
}

void insereFim(Lista *l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;

    No *aux = l->cabeca;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
}

No* busca(Lista *l, int valor) {
    No *aux = l->cabeca->prox;
    while (aux != NULL) {
        if (aux->dado == valor) return aux;
        aux = aux->prox;
    }
    return NULL;
}

int removeElemento(Lista *l, int valor) {
    No *ant = l->cabeca;
    No *atual = l->cabeca->prox;

    while (atual != NULL) {
        if (atual->dado == valor) {
            ant->prox = atual->prox;
            free(atual);
            return 1; // sucesso
        }
        ant = atual;
        atual = atual->prox;
    }
    return 0; // não achou
}

void imprimeLista(Lista *l) {
    if (estaVazia(l)) {
        printf("Lista vazia.\n");
        return;
    }
    No *aux = l->cabeca->prox;
    printf("Lista: ");
    while (aux != NULL) {
        printf("%d -> ", aux->dado);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void liberaLista(Lista *l) {
    No *aux = l->cabeca;
    while (aux != NULL) {
        No *tmp = aux;
        aux = aux->prox;
        free(tmp);
    }
    l->cabeca = NULL;
}
