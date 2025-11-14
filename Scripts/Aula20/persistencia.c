#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persistencia.h"

int salvarEmArquivo(Fila *f, const char *nomeArquivo)
{
    if (f == NULL || nomeArquivo == NULL)
        return 0;

    FILE *arq = fopen(nomeArquivo, "w");
    if (arq == NULL)
    {
        perror("Erro ao abrir arquivo para escrita");
        return 0;
    }

    No *atual = f->inicio;
    while (atual != NULL)
    {
        fprintf(arq, "%s;%d\n",
                atual->dado.nome,
                atual->dado.idade);
        atual = atual->prox;
    }

    fclose(arq);
    return 1;
}

int carregarDeArquivo(Fila *f, const char *nomeArquivo)
{
    if (f == NULL || nomeArquivo == NULL)
        return 0;

    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL)
    {
        perror("Erro ao abrir arquivo para leitura");
        return 0;
    }

    limparFila(f);

    char linha[200];
    while (fgets(linha, sizeof(linha), arq) != NULL)
    {
        Pessoa p;
        /* Lê até o ';' como nome (pode ter espaço) e depois a idade */
        if (sscanf(linha, " %49[^;];%d", p.nome, &p.idade) == 2)
        {
            enfileirar(f, p);
        }
    }

    fclose(arq);
    return 1;
}

int apagarArquivo(const char *nomeArquivo)
{
    if (nomeArquivo == NULL)
        return 0;
    if (remove(nomeArquivo) == 0)
    {
        return 1;
    }
    else
    {
        perror("Erro ao apagar arquivo");
        return 0;
    }
}
