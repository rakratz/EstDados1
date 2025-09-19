#include <stdio.h>
#include "vetor.h"

void inicializaVetor(Vetor *v)
{
    v->tamanho = 0;
}

void insereElemento(Vetor *v, int valor)
{
    if (v->tamanho < MAX)
    {
        v->dados[v->tamanho] = valor;
        v->tamanho++;
    }
    else
    {
        printf("Vetor cheio!\n");
    }
}

void imprimeVetor(Vetor *v)
{
    for (int i = 0; i < v->tamanho; i++)
    {
        printf("%d ", v->dados[i]);
    }
    printf("\n");
}

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int Particao(Vetor *v, int p, int r)
{
    int x = v->dados[p];
    int up = r;
    int down = p;

    while (down < up)
    {
        while (v->dados[down] <= x && down < r)
            down++;
        while (v->dados[up] > x)
            up--;
        if (down < up)
            troca(&v->dados[down], &v->dados[up]);
    }

    v->dados[p] = v->dados[up];
    v->dados[up] = x;
    return up;
}

void Quicksort(Vetor *v, int p, int r)
{
    if (p < r)
    {
        int q = Particao(v, p, r);
        Quicksort(v, p, q - 1);
        Quicksort(v, q + 1, r);
    }
}