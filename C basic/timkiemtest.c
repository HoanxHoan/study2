#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    int v[m];
    for (int i = 0; i < m; ++i) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < m; ++i) {
        int found = 0;
        for (int j = 0; j < n; ++j) {
            if (v[i] == a[j]) {
                found = 1;
                break;
            }
        }
        printf("%d\n", found);
    }

    return 0;
}

