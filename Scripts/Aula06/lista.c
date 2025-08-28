#include "lista.h"

// Cria e inicializa a lista
Lista* cria_lista(void) {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (lista != NULL) lista->qtd = 0; // começa vazia
    return lista;
}

// Libera a memória
void lista_libera(Lista* lista) {
    free(lista);
}

// Insere no final da lista (se houver espaço)
int insere_final(Lista* lista, int elem) {
    if (lista == NULL || lista->qtd == MAX) return 0;
    lista->dados[lista->qtd++] = elem;
    return 1;
}

// Remove a primeira ocorrência do elemento
// Desloca os demais para manter a ordem
int remove_elem(Lista* lista, int elem) {
    if (lista == NULL || lista->qtd == 0) return 0;
    int i = 0;
    while (i < lista->qtd && lista->dados[i] != elem) i++;
    if (i == lista->qtd) return 0; // não encontrado
    for (int j = i; j < lista->qtd - 1; j++) {
        lista->dados[j] = lista->dados[j + 1];
    }
    lista->qtd--;
    return 1;
}

// Busca linear: percorre até encontrar
int busca_elem(const Lista* lista, int elem) {
    if (lista == NULL) return -1;
    for (int i = 0; i < lista->qtd; i++) {
        if (lista->dados[i] == elem) return i;
    }
    return -1;
}

// Mostra os elementos da lista
void imprime_lista(const Lista* lista) {
    if (lista == NULL) { printf("(lista nula)\n"); return; }
    printf("Lista: ");
    for (int i = 0; i < lista->qtd; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}

// Retorna a quantidade atual
int lista_tamanho(const Lista* lista) {
    return (lista ? lista->qtd : 0);
}


// Insere em ordem crescente
int insere_ordenado(Lista* lista, int elem) {
    if (lista == NULL || lista->qtd == MAX) return 0;
    int i = lista->qtd - 1;

    // desloca todos que são maiores que elem
    while (i >= 0 && lista->dados[i] > elem) {
        lista->dados[i + 1] = lista->dados[i];
        i--;
    }
    lista->dados[i + 1] = elem;
    lista->qtd++;
    return 1;
}

















