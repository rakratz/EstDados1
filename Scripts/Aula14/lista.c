#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// O(1)
void inicializaLista(Lista *lista)
{
    lista->cabeca = (No *)malloc(sizeof(No));
    if (lista->cabeca == NULL)
    {
        printf("Erro: sem memória para criar a lista!\n");
        exit(1);
    }
    // cabeca aponta para NULL que lista vazia
    lista->cabeca->prox = NULL;
    //lista->calda->prox = NULL;
}

// O(1)
int estaVazia(Lista *lista)
{
    if (lista->cabeca->prox == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// O(1)
void insereInicio(Lista *lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Erro: sem memória para inserir!\n");
        return;
    }
    novo->dado = valor;
    /* Se a lista estive vazia cabeca-> proximo é NULL, se não
    apontará para o primeiro Nó.
    Em ambos os caso, a lógica é a mesma*/
    novo->prox = lista->cabeca->prox;
    lista->cabeca->prox = novo;
}

// O(n) e Ω(1)
void insereFim(Lista *lista, int valor){
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Erro: sem memória para inserir!\n");
        return;
    } else {
        novo->dado = valor;
        novo->prox = NULL;
        No *aux = lista->cabeca->prox;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}
// O(n) e Ω(1)
No *busca(Lista *lista, int valor)
{
    if (estaVazia(lista))
    {
        return NULL;
    }
    else
    {
        No *aux = lista->cabeca->prox;
        while (aux != NULL)
        {
            if (aux->dado == valor)
            {
                return aux; // Encontrou
            }
            else
            {
                aux = aux->prox;
            }
        }
        return NULL;
    }
}

// O(n) e Ω(1)
int removeElemento(Lista *lista, int valor)
{
    if (estaVazia(lista))
    {
        return 0;
    }
    else
    {
        No *ant = lista->cabeca;
        No *atual = lista->cabeca->prox;
        while (atual != NULL)
        {
            if (atual->dado == valor)
            {
                // desencadeia o nó atual
                ant->prox = atual->prox;
                free(atual);
                return 1;
            }
            else
            {
                ant = atual;
                atual = atual->prox;
            }
        }
        return 0;
    }
}

// O(1)
int removeInicio(Lista *lista)
{
    if (estaVazia(lista))
    {
        return 0;
    }
    else
    {
        No *primeiro = lista->cabeca->prox;   // nó a ser removido
        lista->cabeca->prox = primeiro->prox; // cabeça aponta para o segundo elemento
        free(primeiro);
        return 1;
    }
}

// O(n) e Ω(1)
int removeFim(Lista *lista)
{
    No *ant = lista->cabeca;
    No *atual = lista->cabeca->prox;
    // Caso especial: Só temos 1 elemento na fila
    if (atual->prox == NULL)
    {
        ant->prox = NULL;
        free(atual);
        return 1;
    }
    else
    {
        while (atual->prox != NULL)
        {
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = NULL;
        free(atual);
        return 0;
    }
}
// O(n) e Ω(1
int atualizaElemento(Lista *lista, int valor, int novo_valor)
{
    if (estaVazia(lista))
    {
        return 0;
    }
    else
    {
        No *aux = lista->cabeca->prox;

        while (aux != NULL)
        {
            if (aux->dado == valor)
            {
                aux->dado = novo_valor;
                return 1;
            }
            else
            {
                aux = aux->prox;
            }
        }
        // Não achamos o valor procurar
        return 0;
    }
}

// O(n) e Ω(1)
void imprimeLista(Lista *lista)
{
    if (estaVazia(lista))
    {
        printf("Lista Vazia!\n");
    }
    else
    {
        No *aux = lista->cabeca->prox;
        while (aux != NULL)
        {
            printf("%d -> ", aux->dado);
            aux = aux->prox;
        }
        printf("NULL\n");
    }
}

void liberaLista(Lista *lista)
{
    if (estaVazia(lista))
    {
        /* fazer nada*/
    }
    else
    {
        No *aux = lista->cabeca->prox;

        while (aux != NULL)
        {
            No *tmp = aux;
            aux = aux->prox;
            free(tmp);
        }
        // Vamos colocar Null na cabeça da Lista
        lista->cabeca->prox = NULL;
        // lista->calda->prox = NULL;
    }
}