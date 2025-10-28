// main2.c
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

static void limpar_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    { /* descarta */
    }
}

static void mostrar_menu(void)
{
    printf("\n===== TESTE DE PILHA (lista encadeada simples) =====\n");
    printf("1) Empilhar (push)\n");
    printf("2) Desempilhar (pop)\n");
    printf("3) Ver topo (peek)\n");
    printf("4) Imprimir pilha\n");
    printf("5) Verificar se esta vazia\n");
    printf("6) Tamanho atual\n");
    printf("7) Limpar pilha\n");
    printf("0) Sair\n");
    printf("Opcao: ");
}

int main(void)
{
    Pilha p;
    pilha_inicializar(&p);

    int opcao;
    int valor;
    int ok;

    for (;;)
    {
        mostrar_menu();
        if (scanf("%d", &opcao) != 1)
        {
            printf("Entrada invalida. Tente novamente.\n");
            limpar_buffer();
            continue;
        }

        switch (opcao)
        {
        case 1: // push
            printf("Valor para empilhar: ");
            if (scanf("%d", &valor) != 1)
            {
                printf("Valor invalido.\n");
                limpar_buffer();
                break;
            }
            ok = pilha_empilhar(&p, valor);
            if (ok)
            {
                printf("[OK] Empilhado: %d\n", valor);
            }
            else
            {
                printf("[ERRO] Falha ao empilhar (sem memoria).\n");
            }
            break;

        case 2: // pop
            ok = pilha_desempilhar(&p, &valor);
            if (ok)
            {
                printf("[OK] Desempilhado: %d\n", valor);
            }
            else
            {
                printf("[ERRO] Pilha vazia.\n");
            }
            break;

        case 3: // topo
            ok = pilha_topo(&p, &valor);
            if (ok)
            {
                printf("Topo: %d\n", valor);
            }
            else
            {
                printf("Pilha vazia.\n");
            }
            break;

        case 4: // imprimir
            pilha_imprimir(&p);
            break;

        case 5: // vazia?
            if (pilha_vazia(&p))
            {
                printf("SIM, pilha vazia.\n");
            }
            else
            {
                printf("NAO, pilha possui elementos.\n");
            }
            break;

        case 6: // tamanho
            printf("Tamanho atual: %d\n", p.tamanho);
            break;

        case 7: // limpar
            pilha_limpar(&p);
            printf("Pilha esvaziada.\n");
            break;

        case 0:
            printf("Saindo...\n");
            pilha_limpar(&p);
            return 0;

        default:
            printf("Opcao invalida.\n");
        }
    }
}
