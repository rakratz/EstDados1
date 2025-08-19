// Arquivo: ponto.h
#ifndef PONTO_H
#define PONTO_H

// Tipo opaco: a struct "ponto" é definida em ponto.c
typedef struct ponto Ponto;

// Cria um novo ponto com coordenadas (x, y).
 Ponto* pto_cria(float x, float y);

// Libera a memória de um ponto.
void pto_libera(Ponto* p);

// Acessa os valores (x, y) de um ponto.
 void pto_acessa(const Ponto* p, float* x, float* y);

// Atribui novos valores (x, y) a um ponto.
void pto_atribui(Ponto* p, float x, float y);

// Calcula a distância Euclidiana entre dois pontos.
 float pto_distancia(const Ponto* p1, const Ponto* p2);

#endif // PONTO_H
