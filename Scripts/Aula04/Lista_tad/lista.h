// Arquivo: lista.h
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // capacidade máxima

// Tipo opaco
typedef struct lista Lista;

// Cria / destrói
Lista* cria_lista(void);
void   lista_libera(Lista* l);

// Operações
int  insere_final(Lista* l, int elem);
int  remove_elem(Lista* l, int elem);     // remove 1ª ocorrência (deslocando)
int  busca_elem(const Lista* l, int elem);
void imprime_lista(const Lista* l);
int  lista_tamanho(const Lista* l);

#endif // LISTA_H
