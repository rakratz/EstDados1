#include "lista_sort.h"

// Bubble Sort: compara pares e troca quando necessário.
// A cada passada, o maior elemento "borbulha" para o fim.
void bubble_sort(Lista* lista) {
    if (!lista || lista->qtd < 2) return;
    int trocou;
    for (int i = 0; i < lista->qtd - 1; i++) {
        trocou = 0;
        for (int j = 0; j < lista->qtd - 1 - i; j++) {
            if (lista->dados[j] > lista->dados[j + 1]) {
                int tmp = lista->dados[j];
                lista->dados[j] = lista->dados[j + 1];
                lista->dados[j + 1] = tmp;
                trocou = 1;
            }
        }
        if (!trocou) break; // se não houve trocas, já está ordenado
    }
}

// Busca linear: percorre do início ao fim
int busca_linear(const Lista* lista, int x) {
    if (!lista) return -1;
    for (int i = 0; i < lista->qtd; i++) {
        if (lista->dados[i] == x) return i;
    }
    return -1;
}

// Busca binária: divide ao meio a cada passo
int busca_binaria(const Lista* lista, int x) {
    if (!lista) return -1;
    int ini = 0, fim = lista->qtd - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (lista->dados[meio] == x) return meio;
        if (x < lista->dados[meio]) fim = meio - 1;
        else ini = meio + 1;
    }
    return -1;
}
