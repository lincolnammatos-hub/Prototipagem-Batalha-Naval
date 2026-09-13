# Prototipagem-Batalha-Naval

#include <stdio.h>
#include <stdlib.h>

//DEFINE AS FUNÇOES

#define SIZE 10
#define NAVIO 3
#define TAMANHO_COORDENADA 3

//FUNÇAO QUE NAO VAI DEVOLVER NADA

void inicializarTabuleiro (char board[SIZE][SIZE]);
void criarCoordenada (char coordenada[SIZE][SIZE][TAMANHO_COORDENADA]);
void posicionarNavio (char navio[SIZE][SIZE]);
void mostrarTabuleiro (char board[SIZE][SIZE], char coordenadas[SIZE][SIZE][TAMANHO_COORDENADA]);
int posicaoValida (int linhas, int colunas);
void atacar (char board[SIZE][SIZE], char navio[SIZE][SIZE], int linhas, int colunas);

//INT MAIN AQUI

int main(void) {
    char tabuleiro[SIZE][SIZE];
    char coordenadas[SIZE][SIZE][TAMANHO_COORDENADA];

    inicializarTabuleiro(tabuleiro);
    criarCoordenada(coordenadas);
    posicionarNavio(tabuleiro);
    mostrarTabuleiro(tabuleiro, coordenadas);

    return 0;
}


//AQUI EXECUTA OQ FIZ NO PROTOTIPO "NO RASCUNHO"

void inicializarTabuleiro (char board[SIZE][SIZE])
{
    for (register int i = 0; i < SIZE; ++i)
    {
        for (register int j = 0; j < SIZE; ++j) {
            board[i][j] = 'O';
        }
    }
}

void criarCoordenada (char board[SIZE][SIZE][TAMANHO_COORDENADA])
{
    for (register int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j][0] = '-';
        }
    }
}

void posicionarNavio (char navio[SIZE][SIZE])
{
    int colocados = 0;
    while (colocados < NAVIO) {
        int i = rand() % SIZE;
        int j = rand() % SIZE;

        if (navio[i][j] == 'O')
        {
            navio[i][j] = 'H';
            colocados++;
        }
    }
}

void mostrarTabuleiro (char board[SIZE][SIZE], char coordenadas[SIZE][SIZE][TAMANHO_COORDENADA])
{
    for (register int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j) {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }
}

void atacar (char board[SIZE][SIZE], char navio[SIZE][SIZE], int linhas, int colunas)
{
    if (!posicaoValida(linhas, colunas)) {
        printf("Posicao Invalida!\n");
        return;
    }
    if (navio[linhas][colunas] == 'H') {
        board[linhas][colunas] = 'X';
        printf("Acertou!\n");
    } else {
        board[linhas][colunas] = 'O';
        printf("Errou!\n");
    }
}

int posicaoValida (int linhas, int colunas)
{
    return (linhas >= 0 && linhas < SIZE && colunas >= 0 && colunas < SIZE);
}
