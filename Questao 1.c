#include <stdio.h>
#include <string.h>

int main() {
    char palavra[11], progresso[11], letra;
    int vidas, acertos = 0;
    int tamanho, i;

    printf("Digite a palavra secreta max 10 letras: ");
    scanf("%10s", palavra);

    tamanho = strlen(palavra);  
    vidas = tamanho + 2;  
    memset(progresso, '_', tamanho); 
    progresso[tamanho] = '\0'; 

    while (vidas > 0 && acertos < tamanho) {
        int encontrou = 0; 
        printf("\nPalavra: %s  Vidas: %d\nLetra: ", progresso, vidas);
        scanf(" %c", &letra);

        if ((letra < 'A' || letra > 'Z') && (letra < 'a' || letra > 'z')) {
            printf("Por favor, insira uma letra válida.\n");
            continue; 
        }

        if (letra >= 'A' && letra <= 'Z') {
            letra += 'a' - 'A';
        }

        for (i = 0; i < tamanho; i++) {
            char letra_palavra = palavra[i];

            if (letra_palavra >= 'A' && letra_palavra <= 'Z') {
                letra_palavra += 'a' - 'A';
            }

            if (letra_palavra == letra && progresso[i] == '_') {
                progresso[i] = palavra[i]; 
                printf("Letra '%c' encontrada na posição %d.\n", letra, i+1);
                acertos++;
                encontrou = 1;
            }
        }

        if (!encontrou) {
            vidas--;  
            printf("Letra '%c' não encontrada. Vidas restantes: %d.\n", letra, vidas);
        }
    }

    if (acertos == tamanho) {
        printf("\nVocê Acertou! A palavra era: %s\n", palavra);
    } else {
        printf("\nVocê Errou! A palavra era: %s\n", palavra);
    }

    return 0;
}
