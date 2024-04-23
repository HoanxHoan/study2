#include <stdio.h>

#define MAX_SIZE 100

int visited[MAX_SIZE][MAX_SIZE];

// H�m ki?m tra xem m?t � trong ma tr?n c� h?p l? kh�ng
int isValid(int row, int col, int m, int n) {
    return (row >= 0 && row < m && col >= 0 && col < n);
}

// H�m d? quy d? duy?t v� d?m s? lu?ng ph?n t? c?a v�ng li�n th�ng
int DFS(int matrix[MAX_SIZE][MAX_SIZE], int row, int col, int m, int n) {
    // ��nh d?u � d� du?c tham
    visited[row][col] = 1;

    // S? lu?ng ph?n t? trong v�ng li�n th�ng
    int count = 1;

    // C�c hu?ng k? nhau: tr�i, ph?i, tr�n, du?i
    int rowOffset[] = {-1, 0, 1, 0};
    int colOffset[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int newRow = row + rowOffset[i];
        int newCol = col + colOffset[i];

        // Ki?m tra � k? c� h?p l? v� chua tham
        if (isValid(newRow, newCol, m, n) && matrix[newRow][newCol] == matrix[row][col] && !visited[newRow][newCol]) {
            // Duy?t d? quy v� c?ng v�o s? lu?ng ph?n t?
            count += DFS(matrix, newRow, newCol, m, n);
        }
    }

    return count;
}

// H�m ch�nh d? x�c d?nh s? lu?ng ph?n t? c?a v�ng li�n th�ng l?n nh?t
int findLargestConnectedRegion(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
    int maxCount = 0;

    // Kh?i t?o m?ng visited
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    // Duy?t qua t?ng � c?a ma tr?n
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                // N?u � chua tham, th?c hi?n DFS d? d?m s? lu?ng ph?n t? c?a v�ng li�n th�ng
                int currentCount = DFS(matrix, i, j, m, n);

                // C?p nh?t s? lu?ng ph?n t? l?n nh?t
                if (currentCount > maxCount) {
                    maxCount = currentCount;
                }
            }
        }
    }

    return maxCount;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // G?i h�m d? x�c d?nh s? lu?ng ph?n t? c?a v�ng li�n th�ng l?n nh?t
    int result = findLargestConnectedRegion(matrix, m, n);

    // In k?t qu?
    printf("So luong phan tu cua vung lien thong lon nhat la: %d\n", result);

    return 0;
}


