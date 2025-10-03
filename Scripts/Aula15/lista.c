#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// O(1)
void inicializarLista(Lista *lista){
    lista->cabeca = (No *)malloc(sizeof(No));
    lista->calda = (No *)malloc(sizeof(No));
    if (!lista->cabeca || !lista->calda)
    {
        printf("Erro: sem memória para criar a lista\n");
        exit(1);
    }

    lista->cabeca->ant = NULL;
    lista->cabeca->prox = lista->calda;

    lista->calda->prox = NULL;
    lista->cabeca->ant = lista->cabeca;

    lista->tamanho = 0;
}

// O(1)
int estaVazia(Lista *lista){
    if (lista->cabeca->prox == lista->calda){
        return 1;
    } else {
        return 0;
    }
}

// O(1)
void insereInicio(Lista *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        printf("Erro: sem memória para inserir\n");
        return;
    }
    novo->dado = valor;
    // Insere entre cabeca e o primeiro nó de dados (ou a calda, se vazia)
    novo->ant = lista->cabeca;
    novo->prox = lista->cabeca->prox;

    lista->cabeca->prox->ant = novo;
    lista->cabeca->prox = novo;

    lista->tamanho++;
}



void imprimeLista(Lista *lista){
    if (estaVazia(lista))
    {
            printf("Lista está vazia!\n");
            return;
    }
    printf("NULL <-> ");
    for (No *aux = lista->cabeca->prox; aux != lista->calda; aux = aux->prox) {
        printf("%d <-> ", aux->dado);
    }
    printf("NULL \n");
}

// O(1)
void insereFim(Lista *lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        printf("Erro: sem memória para inserir!\n");
        return;
    }
    novo->dado = valor;

    // Insere imediatamente antes da calda
    novo->prox = lista->calda;
    novo->ant = lista->calda->ant;

    lista->calda->ant->prox = novo;
    lista->calda->ant = novo;

    lista->tamanho++;
}

// O(1)
int removeInicio(Lista *lista){
    if (estaVazia(lista))
    {
        printf("Lista está vazia!\n");
        return 0;
    }

    No *primeiro = lista->cabeca->prox;
    lista->cabeca->prox = primeiro->prox;
    primeiro->prox->ant = lista->cabeca;

    free(primeiro);
    lista->tamanho--;
    return 1;
}

// O(1)
int removeFim(Lista *lista)
{
    if (estaVazia(lista))
    {
        printf("Lista está vazia!\n");
        return 0;
    }
    No *ultimo = lista->calda->ant;
    lista->calda->ant = ultimo->ant;
    ultimo->ant->prox = lista->calda;

    free(ultimo);
    lista->tamanho--;
    return 1;
}

// O(n) e Ω(1)
int removeElemento(Lista *lista, int valor)
{
    if (estaVazia(lista))
    {
        printf("Lista está vazia!\n");
        return 0;
    }

    for (No *atual = lista->cabeca->prox; atual != lista->calda; atual = atual->prox)
    {
        if (atual->dado == valor)
        {
            // Desencadeia o nó atual
            atual->ant->prox = atual->prox;
            atual->prox->ant = atual->ant;
            free(atual);
            lista->tamanho--;
            return 1;
        }
    }
    return 0;
}

// O(n)
No *busca(Lista *lista, int valor)
{
    if (estaVazia(lista))
    {
        printf("Lista está vazia!\n");
        return 0;
    }

    for (No *aux = lista->cabeca->prox; aux != lista->calda; aux = aux->prox)
    {
        if (aux->dado == valor)
            return aux;
    }
    return NULL;
}

// O(n) e Ω(1)
int atualizaElemento(Lista *lista, int valor, int novo_valor)
{
    if (estaVazia(lista))
    {
        printf("Lista está vazia!\n");
        return 0;
    }

    for (No *aux = lista->cabeca->prox; aux != lista->calda; aux = aux->prox)
    {
        if (aux->dado == valor)
        {
            aux->dado = novo_valor;
            return 1;
        }
    }
    return 0;
}

// O(n) - útil para checar o encadeamento para trás
void imprimeListaReversa(Lista *lista)
{
    if (estaVazia(lista))
    {
        printf("Lista Vazia!\n");
        return;
    }
    printf("NULL <-> ");
    for (No *aux = lista->calda->ant; aux != lista->cabeca; aux = aux->ant)
    {
        printf("%d <-> ", aux->dado);
    }
    printf("NULL\n");
}

void liberaLista(Lista *lista)
{
    // Libera apenas nós de dados; mantém sentinelas para reuso
    No *aux = lista->cabeca->prox;
    while (aux != lista->calda)
    {
        No *tmp = aux;
        aux = aux->prox;
        free(tmp);
    }
    // Reconecta sentinelas
    lista->cabeca->prox = lista->calda;
    lista->calda->ant = lista->cabeca;
    lista->tamanho = 0;
}

void destroiLista(Lista *lista)
{
    // Limpa dados e também libera as sentinelas
    liberaLista(lista);
    free(lista->cabeca);
    free(lista->calda);
    lista->cabeca = NULL;
    lista->calda = NULL;
}