#include <stdio.h>
#include "pilha.h"

int main(void)
{
    Pilha p;
    pilha_inicializar(&p);
    /* Ver topo */
    int x;

    if (pilha_topo(&p, &x))
    {
        printf("Topo atual: %d\n", x); /* esperado: 30 */
    }
    else
    {
        printf("Pilha vazia (sem topo)\n");
    }

    /* Empilhar 3 valores */
    pilha_empilhar(&p, 10);
    pilha_empilhar(&p, 20);
    pilha_empilhar(&p, 30);
    pilha_imprimir(&p); /* esperado: 30 -> 20 -> 10 -> NULL */


    if (pilha_topo(&p, &x))
    {
        printf("Topo atual: %d\n", x); /* esperado: 30 */
    }
    else
    {
        printf("Pilha vazia (sem topo)\n");
    }

    /* Desempilhar dois valores */
    if (pilha_desempilhar(&p, &x))
    {
        printf("Desempilhei: %d\n", x); /* esperado: 30 */
    }
    pilha_imprimir(&p); /* esperado: 20 -> 10 -> NULL */

    if (pilha_desempilhar(&p, &x))
    {
        printf("Desempilhei: %d\n", x); /* esperado: 20 */
    }
    pilha_imprimir(&p); /* esperado: 10 -> NULL */

    if (pilha_desempilhar(&p, &x)) {
        printf("Desempilhei: %d\n", x); /* esperado: 20 */
    }
    pilha_imprimir(&p);                  /* esperado: 10 -> NULL */
    
    /* Esvaziar geral */
    pilha_limpar(&p);
    pilha_imprimir(&p);

    return 0;
}