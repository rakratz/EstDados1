#ifndef PQ_H
#define PQ_H

#include <stdbool.h>

// Estrutura de item da fila de prioridade
typedef struct
{
    int prioridade; // menor número = maior prioridade
    int valor;      // dado associado
} PQItem;

// Tipo opaco da fila de prioridade
typedef struct pqueue PQueue;

// Criação / destruição
PQueue *pq_cria(int capacidade);
void pq_libera(PQueue *pq);

// Estado
bool pq_vazia(const PQueue *pq);
bool pq_cheia(const PQueue *pq);
int pq_tamanho(const PQueue *pq);

// Operações
bool pq_enfileirar(PQueue *pq, int valor, int prioridade);
bool pq_desenfileirar(PQueue *pq, PQItem *out);
bool pq_topo(const PQueue *pq, PQItem *out);
void pq_listar(const PQueue *pq, bool em_ordem);

#endif
