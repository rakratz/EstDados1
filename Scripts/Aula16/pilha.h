#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>

/* Nó da lista encadeada simples */
typedef struct No
{
    int valor;
    struct No *prox;
} No;

/* Pilha com ponteiro para o topo (cabeça) e contador de tamanho */
typedef struct Pilha
{
    No *topo;
    int tamanho;
} Pilha;

/* Inicializa a pilha (topo = NULL, tamanho = 0) */
void pilha_inicializar(Pilha *p);

/* Retorna 1 se pilha vazia, 0 caso contrário */
int pilha_vazia(const Pilha *p);

/* Empilha (push): retorna 1 se OK, 0 se falha de alocação */
int pilha_empilhar(Pilha *p, int v);

/* Desempilha (pop): retorna 1 se OK (e escreve em *out), 0 se vazia */
int pilha_desempilhar(Pilha *p, int *out);

/* (Opcional) Lê valor do topo sem remover: 1 se OK, 0 se vazia */
int pilha_topo(const Pilha *p, int *out);

/* (Opcional) Imprime do topo até a base */
void pilha_imprimir(const Pilha *p);

/* (Opcional) Esvazia a pilha liberando memória */
void pilha_limpar(Pilha *p);

#endif /* PILHA_H */
