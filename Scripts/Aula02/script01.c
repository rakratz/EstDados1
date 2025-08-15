/*
  -----------------------------------------------------
  CMP2106 - Estrutura de Dados I
  Aula 01 - Revisão de C
  Professor: Ricardo de Andrade Kratz
  Autor: [Nome do Aluno]
  Data: [DD/MM/AAAA]
  Descrição: Olá, mundo! e soma de dois números
  -----------------------------------------------------
*/

#include <stdio.h>
#include <locale.h> // necessário para setlocale

int main() {
    // Configura a localidade para permitir acentos no terminal
    setlocale(LC_ALL, "Portuguese");

    printf("Olá, mundo!\n");
    printf("Resultado da soma: %d\n", 2 + 3);

    return 0;
}