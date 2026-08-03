#include <stdio.h>

int buscaInterpolacao(int vetor[], int tamanho, int valor)
{
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim &&
           valor >= vetor[inicio] &&
           valor <= vetor[fim])
    {
        // Evita divisão por zero caso todos os valores sejam iguais
        if (vetor[inicio] == vetor[fim])
        {
            if (vetor[inicio] == valor)
                return inicio;
            else
                return -1;
        }

        // Calcula a posição estimada
        int pos = inicio +
                  ((valor - vetor[inicio]) * (fim - inicio))
                  / (vetor[fim] - vetor[inicio]);

        // Encontrou o valor
        if (vetor[pos] == valor)
            return pos;

        // Continua procurando na metade adequada
        if (vetor[pos] < valor)
            inicio = pos + 1;
        else
            fim = pos - 1;
    }

    return -1;
}

int main()
{
    int vetor[] = {10,20,30,40,50,60,70,80,90,100,
                   110,120,130,140,150,160,170,180,190,200};

    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor;

    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &valor);

    int posicao = buscaInterpolacao(vetor, tamanho, valor);

    if (posicao != -1)
        printf("Valor encontrado na posicao %d.\n", posicao);
    else
        printf("Valor nao encontrado.\n");

    return 0;
}
