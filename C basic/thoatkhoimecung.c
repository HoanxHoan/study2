#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

// H�m kiem tra xem mot diem c� hop le trong m� cung kh�ng
int is_valid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// H�m t�m so buoc toi thieu de tho�t khoi m� cung
int find_minimum_steps(int n, int m, int r, int c, int maze[n][m]) {
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    // Tao mot ma tran visited de d�nh dau c�c � d� duoc duyet
    int visited[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }

    // Khoi tao h�ng doi 
    Point queue[n*m];
    int front = 0, rear = 0;

    // Bat dau tu � xuat ph�t
    queue[rear].x = r;
    queue[rear].y = c;
    rear++;
    visited[r][c] = 1;

    while (front < rear) {
        // Lay diem hien tai tu h�ng doi
        int x = queue[front].x;
        int y = queue[front].y;
        front++;

        // Kiem tra xem d� tho�t khoi m� cung chua
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            return visited[x][y] - 1; // So buoc toi thieu l� so luot duyet - 1
        }

        // Duyet c�c � l�n can
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            // Kiem tra xem � l�n can c� hop le v� chua duoc duyet
            if (is_valid(new_x, new_y, n, m) && maze[new_x][new_y] == 0 && !visited[new_x][new_y]) {
                // Th�m � l�n can v�o h�ng doi
                queue[rear].x = new_x;
                queue[rear].y = new_y;
                rear++;
                visited[new_x][new_y] = visited[x][y] + 1;
            }
        }
    }
free(queue);
free(visited);
   
    return -1;
}

int main() {
    int n, m, r, c;
    scanf("%d %d %d %d", &n, &m, &r, &c);

    int maze[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    int minimum_steps = find_minimum_steps(n, m, r, c, maze);
    if (minimum_steps == -1) {
        printf("Khong the thoat ra khoi me cung.\n");
    } else {
        printf("%d\n", minimum_steps);
    }

    return 0;
}

