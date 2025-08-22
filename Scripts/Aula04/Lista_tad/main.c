// Arquivo: main.c
#include <stdio.h>
#include "lista.h"

int main(void) {
    Lista* l = cria_lista();
    if (!l) {
        printf("Falha ao criar lista.\n");
        return 1;
    }

    insere_final(l, 10);
    insere_final(l, 20);
    insere_final(l, 10); // repetido
    insere_final(l, 30);

    imprime_lista(l);  // Lista: 10 20 10 30

    int pos = busca_elem(l, 10);
    if (pos != -1) printf("Elemento 10 encontrado na posicao %d\n", pos);

    remove_elem(l, 10); // remove a 1ª ocorrência (ordem preservada)
    imprime_lista(l);   // Lista: 20 10 30

    printf("Tamanho: %d\n", lista_tamanho(l));

    lista_libera(l);
    return 0;
}
