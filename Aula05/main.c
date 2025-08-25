#include <stdio.h>
#include "lista.h"
#include "lista_sort.h"

int main(void) {
    Lista* l = cria_lista();
    insere_final(l, 30);
    insere_final(l, 10);
    insere_final(l, 50);
    insere_final(l, 20);
    insere_final(l, 40);

    printf("Antes de ordenar:\n");
    imprime_lista(l);

    bubble_sort(l);
    printf("Depois de ordenar (crescente):\n");
    imprime_lista(l);

    int x = 20;
    int posL = busca_linear(l, x);
    int posB = busca_binaria(l, x);

    printf("Busca linear por %d: pos=%d\n", x, posL);
    printf("Busca binaria por %d: pos=%d\n", x, posB);

    lista_libera(l);
    return 0;
}
