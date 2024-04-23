#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char code[10];
    int so_luong;
    int gia;
} Product;
void addProduct(Product products[], int *numProducts, char code[], int quantity, int price) {
    int i;
    for (i = 0; i < *numProducts; i++) {
        if (strcmp(products[i].code, code) == 0) {
            products[i].so_luong += quantity;
            printf("%d %d\n", products[i].so_luong, products[i].gia);
            return;
        }
    }
    strcpy(products[*numProducts].code, code);
    products[*numProducts].so_luong = quantity;
    products[*numProducts].gia = (price == -1) ? -1 : price;
    (*numProducts)++;
    
    printf("%d %d\n", quantity, (price == -1) ? -1 : price);
}
void updateProduct(Product products[], int numProducts, char code[], int newPrice) {
    int i;
    for (i = 0; i < numProducts; i++) {
        if (strcmp(products[i].code, code) == 0) {
            printf("%d %d\n", products[i].gia, newPrice);
            products[i].gia = newPrice;
            return;
        }
    }
    printf("San pham khong ton tai\n");
}
void deleteProduct(Product products[], int *numProducts, char code[]) {
    int i;
    for (i = 0; i < *numProducts; i++) {
        if (strcmp(products[i].code, code) == 0) {
            printf("Da xoa san pham\n");
            for (int j = i; j < *numProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            (*numProducts)--;
            return;
        }
    }
    printf("San pham khong ton tai\n");
}
void checkProduct(Product products[], int numProducts, char code[]) {
    int i;
    for (i = 0; i < numProducts; i++) {
        if (strcmp(products[i].code, code) == 0) {
            printf("%d %d\n", products[i].so_luong, products[i].gia);
            return;
        }
    }
    printf("San pham khong ton tai\n");
}
void orderProduct(Product products[], int numProducts, char code[], int quantity) {
    int i;
    for (i = 0; i < numProducts; i++) {
        if (strcmp(products[i].code, code) == 0) {
            if (products[i].so_luong < quantity) {
                printf("Khong du so luong\n");
            } else if (products[i].gia < 0) {
                printf("Khong the dat hang san pham chua co gia\n");
            } else {
                printf("Da dat hang %d %d\n", products[i].so_luong - quantity, quantity * products[i].gia);
                products[i].so_luong -= quantity;
            }
            return;
        }
    }
    printf("San pham khong ton tai\n");
}

int main() {
    int n, m;
    scanf("%d", &n);
    
    Product products[100000];
    int numProducts = n;
    
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", products[i].code, &products[i].so_luong, &products[i].gia);
    }
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        char command[7];
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            char code[10];
            int so_luong;
            scanf("%s %d", code, &so_luong);
            addProduct(products, &numProducts, code, so_luong, -1);
        } else if (strcmp(command, "update") == 0) {
            char code[10];
            int gia;
            scanf("%s %d", code, &gia);
            updateProduct(products, numProducts, code, gia);
        } else if (strcmp(command, "delete") == 0) {
            char code[10];
            scanf("%s", code);
            deleteProduct(products, &numProducts, code);
        } else if (strcmp(command, "check") == 0) {
            char code[10];
            scanf("%s", code);
            checkProduct(products, numProducts, code);
        } else if (strcmp(command, "order") == 0) {
            char code[10];
            int so_luong;
            scanf("%s %d", code, &so_luong);
            orderProduct(products, numProducts, code, so_luong);
        }
    }
    
    return 0;
}
