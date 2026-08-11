#include <stdio.h>

int main() {

    int x = 10;
    int *p = &x;

    printf("ANTES DA ALTERACAO\n\n");

    printf("Valor de x: %d\n", x);
    printf("Endereco de x: %p\n", (void*)&x);
    printf("Valor de p: %p\n", (void*)p);
    printf("Valor apontado por p: %d\n", *p);

    // Alterando o valor atraves do ponteiro
    *p = 50;

    printf("\nDEPOIS DA ALTERACAO\n\n");

    printf("Valor de x: %d\n", x);
    printf("Endereco de x: %p\n", (void*)&x);
    printf("Valor de p: %p\n", (void*)p);
    printf("Valor apontado por p: %d\n", *p);

    return 0;
}
