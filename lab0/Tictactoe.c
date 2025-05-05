#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length) {
    printf("\t");
    for (int i=0; i < length; i++) printf("................");
    printf("\n");
}

void print_board(char board[3][3]) {
    int cell = 0;
    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

char get_winner(char board[3][3]) {
    char winner = '-';
    for (int i = 0; i < 3; ++i) {
        //Fila//
        char primerf = board[i][0];
        if (primerf != '-') {
            bool iguales = true;
            int j = 1;
            while (iguales && j < 3) {
                char actual = board[i][j];
                if (primerf != actual) {
                    iguales = false;
                }
                j++;
            }
            if (iguales) {
                winner = primerf;
                break;
            }
        }
        //Columna//
        char primerc = board[0][i];
        if (primerc != '-') {
            bool iguales = true;
            int j = 1;
            while (iguales && j < 3) {
                char actual = board[j][i];
                if (primerc != actual) {
                    iguales = false;
                }
                j++;
            }
            if (iguales) {
                winner = primerc;
                break;
            }
        }
    }
    //Diagonal principal//
    if (winner == '-') {
        char primerd = board[0][0];
        if (primerd != '-') {
            bool iguales = true;
            int j = 1;
            while (iguales && j < 3) {
                char actual = board[j][j];
                if (primerd != actual) {
                iguales = false;
                }
                j++;
            }
            if (iguales) {
                winner = primerd;
            }
        }
    }
    //Diagonal secundaria//
    if (winner == '-') {
        char primerds = board[0][3-1];
        if (primerds != '-') {
            bool iguales = true;
            int j = 3-2;
            int i = 1;
            while (iguales && j >= 0 && i < 3) {
                char actual = board[i][j];
                if (primerds != actual) {
                iguales = false;
                }
                j--;
                i++;
            }
            if (iguales) {
                winner = primerds;
            }
        }
    }    
    return winner; 
} 

bool has_free_cell(char board[3][3]) {
    bool free_cell = false;
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            if (board[row][column] == '-') {
                free_cell = true;
                break;
            }
        }
    }    
    return free_cell;
}

int main(void) {
    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };
    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posicion (numero del 0 al %d):", turn, CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un numero desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } 
            else {
                printf("\nCelda ocupada!\n");
            }
        }
        else {
            printf("\nCelda invalida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Gano %c!\n", winner);
    }
    return 0;
}
