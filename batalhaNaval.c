#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NUMERO_AGUA 0
#define NUMERO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // criação do tabuleiro

    int linhaHorizontal = 2; // posicionamento primeiro navio na horizontal
    int colunaHorizontal = 4; // posicionamento primeiro navio na horizontal

    int linhaVertical = 5; // posicionamento navio na vertical
    int colunaVertical = 1; // posicionamento navio na vertical


    // Condicional para checar se o navio ultrapassa o tabuleiro horizontalmente
    if(colunaHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Condicional para checar se o navio ultrapassa o tabuleiro verticalmente
    if(colunaVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }





    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        // verificando se já existe um navio naquela posição do tabuleiro
        if(tabuleiro[linhaHorizontal][colunaHorizontal + i] == NUMERO_NAVIO ) {
            printf("Erro: Sobreposição detectada no navio horizontal.\n");
            return 1;
        }
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = NUMERO_NAVIO; // coloca o navio nessa posição do tabuleiro
    }


     for(int i = 0; i < TAMANHO_NAVIO; i++) {
        // verificando se já existe um navio naquela posição do tabuleiro
        if(tabuleiro[linhaVertical + i][colunaVertical] == NUMERO_NAVIO ) {
            printf("Erro: Sobreposição detectada no navio vertical.\n");
            return 1;
        }
        tabuleiro[linhaVertical + i][colunaVertical] = NUMERO_NAVIO; // coloca o navio nessa posição do tabuleiro
    }
    // Exibição do tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n\n");
    for(int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for(int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}
