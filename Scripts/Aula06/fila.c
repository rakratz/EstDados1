#include "fila.h"

// ---------- helpers internos ----------
static int phys_index(const Fila* f, int pos_logica) {
    // converte posição lógica [0..qtd-1] para índice físico do vetor
    return (f->ini + pos_logica) % FCAP;
}

static void shift_right(Fila* f, int pos_logica) {
    // desloca elementos uma posição à direita (do fim para pos_logica),
    // abrindo espaço em pos_logica. Usa aritmética modular.
    // Pré-condições: !fila_cheia(f) e 0 <= pos_logica <= f->qtd
    int i;
    for (i = f->qtd; i > pos_logica; i--) {
        int dst = phys_index(f, i);
        int src = phys_index(f, i - 1);
        f->dados[dst] = f->dados[src];
    }
    // atualiza 'fim' e 'qtd'
    f->fim = (f->fim + 1) % FCAP;
    f->qtd++;
}

static void shift_left(Fila* f, int pos_logica) {
    // desloca elementos uma posição à esquerda (de pos_logica até fim-1),
    // "fechando buraco" em pos_logica. Atualiza ini/fim/qtd.
    // Pré-condição: 0 <= pos_logica < f->qtd
    for (int i = pos_logica; i < f->qtd - 1; i++) {
        int dst = phys_index(f, i);
        int src = phys_index(f, i + 1);
        f->dados[dst] = f->dados[src];
    }
    // ao remover o último lógico, basta andar 'fim' para trás
    f->fim = (f->fim - 1 + FCAP) % FCAP;
    f->qtd--;
}

// ---------- API ----------
Fila* fila_cria(void) {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f) { f->ini = 0; f->fim = 0; f->qtd = 0; }
    return f;
}

void fila_libera(Fila* f) { free(f); }

bool fila_vazia(const Fila* f) { return !f || f->qtd == 0; }

bool fila_cheia(const Fila* f) { return f && f->qtd == FCAP; }

int fila_tamanho(const Fila* f) { return f ? f->qtd : 0; }

int incluir(Fila* f, int x) {
    if (!f || fila_cheia(f)) return 0;
    f->dados[f->fim] = x;
    f->fim = (f->fim + 1) % FCAP;
    f->qtd++;
    return 1;
}

int excluir(Fila* f, int* out) {
    if (!f || fila_vazia(f)) return 0;
    if (out) *out = f->dados[f->ini];
    f->ini = (f->ini + 1) % FCAP;
    f->qtd--;
    return 1;
}

int pesquisar(const Fila* f, int x) {
    if (!f) return -1;
    for (int i = 0; i < f->qtd; i++) {
        if (f->dados[phys_index(f, i)] == x) return i; // posição lógica
    }
    return -1;
}

void listar(const Fila* f) {
    if (!f) { printf("(fila nula)\n"); return; }
    printf("Fila (%d/%d): ", f->qtd, FCAP);
    for (int i = 0; i < f->qtd; i++) {
        printf("%d ", f->dados[phys_index(f, i)]);
    }
    printf("\n");
}

// Mantém ordem crescente; se cheia -> falha
int inserir_ordenado(Fila* f, int x) {
    if (!f || fila_cheia(f)) return 0;

    // caso trivial: vazia -> insere normal
    if (fila_vazia(f)) return incluir(f, x);

    // encontra posição lógica onde x deve entrar
    int pos = 0;
    while (pos < f->qtd && f->dados[phys_index(f, pos)] < x) pos++;

    // abre espaço deslocando à direita
    shift_right(f, pos);
    f->dados[phys_index(f, pos)] = x;
    return 1;
}

// Remove a 1ª ocorrência do valor; retorna 1 se removeu
int excluir_valor(Fila* f, int x) {
    if (!f || fila_vazia(f)) return 0;
    int pos = pesquisar(f, x);
    if (pos == -1) return 0;
    shift_left(f, pos);
    return 1;
}
