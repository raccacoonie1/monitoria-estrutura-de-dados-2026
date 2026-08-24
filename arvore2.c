#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILHOS 10

// Estrutura de um nó da árvore
struct No {
    char nome[50];

    struct No *filhos[MAX_FILHOS];

    int quantidadeFilhos;
};

// Cria uma nova pasta
struct No* criarNo(char nome[]) {

    struct No *novo = malloc(sizeof(struct No));

    strcpy(novo->nome, nome);

    novo->quantidadeFilhos = 0;

    return novo;
}

// Adiciona uma pasta dentro de outra
void adicionarFilho(struct No *pai, struct No *filho) {

    if (pai->quantidadeFilhos < MAX_FILHOS) {

        pai->filhos[pai->quantidadeFilhos] = filho;

        pai->quantidadeFilhos++;
    }
}

// Mostra a árvore
void mostrarArvore(struct No *no, int nivel) {

    int i;

    // Espaçamento para representar a hierarquia
    for (i = 0; i < nivel; i++) {
        printf("    ");
    }

    printf("|-- %s\n", no->nome);

    // Mostra os filhos
    for (i = 0; i < no->quantidadeFilhos; i++) {

        mostrarArvore(no->filhos[i], nivel + 1);
    }
}

int main() {

    // Criando as pastas
    struct No *computador = criarNo("Computador");

    struct No *documentos = criarNo("Documentos");
    struct No *downloads = criarNo("Downloads");
    struct No *imagens = criarNo("Imagens");

    struct No *faculdade = criarNo("Faculdade");
    struct No *trabalho = criarNo("Trabalho");
    struct No *projetos = criarNo("Projetos");

    struct No *programas = criarNo("Programas");
    struct No *arquivos = criarNo("Arquivos");

    struct No *viagens = criarNo("Viagens");
    struct No *familia = criarNo("Familia");

    // Montando a árvore
    adicionarFilho(computador, documentos);
    adicionarFilho(computador, downloads);
    adicionarFilho(computador, imagens);

    adicionarFilho(documentos, faculdade);
    adicionarFilho(documentos, trabalho);
    adicionarFilho(documentos, projetos);

    adicionarFilho(downloads, programas);
    adicionarFilho(downloads, arquivos);

    adicionarFilho(imagens, viagens);
    adicionarFilho(imagens, familia);

    // Mostrando a árvore
    printf("ESTRUTURA DE PASTAS\n\n");

    mostrarArvore(computador, 0);

    return 0;
}
