#include <stdio.h>

typedef struct{
    int codigo;
    char nome[30];
    float preco;
} Produto;

int buscaSequencial(Produto produtos[], int tamanho, int codigo){

    for(int i = 0; i < tamanho; i++){
        if(produtos[i].codigo == codigo)
            return i;
    }

    return -1;
}

int main(){

    Produto produtos[] = {
        {310, "Monitor", 999.90},
        {101, "Mouse", 89.90},
        {520, "Notebook", 3599.90},
        {205, "Teclado", 149.90},
        {412, "Headset", 249.90}
    };

    int codigo;

    printf("===== BUSCA SEQUENCIAL =====\n\n");

    printf("Insira o codigo do produto desejado: ");
    scanf("%d", &codigo);

    int pos = buscaSequencial(produtos, 5, codigo);

    if(pos != -1){
        printf("\nProduto encontrado!\n");
        printf("Codigo: %d\n", produtos[pos].codigo);
        printf("Nome: %s\n", produtos[pos].nome);
        printf("Preco: R$ %.2f\n", produtos[pos].preco);
    }
    else{
        printf("\nProduto nao encontrado.\n");
    }

    printf("\nPressione ENTER para sair...");
    getchar(); // limpa o ENTER do scanf
    getchar(); // espera o usuário pressionar ENTER

    return 0;
}
