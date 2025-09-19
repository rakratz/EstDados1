#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void menu() {
    printf("\n===== LISTA ENCADEADA COM CABEÇA =====\n");
    printf("1) Inserir no início\n");
    printf("2) Inserir no fim\n");
    printf("3) Buscar elemento\n");
    printf("4) Remover elemento\n");
    printf("5) Imprimir lista\n");
    printf("0) Sair\n");
}

int main() {
    Lista l;
    inicializaLista(&l);

    int opc, valor;
    do {
        menu();
        printf("Escolha: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                insereInicio(&l, valor);
                break;
            case 2:
                printf("Valor: ");
                scanf("%d", &valor);
                insereFim(&l, valor);
                break;
            case 3: {
                printf("Valor: ");
                scanf("%d", &valor);
                No *n = busca(&l, valor);
                if (n) printf("Encontrado: %d\n", n->dado);
                else   printf("Não encontrado.\n");
                break;
            }
            case 4:
                printf("Valor: ");
                scanf("%d", &valor);
                if (removeElemento(&l, valor))
                    printf("Removido com sucesso.\n");
                else
                    printf("Elemento não encontrado.\n");
                break;
            case 5:
                imprimeLista(&l);
                break;
            case 0:
                liberaLista(&l);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opc != 0);

    return 0;
}
