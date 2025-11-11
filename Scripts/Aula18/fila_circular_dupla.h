#ifndef FILA_CIRCULAR_DUPLA_H
#define FILA_CIRCULAR_DUPLA_H

#include <stddef.h> /* size_t */

/* Nó da lista duplamente encadeada circular */
typedef struct FCDNodo
{
    int valor;
    struct FCDNodo *prox;
    struct FCDNodo *ant;
} FCDNodo;

/* Estrutura de dados da Fila Circular Dupla */
typedef struct
{
    FCDNodo *frente; /* aponta para o primeiro elemento */
    size_t tamanho;
} FilaCircularDupla;

/* Inicializa a fila */
void fila_circular_inicializar(FilaCircularDupla *f);

/* Retorna 1 se vazia e 0 caso contrário */
int fila_circular_vazia(const FilaCircularDupla *f);

/* Retorna o tamanho da fila */
size_t fila_circular_tamanho(const FilaCircularDupla *f);

/* Enfileira no final da fila (retorna 1 se ok; 0 se erro de memória) */
int fila_circular_enfileirar(FilaCircularDupla *f, int valor);

/* Lê o elemento da frente sem remover (retorna 1 se ok; 0 se vazia) */
int fila_circular_frente(const FilaCircularDupla *f, int *out);

/* Desenfileira no início da fila (retorna 1 se ok; 0 se vazia) */
int fila_circular_desenfileirar(FilaCircularDupla *f, int *out);

/* Remove todos os nós (fila fica vazia) */
void fila_circular_limpar(FilaCircularDupla *f);

/* Imprime a fila (utilitário de depuração) */
void fila_circular_imprimir(const FilaCircularDupla *f);

#endif /* FILA_CIRCULAR_DUPLA_H */