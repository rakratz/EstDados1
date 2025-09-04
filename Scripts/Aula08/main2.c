// main2.c
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int lerInteiro(const char *msg) {
    int x;
    while (1) {
        printf("%s", msg);
        if (scanf("%d", &x) == 1) {
            limparBuffer();
            return x;
        }
        printf("Entrada inválida. Tente novamente.\n");
        limparBuffer();
    }
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    limparBuffer(); // garante que buffer esteja limpo
    getchar();
}

int tamanho(Pilha *p) {
    return p->topo + 1;
}

void listar(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha está vazia.\n");
        return;
    }
    printf("Conteúdo da pilha (topo -> base):\n");
    for (int i = p->topo; i >= 0; --i) {
        printf("[%d] = %d\n", i, p->dados[i]);
    }
}

void esvaziar(Pilha *p) {
    while (!isEmpty(p)) pop(p);
}

void menu() {
    printf("\n===== PILHA (CRUD) =====\n");
    printf("1) Empilhar (push)\n");
    printf("2) Desempilhar (pop)\n");
    printf("3) Consultar topo (peek)\n");
    printf("4) Listar elementos\n");
    printf("5) Tamanho da pilha\n");
    printf("6) Verificar se vazia\n");
    printf("7) Verificar se cheia\n");
    printf("8) Esvaziar pilha\n");
    printf("0) Sair\n");
}

int main() {
    Pilha p;
    inicializa(&p);

    int opc, valor;
    do {
        menu();
        printf("Capacidade (MAX) = %d | Tamanho atual = %d\n", MAX, tamanho(&p));
        opc = lerInteiro("Escolha uma opção: ");

        switch (opc) {
            case 1: // push
                if (isFull(&p)) {
                    printf("Não é possível empilhar: pilha cheia.\n");
                } else {
                    valor = lerInteiro("Valor a empilhar: ");
                    push(&p, valor);
                    printf("OK: %d empilhado.\n", valor);
                }
                pausar();
                break;

            case 2: // pop
                if (isEmpty(&p)) {
                    printf("Não é possível desempilhar: pilha vazia.\n");
                } else {
                    int removido = pop(&p);
                    printf("OK: desempilhado %d.\n", removido);
                }
                pausar();
                break;

            case 3: // peek
                if (isEmpty(&p)) {
                    printf("Pilha vazia.\n");
                } else {
                    printf("Topo = %d\n", peek(&p));
                }
                pausar();
                break;

            case 4: // listar
                listar(&p);
                pausar();
                break;

            case 5: // tamanho
                printf("Tamanho atual = %d\n", tamanho(&p));
                pausar();
                break;

            case 6: // isEmpty
                printf("Pilha %s vazia.\n", isEmpty(&p) ? "está" : "não está");
                pausar();
                break;

            case 7: // isFull
                printf("Pilha %s cheia.\n", isFull(&p) ? "está" : "não está");
                pausar();
                break;

            case 8: // clear
                esvaziar(&p);
                printf("Pilha esvaziada.\n");
                pausar();
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
                pausar();
                break;
        }
    } while (opc != 0);

    return 0;
}
