// Arquivo: main.c
#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main(void) {
    float d;
    Ponto *p = pto_cria(10.0f, 21.0f);
    Ponto *q = pto_cria(7.0f, 25.0f);

    // valida alocação
    if (!p || !q) {
        fprintf(stderr, "Erro: falha ao alocar pontos.\n");
        pto_libera(p);
        pto_libera(q);
        return 1;
    }

    // Ponto r;            // ERRO: tipo opaco, não pode instanciar direto
    // q->x = 2;           // ERRO: campos são encapsulados
    // use as funções do TAD:
    // pto_atribui(q, 2.0f, 25.0f);

    d = pto_distancia(p, q);
    printf("Distancia entre pontos: %.2f\n", d);

    pto_libera(p);
    pto_libera(q);
    return 0;
}
