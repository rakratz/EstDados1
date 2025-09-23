#include <stdio.h>
#include "lista.h"

int main()
{
    Lista L;
    inicializaLista(&L);

    // Verificar se existe a lista e está vazia
    printf("A lista existe e esta vazia? \n");
    if (estaVazia){
        printf("Sim");
    }
    imprimeLista(&L);
    printf("Inserindo no inicio 10 e 20\n");
    insereInicio(&L, 10);
    insereInicio(&L, 20);
    insereInicio(&L, 30);
    insereInicio(&L, 40);
    insereInicio(&L, 50);
    insereInicio(&L, 60);
    imprimeLista(&L);
    removeInicio(&L); // Remover 60
    imprimeLista(&L);
    removeFim(&L); // Remover 10
    imprimeLista(&L);
    busca(&L, 25);
    if (removeElemento(&L, 25) == 0) {
         printf("25 nao foi removido\n");
    }
    busca(&L, 20);
    removeElemento(&L, 20);
    busca(&L, 20);
    imprimeLista(&L);
    return 0;
}