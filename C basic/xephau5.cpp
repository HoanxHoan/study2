#include <stdio.h>
#include <stdbool.h>

int board[100][100];
int totalSolutions = 0;
bool isSafe(int x, int y,int n) {
    for (int i = 0; i < x; i++) {
        if (board[i][y] == 1) {
            return false;
        }
   }
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = x, j = y; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void countNQueens(int x,int n) {
    if (x == n) {
        totalSolutions++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(x, i,n)) {
            board[x][i] = 1;
            countNQueens(x + 1,n);
            board[x][i] = 0;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    countNQueens(0,n);

    printf("%d\n", totalSolutions);

    return 0;
}

