#include "lista.h"

Lista *lista_cria(void)
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l)
        l->qtd = 0;
    return l;
}

void lista_libera(Lista *l)
{
    free(l);
}

bool lista_vazia(const Lista *l)
{
    return !l || l->qtd == 0;
}

bool lista_cheia(const Lista *l)
{
    return l && l->qtd == MAX;
}

int lista_insere_final(Lista *l, int x)
{
    if (!l || lista_cheia(l))
        return 0;
    l->dados[l->qtd++] = x;
    return 1;
}

void lista_imprime(const Lista *l)
{
    if (!l || l->qtd == 0)
    {
        printf("[]\n");
        return;
    }
    printf("[");
    for (int i = 0; i < l->qtd; i++)
    {
        printf("%d", l->dados[i]);
        if (i < l->qtd - 1)
            printf(", ");
    }
    printf("]\n");
}

/* Insertion Sort */
void insertion_sort(Lista *l)
{
    if (!l || l->qtd < 2)
        return;

    for (int i = 1; i < l->qtd; i++)
    {
        int chave = l->dados[i];
        int j = i - 1;
        while (j >= 0 && l->dados[j] > chave)
        {
            l->dados[j + 1] = l->dados[j];
            j--;
        }
        l->dados[j + 1] = chave;
    }
}

/* Selection Sort */
void selection_sort(Lista *l)
{
    if (!l || l->qtd < 2)
        return;

    for (int i = 0; i < l->qtd - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < l->qtd; j++)
        {
            if (l->dados[j] < l->dados[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int tmp = l->dados[i];
            l->dados[i] = l->dados[min];
            l->dados[min] = tmp;
        }
    }
}
