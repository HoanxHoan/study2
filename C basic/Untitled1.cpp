#include <stdio.h>

// Hàm d? quy d? tính t?ng l?n nh?t c?a b? k s? b?t k? trong m?ng
int findMaxSum(int arr[], int n, int k) {
    // Tru?ng h?p co b?n: N?u s? lu?ng s? k còn l?i ít hon k ho?c k = 0
    if (n < k || k == 0) {
        return 0;
    }

    // Tru?ng h?p 1: Không bao g?m ph?n t? cu?i cùng
    int excludingLast = findMaxSum(arr, n - 1, k);

    // Tru?ng h?p 2: Bao g?m ph?n t? cu?i cùng
    int includingLast = arr[n - 1] + findMaxSum(arr, n - 1, k - 1);

    // Tr? v? t?ng l?n nh?t gi?a tru?ng h?p 1 và tru?ng h?p 2
    return (excludingLast > includingLast) ? excludingLast : includingLast;
}

int main() {
    int n, k;

    // Nh?p s? lu?ng ph?n t? và s? lu?ng ph?n t? c?n tính t?ng
    printf("Nh?p s? lu?ng ph?n t? n: ");
    scanf("%d", &n);
    printf("Nh?p s? lu?ng ph?n t? c?n tính t?ng k: ");
    scanf("%d", &k);

    if (n <= 0 || k <= 0) {
        printf("S? lu?ng ph?n t? và s? lu?ng c?n tính t?ng ph?i l?n hon 0.\n");
        return 1;
    }

    int arr[n];

    // Nh?p dãy n s? nguyên
    printf("Nh?p %d s? nguyên:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // G?i hàm d? quy d? tìm t?ng l?n nh?t
    int result = findMaxSum(arr, n, k);

    // In ra k?t qu?
    printf("T?ng l?n nh?t c?a b? %d s? b?t k? trong dãy là: %d\n", k, result);

    return 0;
}


