#include <stdio.h>
#include "pq.h"

int main(void)
{
    PQueue *pq = pq_cria(10);

    pq_enfileirar(pq, 42, 5);
    pq_enfileirar(pq, 13, 2);
    pq_enfileirar(pq, 99, 9);
    pq_enfileirar(pq, 77, 1);

    printf("Estrutura interna do heap:\n");
    pq_listar(pq, false);

    printf("\nElementos em ordem de prioridade:\n");
    pq_listar(pq, true);

    PQItem it;
    if (pq_topo(pq, &it))
        printf("Topo: valor=%d prioridade=%d\n", it.valor, it.prioridade);

    while (pq_desenfileirar(pq, &it))
    {
        printf("Saiu: valor=%d prioridade=%d\n", it.valor, it.prioridade);
    }

    pq_listar(pq, true);

    pq_libera(pq);
    return 0;
}
