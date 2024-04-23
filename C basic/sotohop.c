
#include<stdio.h>
int comb(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return comb(n - 1, k - 1) + comb(n - 1, k);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &k,&n);
    int result = comb(n, k);
    printf("%d\n",result);
    return 0;
}

