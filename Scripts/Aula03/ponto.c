// Arquivo: ponto.c

#include <stdlib.h>   // uso de NULL e malloc/free
#include <math.h>     // funções matemáticas (sqrt, pow, etc.)
#include "ponto.h"    // inclusão da interface (protótipos)

// Definição do tipo de dados (opaca)
struct ponto {
    float x;
    float y;
};

// Cria um novo ponto com coordenadas (x, y)
Ponto* pto_cria(float x, float y) {
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

// Libera a memória alocada para um ponto
void pto_libera(Ponto* p) {
    free(p);  // free já trata o caso de p == NULL
}

// Acessa os valores "x" e "y" de um ponto
void pto_acessa(const Ponto* p, float* x, float* y) {
    if (p != NULL) {
        if (x != NULL) *x = p->x;
        if (y != NULL) *y = p->y;
    }
}

// Atribui os valores "x" e "y" a um ponto
void pto_atribui(Ponto* p, float x, float y) {
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
}

// Calcula a distância entre dois pontos
float pto_distancia(const Ponto* p1, const Ponto* p2) {
    if (p1 == NULL || p2 == NULL) return -1.0f;

    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;

    return sqrtf(dx * dx + dy * dy);
}
// Fim do arquivo ponto.c