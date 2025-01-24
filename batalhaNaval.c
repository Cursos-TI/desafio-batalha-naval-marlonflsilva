#include <stdio.h>
#define SIZE 10 // Tamanho do tabuleiro

// Função para inicializar o tabuleiro com zeros
void inicializarTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar navios no tabuleiro
void posicionarNavios(int tabuleiro[SIZE][SIZE]) {
    // Navio horizontal (tamanho 3)
    for (int i = 2; i < 5; i++) {
        tabuleiro[2][i] = 3;
    }

    // Navio vertical (tamanho 3)
    for (int i = 5; i < 8; i++) {
        tabuleiro[i][7] = 3;
    }

    // Navio diagonal (tamanho 3)
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3;
    }

    // Outro navio diagonal (tamanho 3)
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][SIZE - 1 - i] = 3;
    }
}

// Função para aplicar habilidade em formato de cone
void habilidadeCone(int tabuleiro[SIZE][SIZE], int x, int y) {
    if (x >= 1 && y >= 1 && y < SIZE - 1) {
        tabuleiro[x - 1][y] = 1;
        tabuleiro[x][y - 1] = 1;
        tabuleiro[x][y] = 1;
        tabuleiro[x][y + 1] = 1;
        if (x < SIZE - 1) {
            tabuleiro[x + 1][y] = 1;
        }
    }
}

// Função para aplicar habilidade em formato de cruz
void habilidadeCruz(int tabuleiro[SIZE][SIZE], int x, int y) {
    for (int i = 0; i < SIZE; i++) {
        tabuleiro[x][i] = 1;
        tabuleiro[i][y] = 1;
    }
}

// Função para aplicar habilidade em formato de octaedro
void habilidadeOctaedro(int tabuleiro[SIZE][SIZE], int x, int y) {
    if (x >= 1 && x < SIZE - 1 && y >= 1 && y < SIZE - 1) {
        tabuleiro[x][y] = 1;
        tabuleiro[x - 1][y] = 1;
        tabuleiro[x + 1][y] = 1;
        tabuleiro[x][y - 1] = 1;
        tabuleiro[x][y + 1] = 1;
        tabuleiro[x - 1][y - 1] = 1;
        tabuleiro[x - 1][y + 1] = 1;
        tabuleiro[x + 1][y - 1] = 1;
        tabuleiro[x + 1][y + 1] = 1;
    }
}

int main() {
    int tabuleiro[SIZE][SIZE];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios
    posicionarNavios(tabuleiro);

    printf("Tabuleiro inicial com navios:\n");
    exibirTabuleiro(tabuleiro);

    // Aplica habilidades
    printf("\nTabuleiro com habilidade em cone (posição 4,4):\n");
    habilidadeCone(tabuleiro, 4, 4);
    exibirTabuleiro(tabuleiro);

    printf("\nTabuleiro com habilidade em cruz (posição 6,6):\n");
    habilidadeCruz(tabuleiro, 6, 6);
    exibirTabuleiro(tabuleiro);

    printf("\nTabuleiro com habilidade em octaedro (posição 3,3):\n");
    habilidadeOctaedro(tabuleiro, 3, 3);
    exibirTabuleiro(tabuleiro);

    return 0;
}
