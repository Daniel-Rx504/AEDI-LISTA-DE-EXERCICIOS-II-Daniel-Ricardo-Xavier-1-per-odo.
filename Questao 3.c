#include <stdio.h>

#define NUM_CONTAS 100

int busca_binaria(int contas[], int tamanho, int conta_buscada, int *comparacoes) {
    int esquerda = 0, direita = tamanho - 1;
    *comparacoes = 0;
    while (esquerda <= direita) {
        (*comparacoes)++;
        int meio = (esquerda + direita) / 2;
        if (contas[meio] == conta_buscada) return meio;
        if (conta_buscada < contas[meio]) direita = meio - 1;
        else esquerda = meio + 1;
    }
    return -1;
}

int main() {
    int contas[NUM_CONTAS];
    for (int i = 0; i < NUM_CONTAS; i++) contas[i] = i + 1;

    int conta_buscada, comparacoes;
    printf("Informe o numero da conta a ser buscada 1 a 100: ");
    scanf("%d", &conta_buscada);

    int resultado = busca_binaria(contas, NUM_CONTAS, conta_buscada, &comparacoes);
    if (resultado != -1) printf("Conta %d encontrada na posicao %d.\n", conta_buscada, resultado);
    else printf("Conta %d nao encontrada.\n", conta_buscada);

    printf("Numero de comparacoes realizadas: %d\n", comparacoes);
    return 0;
}
