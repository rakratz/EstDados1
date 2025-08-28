#include "fila.h"

int main(void) {
    Fila* f = fila_cria();

    // 1) incluir / inserir_final (enqueue)
    incluir(f, 60);
    incluir(f, 10);
    incluir(f, 30);
    listar(f); // 60 10 30

    // 2) pesquisar
    printf("Posicao logica do 10: %d\n", pesquisar(f, 10));

    // 3) excluir (dequeue)
    int remov;
    excluir(f, &remov);
    printf("Excluiu da frente: %d\n", remov);
    listar(f); // 10 30

    // 4) inserir_ordenado (mantém crescente)
    inserir_ordenado(f, 25);
    inserir_ordenado(f, 15);
    inserir_ordenado(f, 40);
    listar(f); // 10 15 25 30 40  (ordem lógica)

    // 5) excluir_valor (remove a 1ª ocorrência do 25)
    excluir_valor(f, 25);
    listar(f); // 10 15 30 40

    // 6) encher para testar circularidade visualmente
    inserir_final(f, 50);
    inserir_final(f, 60);
    inserir_final(f, 70);
    inserir_final(f, 80);
    listar(f);

    fila_libera(f);
    return 0;
}
