#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

/* Criação / destruição */
Fila *criarFila() {
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f != NULL)
    {
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }
    return f;
}

void limparFila(Fila *f) {
    if (f == NULL)
        return;
    No *atual = f->inicio;
    while (atual != NULL) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}
void destruirFila(Fila *f){
    if (f == NULL)
        return;
    limparFila(f);
    free(f);
}


/* Operações básicas */
int filaVazia(Fila *f) {
    return (f == NULL || f->inicio == NULL);
}
int enfileirar(Fila *f, Pessoa p) {        /* insere no fim */
    if (f == NULL)
        return;
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL)
        return 0;
    novo->dado = p;
    novo->prox = NULL;
    novo->ant = f->fim;

    if (filaVazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->tamanho++;
    return 1;
}
int desenfileirar(Fila *f, Pessoa *pOut){ /* remove do início */
    if (f == NULL || filaVazia(f))
        return 0;
    No *rem = f->inicio;
    if (pOut != NULL) {
        *pOut = rem->dado;
    }
    f->inicio = rem->prox;
    if (f->inicio != NULL) {
        f->inicio->ant = NULL;
    } else {
        f->fim = NULL;
    }
    free(rem);
    f->tamanho--;
    return 1;
}
/* Utilitários */
void imprimirFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    No *atual = f->inicio;
    printf("Tamanho da fila: %d\n", f->tamanho);
    while (atual != NULL) {
        printf("Nome: %-20s | Idade: %d\n",
               atual->dado.nome, atual->dado.idade);
        atual = atual->prox;
    }
}

/* Ordenação por idade: crescente != 0 -> crescente; 0 -> decrescente */
void ordenarPorIdade(Fila *f, int crescente);

/* Busca/remoção/atualização por nome (igualdade exata) */
No *buscarPorNome(Fila *f, const char *nome);
int removerPorNome(Fila *f, const char *nome);
int atualizarPessoa(Fila *f, const char *nomeAntigo, Pessoa novaPessoa);
