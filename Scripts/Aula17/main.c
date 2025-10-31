#include <stdio.h>
#include "fila.h"

int main(void)
{
    FilaLinear f;
    int ok, tmp;

    /* inicializa */
    ok = filaLienar_inicializar(&f, 10);
    if (!ok)
    {
        printf("Falha ao inicializar a Fila\n");
        return 1;
    }
    else
    {
        printf("Fila inicializada.\n");
    }

    /* enfileirar */
    filaLienar_enfileirar(&f, 10);
    filaLienar_enfileirar(&f, 9);
    filaLienar_enfileirar(&f, 30);
    filaLienar_enfileirar(&f, 4);

    /* imprime estado atual */
    filaLinear_imprimir(&f);

    /* frente */
    if (filaLienar_frente(&f, &tmp))
    {
        printf("Frente da Fila {%d}\n", tmp);
    }

    /* tamanho */
    printf("Tamanho atual: %d\n", filaLienar_tamanho(&f));

    /* desenfileirar um */
    if (filaLienar_desenfileirar(&f, &tmp))
    {
        printf("Desenfileirado {%d}\n", tmp);
    }
    filaLinear_imprimir(&f);

    /* enfileira mais um e imprime */
    filaLienar_enfileirar(&f, 40);
    filaLinear_imprimir(&f);

    /* ordenar crescente todo o conteúdo atual */
    filaLinear_shellSort(&f, f.tamanho, 1);
    printf("Ordenada (crescente):\n");
    filaLinear_imprimir(&f);

    /* ordenar decrescente todo o conteúdo atual */
    filaLinear_shellSort(&f, f.tamanho, 0);
    printf("Ordenada (decrescente):\n");
    filaLinear_imprimir(&f);

    /* liberar memória */
    filaLinear_limpar(&f);
    return 0;
}
