#ifndef FILA_H
#define FILA_H

#define TAM_NOME 50

typedef struct
{
    char nome[TAM_NOME];
    int idade;
} Pessoa;

typedef struct No
{
    Pessoa dado;
    struct No *ant;
    struct No *prox;
} No;

typedef struct
{
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

/* Criação / destruição */
Fila *criarFila();
void destruirFila(Fila *f);
void limparFila(Fila *f);

/* Operações básicas */
int filaVazia(Fila *f);
int enfileirar(Fila *f, Pessoa p);        /* insere no fim */
int desenfileirar(Fila *f, Pessoa *pOut); /* remove do início */

/* Utilitários */
void imprimirFila(Fila *f);

/* Ordenação por idade: crescente != 0 -> crescente; 0 -> decrescente */
void ordenarPorIdade(Fila *f, int crescente);

/* Busca/remoção/atualização por nome (igualdade exata) */
No *buscarPorNome(Fila *f, const char *nome);
int removerPorNome(Fila *f, const char *nome);
int atualizarPessoa(Fila *f, const char *nomeAntigo, Pessoa novaPessoa);

#endif /* FILA_H */