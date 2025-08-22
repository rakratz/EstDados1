#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // tamanho máximo da lista

typedef struct {
    int dados[MAX];  // vetor que armazena os elementos
    int qtd;         // quantidade atual de elementos
} Lista;

Lista* cria_lista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (lista != NULL) lista->qtd = 0;
    return lista;
}

int insere_final(Lista* lista, int elem) {
    if (lista == NULL || lista->qtd == MAX) return 0; // erro
    lista->dados[lista->qtd] = elem;
    lista->qtd++;
    return 1; // sucesso
}

int busca_elem(const Lista* lista, int elem){
    if (lista == NULL) return -1;
    for (int i =0; i < lista->qtd; i++){
        if (lista->dados[i] == elem) return i;
    }
}

int remove_elem(Lista* lista, int elem) {
    if (lista == NULL || lista->qtd == 0) return 0;  // lista vazia ou nula

    int i = 0;
    while (i < lista->qtd && lista->dados[i] != elem) i++;  // busca linear

    if (i == lista->qtd) return 0;  // não encontrou

    // desloca à esquerda do índice encontrado até o penúltimo
    for (int j = i; j < lista->qtd - 1; j++) {
        lista->dados[j] = lista->dados[j + 1];
    }

    lista->qtd--;   // diminui o tamanho lógico
    return 1;   // sucesso
}


void imprime_lista(const Lista* lista) {
    if (lista == NULL) return;
    printf("Lista: ");
    for (int i = 0; i < lista->qtd; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}

int main() {
    Lista* lista = cria_lista();

    insere_final(lista, 10);
    insere_final(lista, 20);
    insere_final(lista, 10); // valor repetido
    insere_final(lista, 30);
    imprime_lista(lista); // Lista: 10 20 10 30

    int pos = busca_elem(lista, 10);
    if (pos != -1) printf("Elemento 10 encontrado na posicao %d\n", pos);

    remove_elem(lista, 10); // remove a primeira ocorrência
    imprime_lista(lista);   // Lista: 20 10 30

    free(lista);
    return 0;
}
