/*
  -----------------------------------------------------
  CMP2106 - Estrutura de Dados I
  Aula 01 - Revisão de C
  Professor: Ricardo de Andrade Kratz
  Autor: [Nome do Aluno]
  Data: [DD/MM/AAAA]
  Descrição: while com ponteiro – Soma de vetor
  -----------------------------------------------------
*/
#include <stdio.h>

int main() {
    int numeros[] = {2, 4, 6, 8, 10}; // vetor de inteiros
    int *ptr = numeros; // ponteiro para o primeiro elemento do vetor
    int soma = 0, i = 0;

    // percorre o vetor usando ponteiro
    while (i < 5) {
        soma += *(ptr + i); // *(ptr + i) acessa o elemento i
        i++;
    }

    printf("Soma dos elementos: %d\n", soma);
    return 0;
}
