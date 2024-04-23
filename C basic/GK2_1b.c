#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char ma[100];
    int can;
};

struct order_item {
    char ma[100];
    int so_luong;
};

struct bst_node {
    char key[100];
    int value;
    struct bst_node *left;
    struct bst_node *right;
    struct bst_node *top;
};

typedef int (*cmp_fnt)(const void *, const void *);

struct bst_tree {
    struct bst_node *root;
    cmp_fnt cmp;
    long size;
};

struct bst_node *bst_node(char *key, int value) {
    struct bst_node *nn = malloc(sizeof(struct bst_node));
    strcpy(nn->key, key);
    nn->value = value;
    nn->left = NULL;
    nn->right = NULL;
    nn->top = NULL;
    return nn;
}

struct bst_tree *bst_tree(cmp_fnt cmp) {
    struct bst_tree *t = malloc(sizeof(struct bst_tree));
    t->cmp = cmp;
    t->root = NULL;
    t->size = 0;
    return t;
}

int *bst_add(struct bst_tree *t, char *key, int value) {
    if (t->root == NULL) {
        t->root = bst_node(key, value);
        ++t->size;
        return NULL;
    }
    struct bst_node *p = t->root, *c;
    int r;
    for (;;) {
        r = t->cmp(key, p->key);
        if (r == 0) {
            return &p->value;
        }
        c = r < 0 ? p->left : p->right;
        if (!c) {
            break;
        }
        p = c;
    }
    struct bst_node *nn = bst_node(key, value);
    if (r < 0) {
        p->left = nn;
    } else {
        p->right = nn;
    }
    ++t->size;
    return NULL;
}

int *bst_search(struct bst_tree *t, char *key) {
    struct bst_node *u = t->root;
    while (u) {
        int r = t->cmp(key, u->key);
        if (r == 0) {
            return &u->value;
        }
        u = r < 0 ? u->left : u->right;
    }
    return NULL;
}

int cmps(const void *p1, const void *p2) {
    return strcmp(p1, p2);
}

int main() {
    int n;
    scanf("%d", &n);

    struct item items[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d", items[i].ma, &items[i].can);
    }

    struct bst_tree *t = bst_tree(cmps);
    for (int i = 0; i < n; i++) {
        bst_add(t, items[i].ma, items[i].can);
    }

    int m;
    scanf("%d", &m);

    for (int j = 0; j < m; j++) {
        int k, S = 0;
        scanf("%d", &k);

        for (int i = 0; i < k; i++) {
            struct order_item oi;
            scanf("%s %d", oi.ma, &oi.so_luong);

            int *pval = bst_search(t, oi.ma);
            if (pval != NULL) {
                S += (*pval * oi.so_luong);
            }
        }

        printf("%d\n", S);
    }

    return 0;
}

