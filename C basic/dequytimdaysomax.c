#include <stdio.h>

// H�m d? quy d? t�nh t?ng l?n nh?t c?a b? k s? b?t k?
int findMaxSumRecursion(int n, int k, int list[]) {
    // Tru?ng h?p co b?n: N?u nho hon k, tr? v? -1
    if (n < k) {
        return -1;
    }

    // Tru?ng h?p co b?n: N?u k b?ng 1, tr? v? gi� tr? l?n nh?t trong d�y
    if (k == 1) {
        int max = list[0];
        for (int i = 1; i < n; i++) {
            if (list[i] > max) {
                max = list[i];
            }
        }
        return max;
    }

    // T�nh t?ng l?n nh?t c?a b? k s?, b?ng c�ch so s�nh t?ng l?n nh?t c?a b? k-1 s? v?i s? th? n
    int maxSumWithoutLast = findMaxSumRecursion(n - 1, k, list);
    int maxSumWithLast = findMaxSumRecursion(n - 1, k - 1, list) + list[n - 1];

    // Tr? v? gi� tr? l?n nh?t gi?a hai t?ng tr�n
    return (maxSumWithoutLast > maxSumWithLast) ? maxSumWithoutLast : maxSumWithLast;
}

int main() {
    int n, k;

    scanf("%d %d", &k,&n);
    int list[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    // T�m v� in ra t?ng l?n nh?t c?a b? k s? b?t k? trong d�y n s? s? d?ng d? quy
    int result = findMaxSumRecursion(n, k, list);
    printf("%d\n",result);

    return 0;
}
	
