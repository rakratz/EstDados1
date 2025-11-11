#include <stdio.h>
#include <stdlib.h>
#include "merge_vetor.h"

/* ===== Implementação do TAD Vetor ===== */

Vetor *vetor_criar(int capacidade)
{
    Vetor *v = (Vetor *)malloc(sizeof(Vetor));
    if (v == NULL)
    {
        return NULL;
    }

    v->dados = (int *)malloc(capacidade * sizeof(int));
    if (v->dados == NULL)
    {
        free(v);
        return NULL;
    }

    v->tamanho = 0;
    v->capacidade = capacidade;
    return v;
}

void vetor_destruir(Vetor *v)
{
    if (v != NULL)
    {
        free(v->dados);
        free(v);
    }
}

int vetor_inserir(Vetor *v, int valor)
{
    if (v == NULL)
        return 0;
    if (v->tamanho == v->capacidade)
    {
        return 0; /* Vetor cheio */
    }
    v->dados[v->tamanho] = valor;
    printf("Inserindo %d \n", valor);
    v->tamanho++;
    return 1;
}

void vetor_imprimir(const Vetor *v)
{
    if (v == NULL)
        return;
    for (int i = 0; i < v->tamanho; i++)
    {
        printf("%d ", v->dados[i]);
    }
    printf("\n");
}

static void merge(int v[], int aux[], int inicio, int meio, int fim){
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    /* itercala as duas metade em aux[]*/
    while (i <= meio && j <= fim) 
    {
        if (v[i] <= v[j]) {
            aux[k++] = v[i++];
        } else {
            aux[k++] = v[j++];
        }
    }

    /* Copia o resto da metade esquera, se houver*/
    while (i <= meio) 
    {
        aux[k++] = v[i++];
    }

    /* Copia o resto da metade direita, se houver*/
    while (j <= fim)
    {
        aux[k++] = v[j++];
    }

    /* Copiar de volda para o vetor original */
    for (i = inicio; i <= fim; i++) {
        v[i] = aux[i];
    }
}

static void merge_sort_rec(int v[], int aux[], int inicio, int fim){
    /* Condição de parada da recursividade*/
    if (inicio >= fim) {
        return;
    }

    int meio = (inicio + fim) / 2;
    merge_sort_rec(v, aux, inicio, meio);
    merge_sort_rec(v, aux, meio + 1, fim);
    merge(v, aux, inicio, meio, fim);
}

/* Ordenação Merge Sort*/
void vetor_merge_sort(Vetor *v){
    if (v == NULL || v->tamanho <= 1) {
        printf("Erro: Vetor não incializado");
        return;
    }

    int *aux = (int *)malloc(v->tamanho * sizeof(int));

    merge_sort_rec(v->dados, aux, 0, v->tamanho - 1);

    free(aux);
}