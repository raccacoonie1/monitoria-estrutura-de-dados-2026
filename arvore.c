#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore
struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
};

// Função para criar um novo nó
struct No* criarNo(int valor) {
    
    // Reserva espaço na memória para um novo nó
    struct No *novo = malloc(sizeof(struct No));

    // Coloca o valor recebido dentro do nó
    novo->valor = valor;

    // Inicialmente, o nó não possui filhos
    novo->esquerda = NULL;
    novo->direita = NULL;

    // Retorna o endereço do novo nó
    return novo;
}

int main() {

    // Criando a raiz da árvore
    struct No *raiz = criarNo(10);

    // Criando o filho esquerdo
    raiz->esquerda = criarNo(5);

    // Criando o filho direito
    raiz->direita = criarNo(20);

    // Criando filhos do nó 5
    raiz->esquerda->esquerda = criarNo(3);
    raiz->esquerda->direita = criarNo(7);

    // Criando filhos do nó 20
    raiz->direita->esquerda = criarNo(15);
    raiz->direita->direita = criarNo(30);

    // Resultados
    printf("Raiz: %d\n", raiz->valor);
    printf("Filho esquerdo: %d\n", raiz->esquerda->valor);
    printf("Filho direito: %d\n", raiz->direita->valor);

    printf("\n");

    printf("Filho esquerdo de 5: %d\n",
           raiz->esquerda->esquerda->valor);

    printf("Filho direito de 5: %d\n",
           raiz->esquerda->direita->valor);

    printf("\n");

    printf("Filho esquerdo de 20: %d\n",
           raiz->direita->esquerda->valor);

    printf("Filho direito de 20: %d\n",
           raiz->direita->direita->valor);

    return 0;
}
