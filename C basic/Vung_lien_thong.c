#include <stdio.h>

#define MAX_SIZE 100

int visited[MAX_SIZE][MAX_SIZE];

// Hàm ki?m tra xem m?t ô trong ma tr?n có h?p l? không
int isValid(int row, int col, int m, int n) {
    return (row >= 0 && row < m && col >= 0 && col < n);
}

// Hàm d? quy d? duy?t và d?m s? lu?ng ph?n t? c?a vùng liên thông
int DFS(int matrix[MAX_SIZE][MAX_SIZE], int row, int col, int m, int n) {
    // Ðánh d?u ô dã du?c tham
    visited[row][col] = 1;

    // S? lu?ng ph?n t? trong vùng liên thông
    int count = 1;

    // Các hu?ng k? nhau: trái, ph?i, trên, du?i
    int rowOffset[] = {-1, 0, 1, 0};
    int colOffset[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int newRow = row + rowOffset[i];
        int newCol = col + colOffset[i];

        // Ki?m tra ô k? có h?p l? và chua tham
        if (isValid(newRow, newCol, m, n) && matrix[newRow][newCol] == matrix[row][col] && !visited[newRow][newCol]) {
            // Duy?t d? quy và c?ng vào s? lu?ng ph?n t?
            count += DFS(matrix, newRow, newCol, m, n);
        }
    }

    return count;
}

// Hàm chính d? xác d?nh s? lu?ng ph?n t? c?a vùng liên thông l?n nh?t
int findLargestConnectedRegion(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
    int maxCount = 0;

    // Kh?i t?o m?ng visited
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    // Duy?t qua t?ng ô c?a ma tr?n
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                // N?u ô chua tham, th?c hi?n DFS d? d?m s? lu?ng ph?n t? c?a vùng liên thông
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

    // G?i hàm d? xác d?nh s? lu?ng ph?n t? c?a vùng liên thông l?n nh?t
    int result = findLargestConnectedRegion(matrix, m, n);

    // In k?t qu?
    printf("So luong phan tu cua vung lien thong lon nhat la: %d\n", result);

    return 0;
}


