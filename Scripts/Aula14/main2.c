// main.c
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int lerInteiro(const char *msg)
{
    int x;
    while (1)
    {
        printf("%s", msg);
        if (scanf("%d", &x) == 1)
        {
            limparBuffer();
            return x;
        }
        printf("Entrada inválida. Tente novamente.\n");
        limparBuffer();
    }
}

void pausar()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void menu()
{
    printf("\n===== LISTA ENCADEADA (no de cabeca) =====\n");
    printf("1) Inserir no inicio\n");
    printf("2) Inserir no fim\n");
    printf("3) Buscar elemento\n");
    printf("4) Atualizar elemento (valor -> novo_valor)\n");
    printf("5) Remover elemento (por valor)\n");
    printf("6) Remover do inicio\n");
    printf("7) Remover do fim\n");
    printf("8) Imprimir lista\n");
    printf("9) Verificar se vazia\n");
    printf("0) Sair\n");
}

int main()
{
    Lista L;
    inicializaLista(&L);

    int opc, valor, novo;

    do
    {
        menu();
        opc = lerInteiro("Escolha uma opcao: ");

        if (opc == 1)
        { // insereInicio
            valor = lerInteiro("Valor a inserir no inicio: ");
            insereInicio(&L, valor);
            printf("OK: %d inserido no inicio.\n", valor);
            pausar();
        }
        else if (opc == 2)
        { // insereFim
            valor = lerInteiro("Valor a inserir no fim: ");
            if (estaVazia(&L))
            {
                // evita segfault se seu insereFim não tratar lista vazia
                insereInicio(&L, valor);
            }
            else
            {
                insereFim(&L, valor);
            }
            printf("OK: %d inserido no fim.\n", valor);
            pausar();
        }
        else if (opc == 3)
        { // busca
            valor = lerInteiro("Valor a buscar: ");
            No *n = busca(&L, valor);
            if (n != NULL)
            {
                printf("Encontrado: %d (endereco %p)\n", n->dado, (void *)n);
            }
            else
            {
                printf("Valor %d nao encontrado.\n", valor);
            }
            pausar();
        }
        else if (opc == 4)
        { // atualizaElemento
            valor = lerInteiro("Valor atual: ");
            novo = lerInteiro("Novo valor: ");
            int ok = atualizaElemento(&L, valor, novo);
            if (ok)
                printf("OK: %d atualizado para %d.\n", valor, novo);
            else
                printf("Falhou: %d nao encontrado.\n", valor);
            pausar();
        }
        else if (opc == 5)
        { // removeElemento
            valor = lerInteiro("Valor a remover: ");
            int ok = removeElemento(&L, valor);
            if (ok)
                printf("OK: %d removido.\n", valor);
            else
                printf("Falhou: %d nao encontrado.\n", valor);
            pausar();
        }
        else if (opc == 6)
        { // removeInicio
            int ok = removeInicio(&L);
            if (ok)
                printf("OK: elemento do inicio removido.\n");
            else
                printf("Lista vazia.\n");
            pausar();
        }
        else if (opc == 7)
        { // removeFim
            if (estaVazia(&L))
            {
                printf("Lista vazia.\n");
            }
            else
            {
                int ok = removeFim(&L);
                // seu removeFim atual retorna 0 mesmo quando remove com sucesso no caso geral;
                // por isso, não confio no retorno: apenas informo e imprimo a lista.
                printf("Operacao de remover do fim executada.\n");
            }
            pausar();
        }
        else if (opc == 8)
        { // imprimeLista
            imprimeLista(&L);
            pausar();
        }
        else if (opc == 9)
        { // estaVazia
            printf("Lista %s vazia.\n", estaVazia(&L) ? "ESTA" : "NAO ESTA");
            pausar();
        }
        else if (opc == 0)
        {
            printf("Saindo...\n");
        }
        else
        {
            printf("Opcao invalida.\n");
            pausar();
        }

    } while (opc != 0);

    // Libera nós de dados e mantém cabeca->prox = NULL (como seu liberaLista faz)
    liberaLista(&L);
    return 0;
}
