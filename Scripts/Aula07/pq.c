#include "pq.h"
#include <stdlib.h>

struct pqueue
{
    PQItem *itens;  // vetor de itens (heap)
    int capacidade; // tamanho máximo
    int n;          // quantidade atual
};

// ---------- Helpers ----------
static void troca(PQItem *a, PQItem *b)
{
    PQItem tmp = *a;
    *a = *b;
    *b = tmp;
}

// retorna true se item a "melhor" que b (menor prioridade = mais importante)
static inline bool melhor(PQItem a, PQItem b)
{
    return a.prioridade < b.prioridade;
}

static void sift_up(PQueue *pq, int i)
{
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (!melhor(pq->itens[i], pq->itens[p]))
            break;
        troca(&pq->itens[i], &pq->itens[p]);
        i = p;
    }
}

static void sift_down(PQueue *pq, int i)
{
    while (1)
    {
        int l = 2 * i + 1, r = 2 * i + 2, best = i;
        if (l < pq->n && melhor(pq->itens[l], pq->itens[best]))
            best = l;
        if (r < pq->n && melhor(pq->itens[r], pq->itens[best]))
            best = r;
        if (best == i)
            break;
        troca(&pq->itens[i], &pq->itens[best]);
        i = best;
    }
}

// ---------- API ----------
PQueue *pq_cria(int capacidade)
{
    PQueue *pq = malloc(sizeof(PQueue));
    if (!pq)
        return NULL;
    pq->itens = malloc(sizeof(PQItem) * capacidade);
    if (!pq->itens)
    {
        free(pq);
        return NULL;
    }
    pq->capacidade = capacidade;
    pq->n = 0;
    return pq;
}

void pq_libera(PQueue *pq)
{
    if (!pq)
        return;
    free(pq->itens);
    free(pq);
}

bool pq_vazia(const PQueue *pq) { return pq->n == 0; }
bool pq_cheia(const PQueue *pq) { return pq->n == pq->capacidade; }
int pq_tamanho(const PQueue *pq) { return pq->n; }

bool pq_enfileirar(PQueue *pq, int valor, int prioridade)
{
    if (pq_cheia(pq))
        return false;
    PQItem novo = {.prioridade = prioridade, .valor = valor};
    pq->itens[pq->n] = novo;
    sift_up(pq, pq->n);
    pq->n++;
    return true;
}

bool pq_desenfileirar(PQueue *pq, PQItem *out)
{
    if (pq_vazia(pq))
        return false;
    if (out)
        *out = pq->itens[0];
    pq->n--;
    pq->itens[0] = pq->itens[pq->n];
    sift_down(pq, 0);
    return true;
}

bool pq_topo(const PQueue *pq, PQItem *out)
{
    if (pq_vazia(pq))
        return false;
    if (out)
        *out = pq->itens[0];
    return true;
}

void pq_listar(const PQueue *pq, bool em_ordem)
{
    if (!pq || pq_vazia(pq))
    {
        printf("(fila vazia)\n");
        return;
    }

    if (!em_ordem)
    {
        // 1) Listar como está no heap (estrutura interna)
        printf("Heap (tamanho=%d): ", pq->n);
        for (int i = 0; i < pq->n; i++)
        {
            printf("[val=%d prio=%d] ", pq->itens[i].valor, pq->itens[i].prioridade);
        }
        printf("\n");
    }
    else
    {
        // 2) Listar em ordem de prioridade (sem destruir a fila)
        printf("Fila em ordem de prioridade: ");
        // cópia temporária
        PQueue tmp = *pq;
        tmp.itens = malloc(sizeof(PQItem) * pq->capacidade);
        for (int i = 0; i < pq->n; i++)
            tmp.itens[i] = pq->itens[i];

        PQItem it;
        while (tmp.n > 0)
        {
            it = tmp.itens[0];
            tmp.n--;
            tmp.itens[0] = tmp.itens[tmp.n];
            sift_down(&tmp, 0);
            printf("[val=%d prio=%d] ", it.valor, it.prioridade);
        }
        free(tmp.itens);
        printf("\n");
    }
}
