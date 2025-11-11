#include <stdio.h>
#include "merge_vetor.h"

int main(void)
{
    int valores[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(valores) / sizeof(valores[0]);

    Vetor *v = vetor_criar(n);
    if (v == NULL)
    {
        printf("Erro ao criar vetor.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        vetor_inserir(v, valores[i]);
    }

    printf("Vetor antes do Merge Sort:\n");
    vetor_imprimir(v);

    vetor_merge_sort(v);

    printf("Vetor depois do Merge Sort:\n");
    vetor_imprimir(v);

    vetor_destruir(v);

    return 0;
}
