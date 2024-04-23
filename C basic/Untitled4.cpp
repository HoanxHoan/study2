#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int chessboard[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &chessboard[i][j]);
        }
    }
    int isAttacking = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chessboard[i][j] == 1) {
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (chessboard[k][l] == 1 && (k != i || l != j)) {
                            if (i == k || j == l || i - j == k - l || i + j == k + l) {
                                isAttacking = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    // In k?t qu?
    if (isAttacking) {
        printf("0\n"); 
    } else {
        printf("1\n"); 
    }

    return 0;
}

