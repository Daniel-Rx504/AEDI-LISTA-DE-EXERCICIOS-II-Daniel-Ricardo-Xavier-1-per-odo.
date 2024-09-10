#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tamanho = 50;        
    int notas[tamanho];
    int contador[5] = {0};
    int i;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++) {
        notas[i] = rand() % 5 + 1; 
    }

    for (i = 0; i < tamanho; i++) {
        contador[notas[i] - 1]++; 
    }

    printf("Frequencia de cada nota atribuida:\n");
    for (i = 0; i < 5; i++) {
        printf("Nota %d: %d vezes\n", i + 1, contador[i]);
    }

    printf("\nNotas geradas:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", notas[i]);
    }
    printf("\n");

    return 0;
}
