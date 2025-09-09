#include "lista.h"

int main(void)
{
    Lista *l = lista_cria();
    int v[] = {30, 10, 50, 20, 40, 5, 60};

    for (int i = 0; i < 7; i++)
    {
        lista_insere_final(l, v[i]);
    }

    printf("Original:\n");
    lista_imprime(l);

    // Teste Insertion Sort
    insertion_sort(l);
    printf("Ordenada com Insertion Sort:\n");
    lista_imprime(l);

    // Recarrega para testar Selection Sort
    l->qtd = 0;
    for (int i = 0; i < 7; i++)
    {
        lista_insere_final(l, v[i]);
    }

    selection_sort(l);
    printf("Ordenada com Selection Sort:\n");
    lista_imprime(l);

    lista_libera(l);
    return 0;
}
