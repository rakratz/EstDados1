#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int dado;           // valor armazenado
    struct No *prox;    // ponteiro para o próximo nó
} No;

typedef struct {
    No *cabeca;
    // No *calda;
} Lista;

void inicializaLista(Lista *lista);
int estaVazia(Lista *lista);
void insereInicio(Lista *lista, int valor);
void insereFim(Lista *lista, int valor);
No *busca(Lista *lista, int valor);
int removeElemento(Lista *lista, int valor);
int removeInicio(Lista *lista);
int removeFim(Lista *lista);
int atualizaElemento(Lista *lista, int valor, int novo_valor);
void imprimeLista(Lista *lista);
void liberaLista(Lista *lista);

#endif