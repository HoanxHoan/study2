#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char code[10];
    int so_luong;
    int gia ;
    struct Node* left;
    struct Node* right;
} Node;

typedef Node* BST;

Node* createNode(char code[], int so_luong, int gia) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->code, code);
    newNode->so_luong = so_luong;
    newNode->gia = gia;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void addProduct_BST(BST* root, char code[], int so_luong, int gia) {
    if (*root == NULL) {
        *root = createNode(code, so_luong, gia);
    } else {
        if (strcmp(code, (*root)->code) < 0) {
            addProduct_BST(&((*root)->left), code, so_luong, gia);
        } else if (strcmp(code, (*root)->code) > 0) {
            addProduct_BST(&((*root)->right), code, so_luong, gia);
        } else {
            (*root)->so_luong += so_luong;
            printf("%d %d\n", (*root)->so_luong, (*root)->gia);
        }
    }
}
void add_so_luong(BST* root, char code[], int so_luong) {
    if (*root == NULL) {
        addProduct_BST(root, code, so_luong, -1);
        printf("%d %d\n",(*root)->so_luong, (*root)->gia);
    } else {
        if (strcmp(code, (*root)->code) < 0) {
            add_so_luong(&((*root)->left), code, so_luong);
        } else if (strcmp(code, (*root)->code) > 0) {
            add_so_luong(&((*root)->right), code, so_luong);
        } else {
            (*root)->so_luong += so_luong;
            printf("%d %d\n", (*root)->so_luong, (*root)->gia);
        }
    }
}
void updateProduct_BST(BST* root, char code[], int newPrice) {
    if (*root == NULL) {
        printf("San pham khong ton tai\n");
    } else {
        if (strcmp(code, (*root)->code) < 0) {
            updateProduct_BST(&((*root)->left), code, newPrice);
        } else if (strcmp(code,(*root)->code) > 0) {
            updateProduct_BST(&((*root)->right), code, newPrice);
        } else {
            printf("%d %d\n", (*root)->gia, newPrice);
            (*root)->gia = newPrice;
        }
    }
}

int main() {
    int n, m;
    scanf("%d", &n);

    BST root = NULL;

    for (int i = 0; i < n; i++) {
        char code[10];
        int so_luong, gia;
        scanf("%s %d %d", code, &so_luong, &gia);
        addProduct_BST(&root, code, so_luong, gia);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        char command[7];
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            char code[10];
            int so_luong;
            scanf("%s %d", code, &so_luong);
            add_so_luong(&root,code,so_luong);
    } else if (strcmp(command, "update") == 0) {
            char code[10];
            int gia;
            scanf("%s %d", code, &gia);
            updateProduct_BST(&root, code, gia);
    }
 }
    return 0;
}

