#include <stdio.h>
#include "fila.h"
#include "persistencia.h"

int main(void)
{
    Fila *f = criarFila();
    if (f == NULL)
    {
        printf("Erro ao criar fila.\n");
        return 1;
    }

    Pessoa p1 = {"Ana", 25};
    Pessoa p2 = {"Bruno", 19};
    Pessoa p3 = {"Carla", 42};
    Pessoa p4 = {"Daniel", 30};

    enfileirar(f, p1);
    enfileirar(f, p2);
    enfileirar(f, p3);
    enfileirar(f, p4);

    printf("Fila original:\n");
    imprimirFila(f);

    printf("\nSalvando em arquivo 'pessoas.txt'...\n");
    salvarEmArquivo(f, "pessoas.txt");

    printf("\nOrdenando por idade crescente:\n");
    ordenarPorIdade(f, 1);
    imprimirFila(f);

    printf("\nOrdenando por idade decrescente:\n");
    ordenarPorIdade(f, 0);
    imprimirFila(f);

    printf("Limpando fila e recarregando do arquivo...\n");
    limparFila(f);
    carregarDeArquivo(f, "pessoas.txt");

    printf("Fila recarregada do arquivo:\n");
    imprimirFila(f);

    destruirFila(f);
    return 0;
}
