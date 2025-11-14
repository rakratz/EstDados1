#include <stdio.h>
#include <string.h>
#include "fila.h"
#include "persistencia.h"

#define ARQUIVO_DADOS "pessoas.txt"

/* Remove o '\n' de fgets */
void removerQuebraLinha(char *str)
{
    if (str == NULL)
        return;
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

void lerPessoaDoTeclado(Pessoa *p)
{
    if (p == NULL)
        return;
    printf("Digite o nome: ");
    fgets(p->nome, TAM_NOME, stdin);
    removerQuebraLinha(p->nome);

    printf("Digite a idade: ");
    scanf("%d", &p->idade);
    getchar(); /* consome '\n' do buffer */
}

void mostrarMenu()
{
    printf("\n========== MENU FILA PESSOAS ==========\n");
    printf("1 - Inserir pessoa na fila\n");
    printf("2 - Remover pessoa (desenfileirar)\n");
    printf("3 - Listar fila\n");
    printf("4 - Ordenar por idade (crescente)\n");
    printf("5 - Ordenar por idade (decrescente)\n");
    printf("6 - Salvar fila em arquivo\n");
    printf("7 - Carregar fila do arquivo\n");
    printf("8 - Remover pessoa por nome\n");
    printf("9 - Atualizar pessoa por nome\n");
    printf("10 - Apagar arquivo de dados\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main(void)
{
    Fila *f = criarFila();
    if (f == NULL)
    {
        printf("Erro ao criar fila.\n");
        return 1;
    }

    int opcao;
    do
    {
        mostrarMenu();
        if (scanf("%d", &opcao) != 1)
        {
            /* entrada inválida */
            printf("Opcao invalida.\n");
            /* limpar buffer */
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            continue;
        }
        getchar(); /* consome '\n' após o número */

        if (opcao == 1)
        {
            Pessoa p;
            lerPessoaDoTeclado(&p);
            if (enfileirar(f, p))
            {
                printf("Pessoa inserida com sucesso.\n");
            }
            else
            {
                printf("Falha ao inserir pessoa.\n");
            }
        }
        else if (opcao == 2)
        {
            Pessoa p;
            if (desenfileirar(f, &p))
            {
                printf("Pessoa removida: %s (%d anos)\n", p.nome, p.idade);
            }
            else
            {
                printf("Fila vazia, nada a remover.\n");
            }
        }
        else if (opcao == 3)
        {
            imprimirFila(f);
        }
        else if (opcao == 4)
        {
            ordenarPorIdade(f, 1);
            printf("Fila ordenada por idade (crescente).\n");
        }
        else if (opcao == 5)
        {
            ordenarPorIdade(f, 0);
            printf("Fila ordenada por idade (decrescente).\n");
        }
        else if (opcao == 6)
        {
            if (salvarEmArquivo(f, ARQUIVO_DADOS))
            {
                printf("Fila salva em '%s'.\n", ARQUIVO_DADOS);
            }
            else
            {
                printf("Falha ao salvar arquivo.\n");
            }
        }
        else if (opcao == 7)
        {
            if (carregarDeArquivo(f, ARQUIVO_DADOS))
            {
                printf("Fila carregada de '%s'.\n", ARQUIVO_DADOS);
            }
            else
            {
                printf("Falha ao carregar arquivo.\n");
            }
        }
        else if (opcao == 8)
        {
            char nome[TAM_NOME];
            printf("Digite o nome da pessoa a remover: ");
            fgets(nome, TAM_NOME, stdin);
            removerQuebraLinha(nome);

            if (removerPorNome(f, nome))
            {
                printf("Pessoa removida com sucesso.\n");
            }
            else
            {
                printf("Pessoa nao encontrada.\n");
            }
        }
        else if (opcao == 9)
        {
            char nomeAntigo[TAM_NOME];
            printf("Digite o nome da pessoa a atualizar: ");
            fgets(nomeAntigo, TAM_NOME, stdin);
            removerQuebraLinha(nomeAntigo);

            No *no = buscarPorNome(f, nomeAntigo);
            if (no == NULL)
            {
                printf("Pessoa nao encontrada.\n");
            }
            else
            {
                printf("Pessoa atual: %s (%d anos)\n",
                       no->dado.nome, no->dado.idade);
                Pessoa nova;
                lerPessoaDoTeclado(&nova);
                if (atualizarPessoa(f, nomeAntigo, nova))
                {
                    printf("Cadastro atualizado com sucesso.\n");
                }
                else
                {
                    printf("Falha ao atualizar.\n");
                }
            }
        }
        else if (opcao == 10)
        {
            if (apagarArquivo(ARQUIVO_DADOS))
            {
                printf("Arquivo '%s' apagado com sucesso.\n", ARQUIVO_DADOS);
            }
            else
            {
                printf("Falha ao apagar arquivo (talvez nao exista).\n");
            }
        }
        else if (opcao == 0)
        {
            printf("Saindo...\n");
        }
        else
        {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    destruirFila(f);
    return 0;
}