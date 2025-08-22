// Arquivo: lista.c
#include "lista.h"

// Implementação interna
struct lista {
    int dados[MAX];
    int qtd;
};

Lista* cria_lista(void) {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    if (l != NULL) l->qtd = 0;
    return l;
}

void lista_libera(Lista* l) {
    free(l);
}

int insere_final(Lista* l, int elem) {
    if (l == NULL || l->qtd == MAX) return 0;
    l->dados[l->qtd++] = elem;
    return 1;
}

// remove a PRIMEIRA ocorrência de elem, deslocando à esquerda (ordem estável)
int remove_elem(Lista* l, int elem) {
    if (l == NULL || l->qtd == 0) return 0;

    int i = 0;
    while (i < l->qtd && l->dados[i] != elem) i++;
    if (i == l->qtd) return 0; // não encontrou

    for (int j = i; j < l->qtd - 1; j++) {
        l->dados[j] = l->dados[j + 1];
    }
    l->qtd--;
    return 1;
}

int busca_elem(const Lista* l, int elem) {
    if (l == NULL) return -1;
    for (int i = 0; i < l->qtd; i++) {
        if (l->dados[i] == elem) return i;
    }
    return -1;
}

void imprime_lista(const Lista* l) {
    if (l == NULL) return;
    printf("Lista: ");
    for (int i = 0; i < l->qtd; i++) {
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}

int lista_tamanho(const Lista* l) {
    return (l ? l->qtd : 0);
}
