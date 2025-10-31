// main2.c
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

static void limpar_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    { /* descarta */
    }
}

static void mostrar_menu(void)
{
    printf("\n===== MENU - FilaLinear (vetor linear) =====\n");
    printf("1) Inicializar fila\n");
    printf("2) Enfileirar (push back)\n");
    printf("3) Desenfileirar (pop front)\n");
    printf("4) Frente (peek)\n");
    printf("5) Imprimir fila\n");
    printf("6) Tamanho\n");
    printf("7) Ordenar crescente (tudo)\n");
    printf("8) Ordenar decrescente (tudo)\n");
    printf("9) Ordenar PRIMEIROS N (crescente/decrescente)\n");
    printf("10) Limpar fila (liberar memoria)\n");
    printf("0) Sair\n");
    printf("Opcao: ");
}

int main(void)
{
    FilaLinear f;
    int inicializada = 0; /* 0 = nao, 1 = sim */
    int op;

    for (;;)
    {
        mostrar_menu();
        if (scanf("%d", &op) != 1)
        {
            printf("Entrada invalida. Encerrando.\n");
            break;
        }

        if (op == 0)
        {
            if (inicializada)
                filaLinear_limpar(&f);
            printf("Saindo...\n");
            return 0;
        }

        switch (op)
        {
        case 1:
        { /* Inicializar */
            int cap;
            printf("Capacidade: ");
            if (scanf("%d", &cap) != 1)
            {
                printf("Valor invalido.\n");
                limpar_buffer();
                break;
            }
            if (inicializada)
            {
                filaLinear_limpar(&f);
                inicializada = 0;
            }
            if (filaLienar_inicializar(&f, cap))
            {
                inicializada = 1;
                printf("[OK] Fila inicializada com capacidade %d.\n", cap);
            }
            else
            {
                printf("[ERRO] Falha ao inicializar.\n");
            }
        }
        break;

        case 2:
        { /* Enfileirar */
            if (!inicializada)
            {
                printf("Inicialize a fila (opcao 1).\n");
                break;
            }
            int v;
            printf("Valor: ");
            if (scanf("%d", &v) != 1)
            {
                printf("Valor invalido.\n");
                limpar_buffer();
                break;
            }
            if (filaLienar_enfileirar(&f, v))
            {
                printf("[OK] Enfileirado: %d\n", v);
            }
            else
            {
                printf("[ERRO] Fila cheia.\n");
            }
        }
        break;

        case 3:
        { /* Desenfileirar */
            if (!inicializada)
            {
                printf("Inicialize a fila (opcao 1).\n");
                break;
            }
            int x;
            if (filaLienar_desenfileirar(&f, &x))
            {
                printf("[OK] Desenfileirado: %d\n", x);
            }
            else
            {
                printf("[ERRO] Fila vazia.\n");
            }
        }
        break;

        case 4:
        { /* Frente */
            if (!inicializada)
            {
                printf("Inicialize a fila (opcao 1).\n");
                break;
            }
            int x;
            if (filaLienar_frente(&f, &x))
            {
                printf("Frente: %d\n", x);
            }
            else
            {
                printf("Fila vazia.\n");
            }
        }
        break;

        case 5:
        { /* Imprimir */
            if (!inicializada)
            {
                printf("Inicialize a fila (opcao 1).\n");
                break;
            }
            filaLinear_imprimir(&f);
        }
        break;

        case 6:
        { /* Tamanho */
            if (!inicializada)
            {
                printf("Inicialize a fila (opcao 1).\n");
                break;
            }
            printf("Tamanho: %d\n", filaLienar_tamanho(&f));
        }
        break;

        case 7:
        { /* Ordenar crescente (tudo) */
            if (!inicializada)
            {
                printf("Inicialize a fila (opcao 1).\n");
                break;
            }
            filaLinear_shellSort(&f, f.tamanho, 1);
            printf("[OK] Ordenada (crescente).\n");
            filaLinear_imprimir(&f);
        }
        break;

        case 8:
        { /* Ordenar decrescente (tudo) */
            if (!inicializada)
            {
                printf("Inicialize a fila (opcao 1).\n");
                break;
            }
            filaLinear_shellSort(&f, f.tamanho, 0);
            printf("[OK] Ordenada (decrescente).\n");
            filaLinear_imprimir(&f);
        }
        break;

        case 9:
        { /* Ordenar primeiros N */
            if (!inicializada)
            {
                printf("Inicialize a fila (opcao 1).\n");
                break;
            }
            int n, modo;
            printf("N (quantos primeiros ordenar): ");
            if (scanf("%d", &n) != 1)
            {
                printf("Valor invalido.\n");
                limpar_buffer();
                break;
            }
            printf("Crescente=1 / Decrescente=0: ");
            if (scanf("%d", &modo) != 1)
            {
                printf("Valor invalido.\n");
                limpar_buffer();
                break;
            }
            filaLinear_shellSort(&f, n, modo ? 1 : 0);
            printf("[OK] Ordenado os %d primeiros (%s).\n", n, modo ? "crescente" : "decrescente");
            filaLinear_imprimir(&f);
        }
        break;

        case 10:
        { /* Limpar */
            if (!inicializada)
            {
                printf("Fila ainda nao foi inicializada.\n");
                break;
            }
            filaLinear_limpar(&f);
            inicializada = 0;
            printf("[OK] Fila limpa (memoria liberada).\n");
        }
        break;

        default:
            printf("Opcao invalida.\n");
        }
    }
}
