#include <stdio.h>

// H�m d? quy d? t�nh t?ng l?n nh?t c?a b? k s? b?t k? trong m?ng
int findMaxSum(int arr[], int n, int k) {
    // Tru?ng h?p co b?n: N?u s? lu?ng s? k c�n l?i �t hon k ho?c k = 0
    if (n < k || k == 0) {
        return 0;
    }

    // Tru?ng h?p 1: Kh�ng bao g?m ph?n t? cu?i c�ng
    int excludingLast = findMaxSum(arr, n - 1, k);

    // Tru?ng h?p 2: Bao g?m ph?n t? cu?i c�ng
    int includingLast = arr[n - 1] + findMaxSum(arr, n - 1, k - 1);

    // Tr? v? t?ng l?n nh?t gi?a tru?ng h?p 1 v� tru?ng h?p 2
    return (excludingLast > includingLast) ? excludingLast : includingLast;
}

int main() {
    int n, k;

    // Nh?p s? lu?ng ph?n t? v� s? lu?ng ph?n t? c?n t�nh t?ng
    printf("Nh?p s? lu?ng ph?n t? n: ");
    scanf("%d", &n);
    printf("Nh?p s? lu?ng ph?n t? c?n t�nh t?ng k: ");
    scanf("%d", &k);

    if (n <= 0 || k <= 0) {
        printf("S? lu?ng ph?n t? v� s? lu?ng c?n t�nh t?ng ph?i l?n hon 0.\n");
        return 1;
    }

    int arr[n];

    // Nh?p d�y n s? nguy�n
    printf("Nh?p %d s? nguy�n:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // G?i h�m d? quy d? t�m t?ng l?n nh?t
    int result = findMaxSum(arr, n, k);

    // In ra k?t qu?
    printf("T?ng l?n nh?t c?a b? %d s? b?t k? trong d�y l�: %d\n", k, result);

    return 0;
}


