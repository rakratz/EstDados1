#ifndef PILHA_H
#define PILHA_H

#define MAX 5   // capacidade da pilha

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

// operações básicas
void inicializa(Pilha *p);
int isEmpty(Pilha *p);
int isFull(Pilha *p);
void push(Pilha *p, int valor);
int pop(Pilha *p);
int peek(Pilha *p);

#endif
