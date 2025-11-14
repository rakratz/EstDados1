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
int filaVazia(Fila *f);
int enfileirar(Fila *f, Pessoa p);        /* insere no fim */
int desenfileirar(Fila *f, Pessoa *pOut); /* remove do início */

/* Utilitários */
void imprimirFila(Fila *f);

/* Ordenação por idade: crescente != 0 -> crescente; 0 -> decrescente */
void ordenarPorIdade(Fila *f, int crescente);

/* Busca/remoção/atualização por nome (igualdade exata) */
No *buscarPorNome(Fila *f, const char *nome);
int removerPorNome(Fila *f, const char *nome);
int atualizarPessoa(Fila *f, const char *nomeAntigo, Pessoa novaPessoa);
