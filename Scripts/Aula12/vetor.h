#ifndef VETOR_H
#define VETOR_H

#define MAX 100 // tamanho máximo do vetor linear

typedef struct
{
    int dados[MAX];
    int tamanho;
} Vetor;

// Operações básicas
void inicializaVetor(Vetor *v);
void insereElemento(Vetor *v, int valor);
void imprimeVetor(Vetor *v);

// Funções de ordenação (Quicksort)
void troca(int *a, int *b);
int Particao(Vetor *v, int p, int r);
void Quicksort(Vetor *v, int p, int r);

#endif
