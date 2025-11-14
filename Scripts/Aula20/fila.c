#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila *criarFila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f != NULL)
    {
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }
    return f;
}

void limparFila(Fila *f)
{
    if (f == NULL)
        return;

    No *atual = f->inicio;
    while (atual != NULL)
    {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

void destruirFila(Fila *f)
{
    if (f == NULL)
        return;
    limparFila(f);
    free(f);
}

int filaVazia(Fila *f)
{
    return (f == NULL || f->inicio == NULL);
}

int enfileirar(Fila *f, Pessoa p)
{
    if (f == NULL)
        return 0;

    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return 0;

    novo->dado = p;
    novo->prox = NULL;
    novo->ant = f->fim;

    if (filaVazia(f))
    {
        f->inicio = novo;
    }
    else
    {
        f->fim->prox = novo;
    }

    f->fim = novo;
    f->tamanho++;
    return 1;
}

int desenfileirar(Fila *f, Pessoa *pOut)
{
    if (f == NULL || filaVazia(f))
        return 0;

    No *rem = f->inicio;
    if (pOut != NULL)
    {
        *pOut = rem->dado;
    }

    f->inicio = rem->prox;
    if (f->inicio != NULL)
    {
        f->inicio->ant = NULL;
    }
    else
    {
        f->fim = NULL;
    }

    free(rem);
    f->tamanho--;
    return 1;
}

void imprimirFila(Fila *f)
{
    if (filaVazia(f))
    {
        printf("Fila vazia.\n");
        return;
    }

    No *atual = f->inicio;
    printf("Tamanho da fila: %d\n", f->tamanho);
    while (atual != NULL)
    {
        printf("Nome: %-20s | Idade: %d\n",
               atual->dado.nome, atual->dado.idade);
        atual = atual->prox;
    }
}

void ordenarPorIdade(Fila *f, int crescente)
{
    if (f == NULL || f->tamanho < 2)
        return;

    int trocou;
    do
    {
        trocou = 0;
        No *atual = f->inicio;

        while (atual != NULL && atual->prox != NULL)
        {
            int cond;
            if (crescente)
            {
                cond = (atual->dado.idade > atual->prox->dado.idade);
            }
            else
            {
                cond = (atual->dado.idade < atual->prox->dado.idade);
            }

            if (cond)
            {
                Pessoa tmp = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = tmp;
                trocou = 1;
            }
            atual = atual->prox;
        }
    } while (trocou);
}

No *buscarPorNome(Fila *f, const char *nome)
{
    if (f == NULL || nome == NULL)
        return NULL;

    No *atual = f->inicio;
    while (atual != NULL)
    {
        if (strcmp(atual->dado.nome, nome) == 0)
        {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

int removerPorNome(Fila *f, const char *nome)
{
    if (f == NULL || filaVazia(f) || nome == NULL)
        return 0;

    No *no = buscarPorNome(f, nome);
    if (no == NULL)
        return 0;

    if (no->ant != NULL)
    {
        no->ant->prox = no->prox;
    }
    else
    {
        f->inicio = no->prox;
    }

    if (no->prox != NULL)
    {
        no->prox->ant = no->ant;
    }
    else
    {
        f->fim = no->ant;
    }

    free(no);
    f->tamanho--;
    return 1;
}

int atualizarPessoa(Fila *f, const char *nomeAntigo, Pessoa novaPessoa)
{
    if (f == NULL || nomeAntigo == NULL)
        return 0;

    No *no = buscarPorNome(f, nomeAntigo);
    if (no == NULL)
        return 0;

    no->dado = novaPessoa;
    return 1;
}
