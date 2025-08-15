#include <stdio.h>

int main(void) {
    int a = 90;
    int b = 2;
    int c = 3;
    int *ptr = &a; // ponteiro para inteiro

    printf("Valor de ptr: %p, Conteudo de ptr: %d\n", (void*)ptr, *ptr);
    printf("B: %d, C: %d\n", b, c);

    return 0;
}