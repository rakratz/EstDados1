#include <stdio.h>
#include "lista.h"
#include "lista_sort.h"

int main(void) {
    Lista* l = cria_lista();
    insere_ordenado(l, 30);
    insere_ordenado(l, 10);
    insere_ordenado(l, 50);
    insere_ordenado(l, 20);
    insere_ordenado(l, 40);

    imprime_lista(l);

    int x = 20;
    int posL = busca_linear(l, x);
    int posB = busca_binaria(l, x);

    printf("Busca linear por %d: pos=%d\n", x, posL);
    printf("Busca binaria por %d: pos=%d\n", x, posB);

    lista_libera(l);
    return 0;
}
