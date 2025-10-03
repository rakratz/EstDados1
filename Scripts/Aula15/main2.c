#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

static int ler_opcao(void)
{
    int op;
    printf("\n==== MENU LISTA DUPLAMENTE ENCADEADA ====\n");
    printf(" 1) Inserir no inicio\n");
    printf(" 2) Inserir no fim\n");
    printf(" 3) Remover do inicio\n");
    printf(" 4) Remover do fim\n");
    printf(" 5) Remover elemento (por valor)\n");
    printf(" 6) Buscar elemento (por valor)\n");
    printf(" 7) Atualizar elemento (valor -> novo valor)\n");
    printf(" 8) Imprimir lista (frente)\n");
    printf(" 9) Imprimir lista (reversa)\n");
    printf("10) Mostrar tamanho\n");
    printf("11) Esvaziar lista (libera nos, mantem sentinelas)\n");
    printf("12) Destruir lista (libera tudo)\n");
    printf("13) Recriar lista (apos destruir)\n");
    printf(" 0) Sair\n");
    printf("Escolha: ");
    if (scanf("%d", &op) != 1)
    {
        // limpa stdin em caso de lixo
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
        return -1;
    }
    return op;
}

int main(void)
{
    Lista lista;
    int lista_ativa = 1;

    inicializarLista(&lista);

    for (;;)
    {
        int op = ler_opcao();
        if (op == -1)
        {
            puts("Entrada invalida.");
            continue;
        }

        // Bloqueia operacoes quando a lista foi destruida
        if (!lista_ativa && !(op == 13 || op == 0))
        {
            puts("A lista foi destruida. Use a opcao 13 para recriar ou 0 para sair.");
            continue;
        }

        if (op == 0)
        {
            if (lista_ativa)
                destroiLista(&lista);
            puts("Saindo...");
            break;
        }

        int valor, novo;
        switch (op)
        {
        case 1:
            printf("Valor para inserir no inicio: ");
            if (scanf("%d", &valor) != 1)
            {
                puts("Entrada invalida.");
                break;
            }
            insereInicio(&lista, valor);
            puts("Inserido no inicio.");
            break;

        case 2:
            printf("Valor para inserir no fim: ");
            if (scanf("%d", &valor) != 1)
            {
                puts("Entrada invalida.");
                break;
            }
            insereFim(&lista, valor);
            puts("Inserido no fim.");
            break;

        case 3:
            if (removeInicio(&lista))
                puts("Removido do inicio.");
            break;

        case 4:
            if (removeFim(&lista))
                puts("Removido do fim.");
            break;

        case 5:
            printf("Valor a remover: ");
            if (scanf("%d", &valor) != 1)
            {
                puts("Entrada invalida.");
                break;
            }
            if (removeElemento(&lista, valor))
                puts("Elemento removido.");
            else
                puts("Valor nao encontrado.");
            break;

        case 6:
        {
            printf("Valor a buscar: ");
            if (scanf("%d", &valor) != 1)
            {
                puts("Entrada invalida.");
                break;
            }

            No *n = busca(&lista, valor);
            if (n)
            {
                printf("Valor encontrado!\n");
                printf("  endereco do no      = %p\n", (void *)n);
                printf("  valor (dado)        = %d\n", n->dado);
                printf("  endereco do ant     = %p\n", (void *)n->ant);
                printf("  endereco do prox    = %p\n", (void *)n->prox);
                // Se quiser também o endereço do campo 'dado':
                // printf("  endereco de n->dado = %p\n", (void*)&n->dado);
            }
            else
            {
                puts("Valor nao encontrado.");
            }
            break;
        }

        case 7:
            printf("Valor atual: ");
            if (scanf("%d", &valor) != 1)
            {
                puts("Entrada invalida.");
                break;
            }
            printf("Novo valor: ");
            if (scanf("%d", &novo) != 1)
            {
                puts("Entrada invalida.");
                break;
            }
            if (atualizaElemento(&lista, valor, novo))
                puts("Elemento atualizado.");
            else
                puts("Valor nao encontrado para atualizar.");
            break;

        case 8:
            imprimeLista(&lista);
            break;

        case 9:
            imprimeListaReversa(&lista);
            break;

        case 10:
            printf("Tamanho da lista: %d\n", lista.tamanho);
            break;

        case 11:
            liberaLista(&lista);
            puts("Lista esvaziada (sentinelas preservadas).");
            break;

        case 12:
            destroiLista(&lista);
            lista_ativa = 0;
            puts("Lista destruida. Use a opcao 13 para recriar.");
            break;

        case 13:
            if (lista_ativa)
            {
                puts("A lista ja esta ativa.");
            }
            else
            {
                inicializarLista(&lista);
                lista_ativa = 1;
                puts("Lista recriada com sucesso.");
            }
            break;

        default:
            puts("Opcao invalida.");
            break;
        }
    }

    return 0;
}
