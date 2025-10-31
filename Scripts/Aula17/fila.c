#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

/* Inicializador */
int filaLienar_inicializar(FilaLinear *f, int capacidade)
{
    if (!f || capacidade <= 0)
    {
        printf("Erro: capacidade invalida!\n");
        return 0;
    }
    f->dados = (int *)malloc(sizeof(int) * capacidade);
    if (!f->dados)
    {
        printf("Erro ao alocar memoria!\n");
        return 0;
    }
    f->tamanho = 0;
    f->capacidade = capacidade;
    return 1;
}

/* Liberar a fila (memoria) */
void filaLinear_limpar(FilaLinear *f)
{
    if (!f)
        return;
    free(f->dados);
    f->dados = NULL;
    f->tamanho = 0;
    f->capacidade = 0;
}

/* Apoio (estado) */
int filaLienar_vazia(const FilaLinear *f)
{
    if (!f)
        return 1;
    return (f->tamanho == 0) ? 1 : 0;
}

int filaLienar_cheia(const FilaLinear *f)
{
    if (!f)
        return 0;
    return (f->tamanho == f->capacidade) ? 1 : 0;
}

int filaLienar_tamanho(const FilaLinear *f)
{
    return f ? f->tamanho : 0;
}

/* Operações básicas */

/* Enfileirar — O(1) */
int filaLienar_enfileirar(FilaLinear *f, int v)
{
    if (!f || filaLienar_cheia(f))
    {
        printf("Fila cheia\n");
        return 0;
    }
    f->dados[f->tamanho++] = v;
    return 1;
}

/* Desenfileirar — O(n) (shift à esquerda) */
int filaLienar_desenfileirar(FilaLinear *f, int *out)
{
    if (!f || filaLienar_vazia(f))
    {
        printf("Fila vazia\n");
        return 0;
    }
    if (out)
        *out = f->dados[0];

    for (int i = 1; i < f->tamanho; i++)
    {
        f->dados[i - 1] = f->dados[i];
    }
    f->tamanho--;
    return 1;
}

/* Frente (peek) — O(1) */
int filaLienar_frente(FilaLinear *f, int *out)
{
    if (!f || filaLienar_vazia(f))
    {
        printf("Fila vazia\n");
        return 0;
    }
    if (out)
        *out = f->dados[0];
    return 1;
}

/* Imprimir */
void filaLinear_imprimir(const FilaLinear *f)
{
    printf("FilaLienar [0..%d): ", filaLienar_tamanho(f));
    if (filaLienar_vazia(f))
    {
        printf("[vazia]\n");
        return;
    }
    for (int i = 0; i < f->tamanho; i++)
    {
        printf("%d", f->dados[i]);
        if (i < f->tamanho - 1)
            printf(" -> ");
    }
    printf(" -> NULL\n");
}

/* Ordenação Shell Sort - crescente e decrescente (primeiros n elementos) */
/* O(n^2) */
/* Caso médio O(n.log(n))*/
/* Melhor caso O(n)*/
void filaLinear_shellSort(FilaLinear *f, int n, int crescente)
{
    if (!f || !f->dados)
        return;
    if (f->tamanho <= 1)
        return;

    if (n <= 0 || n > f->tamanho)
        n = f->tamanho;

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int tmp = f->dados[i];
            int j = i;

            if (crescente)
            {
                while (j >= gap && f->dados[j - gap] > tmp)
                {
                    f->dados[j] = f->dados[j - gap];
                    j -= gap;
                }
            }
            else
            {
                while (j >= gap && f->dados[j - gap] < tmp)
                {
                    f->dados[j] = f->dados[j - gap];
                    j -= gap;
                }
            }
            f->dados[j] = tmp;
        }
    }
}
