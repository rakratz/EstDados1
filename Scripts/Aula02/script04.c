/*
  -----------------------------------------------------
  CMP2106 - Estrutura de Dados I
  Aula 01 - Revisão de C
  Professor: Ricardo de Andrade Kratz
  Autor: [Nome do Aluno]
  Data: [DD/MM/AAAA]
  Descrição: for com break e continue – Procurando números primos
  -----------------------------------------------------
*/
#include <stdio.h>

int main() {
    int numero, i, primo;

    printf("Digite um número: ");
    scanf("%d", &numero);

    // Percorre todos os números de 2 até o número digitado
    for (int n = 2; n <= numero; n++) {
        primo = 1; // assume que o número é primo
        // Testa divisores de 2 até n-1
        for (i = 2; i < n; i++) {
            if (n % i == 0) { // se for divisível, não é primo
                primo = 0;
                break; // sai do loop interno
            }
        }
        if (primo)
            printf("%d é primo\n", n);
    }
    return 0;
}
