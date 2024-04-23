#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100
#define MAXM 100
#define INF 999999

// Ðinh nghia mot cau trúc cho diem (ô) trong ma tran
typedef struct {
    int x, y;
} Point;

// Ðinh nghia mot cau trúc cho nút trong hàng doi uu tiên
typedef struct {
    Point p;
    int distance;
} Node;

int n, m; // Kích thuoc cua ma tran
int maze[MAXN][MAXM]; // Ma tran mê cung
int dist[MAXN][MAXM]; // Ma tran luu khoang cách toi tung ô
bool visited[MAXN][MAXM]; // Ma tran luu trang thái dã tham cua tung ô

// Hàm kiem tra xem mot ô có nam trong mê cung không
bool isValid(Point p) {
    return (p.x >= 0 && p.x < n && p.y >= 0 && p.y < m);
}

// Hàm kiem tra xem mot ô có the di chuyen den không
bool isWalkable(Point p) {
    return (isValid(p) && maze[p.x][p.y] == 0);
}

// Hàm tìm duong di ngan nhat tu (i0, j0) den dích (i1, j1) bang thuat toán Dijkstra
int shortestPath(Point start, Point destination) {
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // Khoi tao ma tran khoang cách
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = INF;
            visited[i][j] = false;
        }
    }

    // Khoi tao diem bat dau và diem dích
    Point src = start;
    Point dest = destination;

    dist[src.x][src.y] = 0;

    // Tao hàng doi uu tiên luu trong thái cua các ô
    Node queue[MAXN * MAXM];
    int front = -1, rear = -1;

    // Thêm diem bat dau vào hàng doi
    queue[++rear].p = src;
    queue[rear].distance = 0;

    while (front != rear) {
        Node current = queue[++front];

        // Ðã toi dích
        if (current.p.x == dest.x && current.p.y == dest.y) {
            return dist[dest.x][dest.y];
        }

        // Duyet các ô lân can
        for (int i = 0; i < 4; i++) {
            Point neighbor;
            neighbor.x = current.p.x + dx[i];
            neighbor.y = current.p.y + dy[i];

            // Kiem tra xem ô lân can có hop le không
            if (isWalkable(neighbor) && !visited[neighbor.x][neighbor.y]) {
                // Neu khoang cách moi ngan hon thì cap nhat khoang cách và thêm vào hàng doi
                if (dist[current.p.x][current.p.y] + 1 < dist[neighbor.x][neighbor.y]) {
                    dist[neighbor.x][neighbor.y] = dist[current.p.x][current.p.y] + 1;
                    queue[++rear].p = neighbor;
                    queue[rear].distance = dist[neighbor.x][neighbor.y];
                    visited[neighbor.x][neighbor.y] = true;
                }
            }
        }
    }

    // Neu không tìm thay duong di
    return -1;
}

int main() {
    Point start, destination;
    scanf("%d %d %d %d", &n, &m, &start.x, &start.y);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    scanf("%d %d", &destination.x, &destination.y);
    
    int shortest = shortestPath(start, destination);

    if (shortest != -1) {
        printf("%d\n", shortest);
    }
    return 0;
}

