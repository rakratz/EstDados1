/*
  -----------------------------------------------------
  CMP2106 - Estrutura de Dados I
  Aula 01 - Revisão de C
  Professor: Ricardo de Andrade Kratz
  Autor: [Nome do Aluno]
  Data: [DD/MM/AAAA]
  Descrição: Exemplo de uso de estruturas de controle (menu,
             laço while, switch/case) e leitura segura.
  -----------------------------------------------------
*/

#include <stdio.h>     // printf, scanf
#include <stdlib.h>    // exit (se necessário)
#include <locale.h>    // setlocale para acentuação
#include <ctype.h>     // isspace (se útil em extensões)

/* -----------------------------------------------------
   Função utilitária: limpa caracteres remanescentes
   no buffer de entrada (stdin) até a próxima quebra de linha.
   Útil quando scanf falha ou quando sobram caracteres.
   ----------------------------------------------------- */
static void limpa_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* descarta */ ;
    }
}

/* -----------------------------------------------------
   Lê um inteiro do usuário com validação simples.
   Retorna 1 (sucesso) e armazena em *out;
   Retorna 0 (falha); nesse caso, o buffer é limpo.
   ----------------------------------------------------- */
static int le_inteiro(const char *prompt, int *out) {
    int ok;

    if (prompt != NULL) {
        printf("%s", prompt);
    }

    ok = scanf("%d", out);
    if (ok != 1) {
        printf("Entrada inválida. Tente novamente.\n");
        limpa_buffer();
        return 0;
    }
    // consome o '\n' que pode ter ficado
    limpa_buffer();
    return 1;
}

/* -----------------------------------------------------
   Exibe o menu principal.
   ----------------------------------------------------- */
static void mostra_menu(void) {
    printf("\n===== MENU =====\n");
    printf("1. Mostrar mensagem\n");
    printf("2. Calcular soma\n");
    printf("3. Sair\n");
    printf("Escolha: ");
}

/* -----------------------------------------------------
   Ação 1: Exibe uma mensagem de boas-vindas.
   ----------------------------------------------------- */
static void acao_mostrar_mensagem(void) {
    printf("Olá, bem-vindo(a) à Aula 2!\n");
}

/* -----------------------------------------------------
   Ação 2: Lê dois inteiros com validação e imprime a soma.
   ----------------------------------------------------- */
static void acao_calcular_soma(void) {
    int a, b;

    // Lê o primeiro número
    while (!le_inteiro("Digite o primeiro número: ", &a)) {
        /* repete até ler corretamente */
    }

    // Lê o segundo número
    while (!le_inteiro("Digite o segundo número: ", &b)) {
        /* repete até ler corretamente */
    }

    printf("Soma = %d\n", a + b);
}

/* -----------------------------------------------------
   Função principal: controla o loop do menu.
   ----------------------------------------------------- */
int main(void) {
    // Habilita acentuação em muitos terminais (depende do SO/terminal)
    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;
    int leitura_ok;

    // Loop principal: continua até o usuário escolher sair (3)
    while (1) {
        mostra_menu();

        // Lemos a opção com validação. Se falhar, volta ao topo do loop.
        leitura_ok = scanf("%d", &opcao);
        if (leitura_ok != 1) {
            printf("Opção inválida. Digite um número.\n");
            limpa_buffer();
            continue;
        }
        // limpa possível '\n' restante
        limpa_buffer();

        // Desvia de acordo com a opção escolhida
        switch (opcao) {
            case 1:
                acao_mostrar_mensagem();
                break;

            case 2:
                acao_calcular_soma();
                break;

            case 3:
                printf("Encerrando o programa...\n");
                return 0; // sai do main

            default:
                printf("Opção inválida! Escolha 1, 2 ou 3.\n");
                break;
        }
    }

    // Nunca chega aqui por causa do return no case 3
    // (mantido por completude)
    return 0;
}
