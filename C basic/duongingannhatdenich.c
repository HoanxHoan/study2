#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100
#define MAXM 100
#define INF 999999

// �inh nghia mot cau tr�c cho diem (�) trong ma tran
typedef struct {
    int x, y;
} Point;

// �inh nghia mot cau tr�c cho n�t trong h�ng doi uu ti�n
typedef struct {
    Point p;
    int distance;
} Node;

int n, m; // K�ch thuoc cua ma tran
int maze[MAXN][MAXM]; // Ma tran m� cung
int dist[MAXN][MAXM]; // Ma tran luu khoang c�ch toi tung �
bool visited[MAXN][MAXM]; // Ma tran luu trang th�i d� tham cua tung �

// H�m kiem tra xem mot � c� nam trong m� cung kh�ng
bool isValid(Point p) {
    return (p.x >= 0 && p.x < n && p.y >= 0 && p.y < m);
}

// H�m kiem tra xem mot � c� the di chuyen den kh�ng
bool isWalkable(Point p) {
    return (isValid(p) && maze[p.x][p.y] == 0);
}

// H�m t�m duong di ngan nhat tu (i0, j0) den d�ch (i1, j1) bang thuat to�n Dijkstra
int shortestPath(Point start, Point destination) {
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // Khoi tao ma tran khoang c�ch
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = INF;
            visited[i][j] = false;
        }
    }

    // Khoi tao diem bat dau v� diem d�ch
    Point src = start;
    Point dest = destination;

    dist[src.x][src.y] = 0;

    // Tao h�ng doi uu ti�n luu trong th�i cua c�c �
    Node queue[MAXN * MAXM];
    int front = -1, rear = -1;

    // Th�m diem bat dau v�o h�ng doi
    queue[++rear].p = src;
    queue[rear].distance = 0;

    while (front != rear) {
        Node current = queue[++front];

        // �� toi d�ch
        if (current.p.x == dest.x && current.p.y == dest.y) {
            return dist[dest.x][dest.y];
        }

        // Duyet c�c � l�n can
        for (int i = 0; i < 4; i++) {
            Point neighbor;
            neighbor.x = current.p.x + dx[i];
            neighbor.y = current.p.y + dy[i];

            // Kiem tra xem � l�n can c� hop le kh�ng
            if (isWalkable(neighbor) && !visited[neighbor.x][neighbor.y]) {
                // Neu khoang c�ch moi ngan hon th� cap nhat khoang c�ch v� th�m v�o h�ng doi
                if (dist[current.p.x][current.p.y] + 1 < dist[neighbor.x][neighbor.y]) {
                    dist[neighbor.x][neighbor.y] = dist[current.p.x][current.p.y] + 1;
                    queue[++rear].p = neighbor;
                    queue[rear].distance = dist[neighbor.x][neighbor.y];
                    visited[neighbor.x][neighbor.y] = true;
                }
            }
        }
    }

    // Neu kh�ng t�m thay duong di
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

