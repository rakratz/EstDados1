#include "pilha.h"
#include <stdlib.h>

void pilha_inicializar(Pilha *p)
{
    p->topo = NULL;
    p->tamanho = 0;
}

int pilha_vazia(const Pilha *p)
{
    return (p->topo == NULL);
}

int pilha_empilhar(Pilha *p, int v)
{
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        /* Falha de alocação */
        return 0;
    }
    novo->valor = v;
    novo->prox = p->topo; /* encadeia no topo */
    p->topo = novo;
    p->tamanho++;
    return 1;
}

int pilha_desempilhar(Pilha *p, int *out)
{
    if (pilha_vazia(p))
    {
        return 0;
    }
    No *rem = p->topo;
    if (out)
        *out = rem->valor;
    p->topo = rem->prox;
    free(rem);
    p->tamanho--;
    return 1;
}

int pilha_topo(const Pilha *p, int *out)
{
    if (pilha_vazia(p))
    {
        return 0;
    }
    if (out)
        *out = p->topo->valor;
    return 1;
}

void pilha_imprimir(const Pilha *p)
{
    printf("Pilha (topo -> base): ");
    if (pilha_vazia(p))
    {
        printf("[vazia]\n");
        return;
    }
    for (No *q = p->topo; q != NULL; q = q->prox)
    {
        printf("%d%s", q->valor, q->prox ? " -> " : " -> NULL\n");
    }
}

void pilha_limpar(Pilha *p)
{
    int lixo;
    while (pilha_desempilhar(p, &lixo))
    {
        /* esvazia */
    }
}
