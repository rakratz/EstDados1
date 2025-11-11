#ifndef MERGE_VETOR_H
#define MERGE_VETOR_H

typedef struct
{
    int *dados;
    int tamanho;
    int capacidade;
} Vetor;

Vetor *vetor_criar(int capacidade);

void vetor_destruir(Vetor *v);

int vetor_inserir(Vetor *v, int valor);

void vetor_imprimir(const Vetor *v);

/* Ordenação Merge Sort*/
void vetor_merge_sort(Vetor *v);

#endif