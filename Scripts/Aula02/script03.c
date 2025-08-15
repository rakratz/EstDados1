/*
  -----------------------------------------------------
  CMP2106 - Estrutura de Dados I
  Aula 01 - Revisão de C
  Professor: Ricardo de Andrade Kratz
  Autor: [Nome do Aluno]
  Data: [DD/MM/AAAA]
  Descrição: Exemplo de uso de estruturas de repetição em C
             com for crescente e for decrescente pulando de 2 em 2.
  -----------------------------------------------------
*/
#include <stdio.h>

int main() {
    int n;

    // Leitura do número para gerar a tabuada
    printf("Digite um número para ver sua tabuada: ");
    scanf("%d", &n);

    // For crescente de 1 até 10
    printf("\nTabuada crescente:\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    // For decrescente de 10 até 1, pulando de 2 em 2
    printf("\nTabuada decrescente (pulando de 2 em 2):\n");
    for (int i = 10; i >= 1; i -= 2) {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    return 0;
}
