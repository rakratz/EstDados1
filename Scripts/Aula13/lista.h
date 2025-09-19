#ifndef LISTA_H
#define LISTA_H

// Estrutura do nó
typedef struct No {
    int dado;
    struct No *prox;
} No;

// Estrutura da lista (com nó cabeça)
typedef struct {
    No *cabeca;  // sempre aponta para o nó cabeça
} Lista;

// Funções
void inicializaLista(Lista *l);
int estaVazia(Lista *l);
void insereInicio(Lista *l, int valor);
void insereFim(Lista *l, int valor);
No* busca(Lista *l, int valor);
int removeElemento(Lista *l, int valor);
void imprimeLista(Lista *l);
void liberaLista(Lista *l);

#endif
