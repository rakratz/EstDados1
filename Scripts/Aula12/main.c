#include <stdio.h>
#include "vetor.h"

int main()
{
    Vetor v;
    inicializaVetor(&v);

    // Inserindo elementos no vetor linear
    insereElemento(&v, 10);
    insereElemento(&v, 7);
    insereElemento(&v, 8);
    insereElemento(&v, 9);
    insereElemento(&v, 1);
    insereElemento(&v, 5);
    insereElemento(&v, 12);
    insereElemento(&v, 3);

    printf("Vetor original:\n");
    imprimeVetor(&v);

    Quicksort(&v, 0, v.tamanho - 1);

    printf("Vetor ordenado:\n");
    imprimeVetor(&v);

    return 0;
}
