#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // Khai b�o v� d?c ma tr?n b�n c?
    int chessboard[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &chessboard[i][j]);
        }
    }

    int isAttacking = 0; // Bi?n ki?m tra c� h?u n�o an nhau kh�ng

    // Duy?t qua t?ng � tr�n b�n c?
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chessboard[i][j] == 1) {
                // N?u t�m th?y qu�n h?u, ki?m tra xem c� h?u n�o an nhau kh�ng
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (chessboard[k][l] == 1 && (k != i || l != j)) {
                            // N?u t�m th?y qu�n h?u kh�c v� ch�ng an nhau, d?t bi?n isAttacking th�nh 1
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
        printf("0\n"); // C� 2 qu�n h?u an nhau
    } else {
        printf("1\n"); // Kh�ng c� qu�n h?u n�o an nhau
    }

    return 0;
}

