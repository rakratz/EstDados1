/* ----------------------------------------------------- 
CMP2106 - Estrutura de Dados I Aula 01 - Revisão de C 
Professor: Ricardo de Andrade Kratz 
Autor: [Nome do Aluno] 
Data: [DD/MM/AAAA] 
Descrição: Exemplo de uso de estruturas de controle em C. 
----------------------------------------------------- */ 
#include <stdio.h>

int main() {
    int opcao = 0; // variável que armazena a escolha do usuário

    // O loop continua enquanto a opção escolhida for diferente de 4
    while (opcao != 4) {
        // Exibe o menu
        printf("\n=== MENU ===\n");
        printf("1. Bom dia\n");
        printf("2. Calcular quadrado de um número\n");
        printf("3. Contar ate 10\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao); // Lê a opção do usuário

        // Estrutura de decisão
        if (opcao == 1) {
            printf("Bom dia!\n");
        } else if (opcao == 2) {
            int x;
            printf("Digite um numero: ");
            scanf("%d", &x);
            printf("Quadrado = %d\n", x * x);
        } else if (opcao == 3) {
            // Exemplo de while dentro do menu
            int i = 1;
            while (i <= 10) {
                printf("%d ", i);
                i++;
            }
            printf("\n");
        } else if (opcao != 4) {
            printf("Opcao invalida!\n");
        }
    }
    return 0;
}
