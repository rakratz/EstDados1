#include "fila_circular_dupla.h"
#include <stdlib.h>
#include <stdio.h>

/* Inicializa a fila */
void fila_circular_inicializar(FilaCircularDupla *f)
{
    if (f != NULL)
    {
        f->frente = NULL;
        f->tamanho = 0;
    }
    else
    {
        printf("Erro ao inicializar a fila.\n");
    }
}

/* Retorna 1 se vazia e 0 caso contrário */
int fila_circular_vazia(const FilaCircularDupla *f)
{
    if (f == NULL)
    {
        return 1;
    }
    else
    {
        if (f->frente == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

/* Retorna o tamanho da fila */
size_t fila_circular_tamanho(const FilaCircularDupla *f)
{
    if (f == NULL)
    {
        return 0;
    }
    else
    {
        return f->tamanho;
    }
}

/* Enfileira no final da fila (retorna 1 se ok; 0 se erro de memória) */
int fila_circular_enfileirar(FilaCircularDupla *f, int valor)
{
    FCDNodo *novo;

    if (f == NULL)
    {
        return 0;
    }

    novo = (FCDNodo *)malloc(sizeof(FCDNodo));
    if (novo == NULL)
    { /* <= correção */
        return 0;
    }

    novo->valor = valor;

    /* fila vazia, o nó aponta para si mesmo (circular)*/
    if (f->frente == NULL)
    {
        novo->prox = novo;
        novo->ant = novo;
        f->frente = novo;
    }
    else
    {
        /* Inserir no Final da Fila */
        FCDNodo *frente = f->frente;
        FCDNodo *cauda = frente->ant;

        novo->prox = frente;
        novo->ant = cauda;

        frente->ant = novo;
        cauda->prox = novo;
    }
    f->tamanho = f->tamanho + 1;
    return 1;
}

/* Lê o elemento da frente sem remover (retorna 1 se ok; 0 se vazia) */
int fila_circular_frente(const FilaCircularDupla *f, int *out)
{
    if (f == NULL)
    {
        return 0;
    }
    else
    {
        if (f->frente == NULL)
        {
            return 0;
        }
        else
        {
            if (out != NULL)
            { /* segurança opcional */
                *out = f->frente->valor;
            }
            return 1;
        }
    }
}

/* Desenfileira no início da fila (retorna 1 se ok; 0 se vazia) */
int fila_circular_desenfileirar(FilaCircularDupla *f, int *out)
{
    FCDNodo *alvo;

    if (f == NULL)
    {
        return 0;
    }
    else
    {
        if (f->frente == NULL)
        {
            return 0;
        }
    }

    alvo = f->frente;
    if (out != NULL)
    { /* segurança opcional */
        *out = alvo->valor;
    }

    /* se só tem um elemento entao frente recebe NULL */
    if (f->tamanho == 1)
    {
        f->frente = NULL;
    }
    else
    {
        FCDNodo *nova_frente = alvo->prox;
        FCDNodo *cauda = alvo->ant;

        cauda->prox = nova_frente;
        nova_frente->ant = cauda;

        f->frente = nova_frente;
    }
    free(alvo);
    f->tamanho = f->tamanho - 1;
    return 1;
}

/* Remove todos os nós (fila fica vazia) */
void fila_circular_limpar(FilaCircularDupla *f)
{
    size_t i;
    FCDNodo *atual;
    FCDNodo *prox;

    if (f == NULL)
    {
        return;
    }
    else
    {
        if (f->frente == NULL)
        {
            f->tamanho = 0; /* garantia */
            return;
        }
    }

    atual = f->frente;
    for (i = 0; i < f->tamanho; i++)
    {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    f->frente = NULL;
    f->tamanho = 0;
}

/* Imprime a fila (utilitário de depuração) */
void fila_circular_imprimir(const FilaCircularDupla *f)
{
    size_t i;
    FCDNodo *atual;

    if (f == NULL)
    {
        printf("(fila nula)\n");
        return;
    }
    else
    {
        if (f->frente == NULL)
        {
            printf("[]\n"); /* opcional */
            return;
        }
    }

    printf("[");
    i = 0;             /* <= inicializar i */
    atual = f->frente; /* <= correção do '=' */
    while (i < f->tamanho)
    {
        printf("%d", atual->valor);
        if (i + 1 < f->tamanho)
        {
            printf(", ");
        }
        atual = atual->prox;
        i = i + 1;
    }
    printf("]\n");
}
