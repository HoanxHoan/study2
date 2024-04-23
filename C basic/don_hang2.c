#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    char CustomerID[10];
    char ProductID[10];
    char ShopID[10];
    int gia ;
    int h;
    int m;
    int s;
    struct Node* left;
    struct Node* right;
} Node;

typedef Node* BST;

Node* createNode(char CustomerID[], char ProductID[] ,char ShopID[] ,int gia,int h,int m,int s) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->CustomerID, CustomerID);
    strcpy(newNode->ProductID, ProductID);
    strcpy(newNode->ShopID, ShopID);
    newNode->gia = gia;
    newNode->h = h;
    newNode->m = m;
    newNode->s = s;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void add(BST* root,char CustomerID[], char ProductID[] ,char ShopID[] ,int gia,int h,int m,int s) {
    if (*root == NULL) {
        *root = createNode(CustomerID,ProductID,ShopID,gia,h,m,s);
    } else {
        if (strcmp(code, (*root)->code) < 0) {
            addProduct_BST(&((*root)->left), CustomerID,ProductID,ShopID,gia,h,m,s);
        } else if (strcmp(code, (*root)->code) > 0) {
            addProduct_BST(&((*root)->right), CustomerID,ProductID,ShopID,gia,h,m,s);
        }
    }
}

