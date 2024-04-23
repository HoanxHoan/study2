#include <stdio.h>
#include <stdbool.h>

// So quân hau can xep
#define N 8

// Bàn co quoc te N x N
int board[N][N];

// Hàm de in ra bàn co
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Hàm kiem tra xem có the dat quân hau tai vi trí (row, col) không
bool isSafe(int row, int col) {
    int i, j;

    // Kiem tra hàng ngang bên trái
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return -1;
        }
    }

    // Kiem tra duong chéo trên bên trái
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return -1;
        }
    }

    // Kiem tra duong chéo duoi bên trái
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return -1;
        }
    }

    return 0;
}

// Hàm de quy de giai quyet bài toán N-Queens
bool solveNQueens(int col) {
    // Neu dã dat tat ca quân hau
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solveNQueens(col + 1)) {
                return true;
            }

            board[i][col] = 0; // Neu không tìm duoc giai pháp, tra loi 0 
        }
    }

    return false; // Không tìm thay giai pháp
}

int main() {
    // Khoi tao bàn co voi tat ca ô bang 0
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

