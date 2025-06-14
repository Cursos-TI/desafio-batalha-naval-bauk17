#include <stdio.h>
#include <stdlib.h> // para acessar a função abs()

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NUMERO_AGUA 0
#define NUMERO_NAVIO 3
#define NUMERO_HABILIDADE 5
#define TAMANHO_HABILIDADE 5 // matriz 5x5 para representar as habilidades

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função que aplica a matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemLinha, int origemColuna) {
    int offset = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Cálculo da posição no tabuleiro com base na origem central
            int linhaTab = origemLinha - offset + i;
            int colunaTab = origemColuna - offset + j;

            // Garante que não acesse posições fora do tabuleiro
            if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO &&
                habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == NUMERO_AGUA) {
                tabuleiro[linhaTab][colunaTab] = NUMERO_HABILIDADE;
            }
        }
    }
}

// Cria a habilidade: Cone
void criarCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (abs(j - 2) <= i) ? 1 : 0;
        }
    }
}

// Cria a habilidade: Cruz
void criarCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (i == 2 || j == 2) ? 1 : 0;
        }
    }
}

// Cria a habilidade: Octaedro
void criarOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (abs(i - 2) + abs(j - 2) <= 2) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa todas as posições do tabuleiro com água

    // Posionamento do primeiro navio na horizontal
    int linhaHorizontal = 2; 
    int colunaHorizontal = 4;

    // Posicionamento do navio na vertical
    int linhaVertical = 5;
    int colunaVertical = 1;

    // Verificações de limites dos navios
    if (colunaHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        linhaVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Um dos navios ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Posiciona navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaHorizontal][colunaHorizontal + i] == NUMERO_NAVIO) {
            printf("Erro: Sobreposição detectada no navio horizontal.\n");
            return 1;
        }
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = NUMERO_NAVIO;
    }

    // Posiciona navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaVertical + i][colunaVertical] == NUMERO_NAVIO) {
            printf("Erro: Sobreposição detectada no navio vertical.\n");
            return 1;
        }
        tabuleiro[linhaVertical + i][colunaVertical] = NUMERO_NAVIO;
    }

    // Posiciona navio na diagonal principal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[6 + i][6 + i] == NUMERO_NAVIO) {
            printf("Erro: Sobreposição detectada na diagonal principal.\n");
            return 1;
        }
        tabuleiro[6 + i][6 + i] = NUMERO_NAVIO;
    }

    // Posiciona navio na diagonal secundária
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[2 - i][2 - i] == NUMERO_NAVIO) {
            printf("Erro: Sobreposição detectada na diagonal secundária.\n");
            return 1;
        }
        tabuleiro[2 - i][2 - i] = NUMERO_NAVIO;
    }

    // Criação das matrizes de habilidades
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarCone(cone); // chamando as funções das respectivas habilidades e passando as variáveis declaradas acima como parâmetro
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicando habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 1, 5);      // cone apontando para baixo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // cruz no meio do tabuleiro
    aplicarHabilidade(tabuleiro, octaedro, 8, 2);  // octaedro na parte inferior

    // Exibição do tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
