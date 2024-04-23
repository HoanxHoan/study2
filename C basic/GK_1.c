#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node {
    int row, col;
};

int isValid(int i, int j, int m, int n, int** matrix, int** visited) {
    return (i >= 0 && i < m && j >= 0 && j < n && !visited[i][j] && matrix[i][j] == 1);
}

int bfs(int** matrix, int m, int n, int i, int j, int** visited) {
    struct Node queue[MAX];
    int front = -1, rear = -1;

    queue[++rear].row = i;
    queue[rear].col = j;
    visited[i][j] = 1;

    int count = 1;

    int rowDir[] = {-1, 1, 0, 0};
    int colDir[] = {0, 0, -1, 1};

    while (front != rear) {
        struct Node current = queue[++front];

        for (int k = 0; k < 4; ++k) {
            int newRow = current.row + rowDir[k];
            int newCol = current.col + colDir[k];

            if (isValid(newRow, newCol, m, n, matrix, visited)) {
                queue[++rear].row = newRow;
                queue[rear].col = newCol;
                visited[newRow][newCol] = 1;
                count++;
            }
        }
    }	

    return count;
}

int findLargestConnectedRegion(int** matrix, int m, int n, int* b, int soPhanTu) {
    int largestRegion = 0;
    int largest = 0;
    int** visited = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i) {
        visited[i] = (int*)calloc(n, sizeof(int));
    }

    for (int x = 0; x < soPhanTu; x++) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == b[x] && !visited[i][j]) {
                    int currentRegionSize = bfs(matrix, m, n, i, j, visited);
                    largestRegion = largestRegion > currentRegionSize ? largestRegion : currentRegionSize;
                }
            }
        }
        if (largestRegion > largest) {
            largest = largestRegion;
        }
    }

    for (int i = 0; i < m; ++i) {
        free(visited[i]);
    }
    free(visited);

    return largest;
}

int daXuatHien(int* mang, int soPhanTu, int giaTri) {
    for (int i = 0; i < soPhanTu; ++i) {
        if (mang[i] == giaTri) {
            return 1;
        }
    }
    return 0;
}

void thongKeVaGan(int** matrix, int m, int n, int* mangKetQua, int* soPhanTu) {
    int* visited = (int*)malloc(m * n * sizeof(int));

    for (int i = 0; i < m * n; ++i) {
        visited[i] = 0;
    }

    *soPhanTu = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i * n + j]) {
                int currentVal = matrix[i][j];

                if (!daXuatHien(mangKetQua, *soPhanTu, currentVal)) {
                    mangKetQua[*soPhanTu] = currentVal;
                    (*soPhanTu)++;
                }

                for (int x = 0; x < m; ++x) {
                    for (int y = 0; y < n; ++y) {
                        if (matrix[x][y] == currentVal) {
                            visited[x * n + y] = 1;
                        }
                    }
                }
            }
        }
    }

    free(visited);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int mangKetQua[m * n];
    int soPhanTu;
    int** a = (int**)malloc(m * sizeof(int*));

    for (int i = 0; i < m; ++i) {
        a[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    thongKeVaGan(a, m, n, mangKetQua, &soPhanTu);
    int result = findLargestConnectedRegion(a, m, n, mangKetQua, soPhanTu);
    printf("%d\n", result);

    for (int i = 0; i < m; ++i) {
        free(a[i]);
    }
    free(a);

    return 0;
}

