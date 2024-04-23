#include <stdio.h>
#include <stdbool.h>

// So qu�n hau can xep
#define N 8

// B�n co quoc te N x N
int board[N][N];

// H�m de in ra b�n co
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// H�m kiem tra xem c� the dat qu�n hau tai vi tr� (row, col) kh�ng
bool isSafe(int row, int col) {
    int i, j;

    // Kiem tra h�ng ngang b�n tr�i
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return -1;
        }
    }

    // Kiem tra duong ch�o tr�n b�n tr�i
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return -1;
        }
    }

    // Kiem tra duong ch�o duoi b�n tr�i
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return -1;
        }
    }

    return 0;
}

// H�m de quy de giai quyet b�i to�n N-Queens
bool solveNQueens(int col) {
    // Neu d� dat tat ca qu�n hau
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solveNQueens(col + 1)) {
                return true;
            }

            board[i][col] = 0; // Neu kh�ng t�m duoc giai ph�p, tra loi 0 
        }
    }

    return false; // Kh�ng t�m thay giai ph�p
}

int main() {
    // Khoi tao b�n co voi tat ca � bang 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQueens(0)) {
        printBoard();
    } else {
        printf("-1");
    }

    return 0;
}

