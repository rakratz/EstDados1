#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main() {
    Pessoa p1;

    strcpy(p1.nome, "Joao");
    p1.idade = 25;
    p1.altura = 1.80;

    printf("Nome: %s\nIdade: %d\nAltura: %.2f\n",
           p1.nome, p1.idade, p1.altura);

    return 0;
}
