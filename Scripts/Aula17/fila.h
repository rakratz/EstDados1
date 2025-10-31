#ifndef FILA_H
#define FILA_H

/* Fila Linear (FIFO) baseada em vetor.
   Implementação simples: desenfileirar faz shift à esquerda. */

typedef struct
{
    int *dados;     /* vetor */
    int tamanho;    /* qtd de elementos válidos */
    int capacidade; /* tamanho máximo */
} FilaLinear;

/* Inicializador */
int filaLienar_inicializar(FilaLinear *f, int capacidade);

/* Liberar a fila (memória) */
void filaLinear_limpar(FilaLinear *f);

/* Apoio (estado) */
int filaLienar_vazia(const FilaLinear *f);
int filaLienar_cheia(const FilaLinear *f);
int filaLienar_tamanho(const FilaLinear *f);

/* Operações básicas */
int filaLienar_enfileirar(FilaLinear *f, int v);       /* push back */
int filaLienar_desenfileirar(FilaLinear *f, int *out); /* pop front (shift) */
int filaLienar_frente(FilaLinear *f, int *out);        /* peek */

/* Imprimir */
void filaLinear_imprimir(const FilaLinear *f);

/* Ordenação Shell Sort - crescente (!=0) / decrescente (==0) sobre os N primeiros */
void filaLinear_shellSort(FilaLinear *f, int n, int crescente);

#endif /* FILA_H */
