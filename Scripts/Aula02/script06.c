/*
  -----------------------------------------------------
  CMP2106 - Estrutura de Dados I
  Aula 01 - Revisão de C
  Professor: Ricardo de Andrade Kratz
  Autor: [Nome do Aluno]
  Data: [DD/MM/AAAA]
  Descrição: Adivinhação de número aleatório
  -----------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numero, chute;
    srand(time(NULL));
    numero = rand() % 10 + 1; // número aleatório de 1 a 10

    do {
        printf("Adivinhe o número (1 a 10): ");
        scanf("%d", &chute);

        if (chute > numero)
            printf("Muito alto!\n");
        else if (chute < numero)
            printf("Muito baixo!\n");
        else
            printf("Acertou!\n");

    } while (chute != numero);

    return 0;
}
