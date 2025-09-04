#include <stdio.h>
#include "pilha.h"

// inicializar pilha
void inicializa(Pilha *p) {
    p->topo = -1;
}

// verificar se está vazia
int isEmpty(Pilha *p) {
    return p->topo == -1;
}

// verificar se está cheia
int isFull(Pilha *p) {
    return p->topo == MAX - 1;
}

// empilhar
void push(Pilha *p, int valor) {
    if (isFull(p)) {
        printf("Erro: pilha cheia!\n");
        return;
    }
    p->dados[++(p->topo)] = valor;
}

// desempilhar
int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: pilha vazia!\n");
        return -1; // valor de erro
    }
    return p->dados[(p->topo)--];
}

// consultar topo
int peek(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: pilha vazia!\n");
        return -1;
    }
    return p->dados[p->topo];
}
