#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha p;
    inicializa(&p);

    // Testando a pilha
    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    printf("Topo: %d\n", peek(&p));

    printf("Desempilhado: %d\n", pop(&p));
    printf("Desempilhado: %d\n", pop(&p));

    printf("Topo atual: %d\n", peek(&p));

    return 0;
}
