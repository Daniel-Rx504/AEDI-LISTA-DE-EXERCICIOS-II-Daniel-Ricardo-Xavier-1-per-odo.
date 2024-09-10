#include <stdio.h>

#define TAMANHO_PRIMOS 25

int busca_binaria(int array[], int tamanho, int valor, int *comparacoes) {
    int esquerda = 0, direita = tamanho - 1;
    *comparacoes = 0;
    
    while (esquerda <= direita) {
        (*comparacoes)++;
        int meio = (esquerda + direita) / 2;
        
        if (array[meio] == valor) return meio;
        if (array[meio] < valor) esquerda = meio + 1;
        else direita = meio - 1;
    }
    return -1;
}

int main() {
    int primos[TAMANHO_PRIMOS] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
                                   31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
                                   73, 79, 83, 89, 97};

    int numero, comparacoes;

    printf("Digite um numero de 1 a 100: ");
    scanf("%d", &numero);

    int resultado = busca_binaria(primos, TAMANHO_PRIMOS, numero, &comparacoes);

    if (resultado != -1) 
        printf("Numero %d encontrado na posicao %d.\n", numero, resultado);
    else 
        printf("Numero %d nao encontrado.\n", numero);

    printf("Comparacoes realizadas: %d\n", comparacoes);

    return 0;
}
