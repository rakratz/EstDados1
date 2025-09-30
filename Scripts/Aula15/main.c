#include <stdio.h>
#include "lista.h"

int main()
{
    Lista lista;

    inicializarLista(&lista);

    insereInicio(&lista, 10);
    insereInicio(&lista, 20);
    insereInicio(&lista, 30);
    insereInicio(&lista, 40);
    insereFim(&lista, 5);
    imprimeLista(&lista);
    return 0;
}