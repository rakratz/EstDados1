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
    if (!lista) {
        fprintf(stderr, "Falha ao alocar memória.\n");
        return 1;
    }

    insere_final(lista, 10);
    insere_final(lista, 20);
    insere_final(lista, 30);
    insere_final(lista, 40);

    imprime_lista(lista);

    free(lista);
    return 0;
}
