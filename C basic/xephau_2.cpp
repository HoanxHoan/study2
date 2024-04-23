#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // Khai báo và d?c ma tr?n bàn c?
    int chessboard[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &chessboard[i][j]);
        }
    }

    int isAttacking = 0; // Bi?n ki?m tra có h?u nào an nhau không

    // Duy?t qua t?ng ô trên bàn c?
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chessboard[i][j] == 1) {
                // N?u tìm th?y quân h?u, ki?m tra xem có h?u nào an nhau không
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (chessboard[k][l] == 1 && (k != i || l != j)) {
                            // N?u tìm th?y quân h?u khác và chúng an nhau, d?t bi?n isAttacking thành 1
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
        printf("0\n"); // Có 2 quân h?u an nhau
    } else {
        printf("1\n"); // Không có quân h?u nào an nhau
    }

    return 0;
}

