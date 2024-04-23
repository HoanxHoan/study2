#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct bst_node{
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
struct bst_node *bst_node(char* key,int value ){
	struct bst_node *nn = malloc(sizeof(struct bst_node));
	strcpy(nn->key, key);
	nn->value = value;
	nn->left=NULL;
	nn->right=NULL;
	nn->top = NULL;
  return nn;
}
struct bst_tree *bst_tree(cmp_fnt cmp) {
  struct bst_tree *t = malloc(sizeof(struct bst_tree));
  t->cmp = cmp;
  t->root = NULL;
  t->size = 0;
}
int* bst_add(struct bst_tree *t, char *key, int value) {
    if (t->root == NULL) {
    t->root = bst_node(key, value);
    ++t->size;
    return NULL;
  }
  struct bst_node *p = t->root, *c;
  int r;
  for(;;) {
    r = t->cmp(key, p->key);
    if (r == 0) {
      return &p->value;
    }
    c = r < 0? p->left: p->right;
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
    u = r < 0 ? u->left: u->right;
  }
  return NULL;
}
struct bst_node *bst_pvalnode(int *pval) {
  return ((void*)pval) - offsetof(struct bst_node, value);
}
 
void bst_node_print_lnr(struct bst_node *n, int depth) {
  if (n->left) {
    bst_node_print_lnr(n->left, depth + 1);
  }
  for (int i = 0; i < depth * 2; ++i) {
    printf(" ");
  }
  printf("(%s: %d)\n", n->key, n->value);
  if (n->right) {
    bst_node_print_lnr(n->right, depth + 1);
  }
}
 
void bst_pprint(struct bst_tree *t) {
  printf("size: %ld\n", t->size);
  if (t->root) {
    bst_node_print_lnr(t->root, 0);
  }
}
 
int cmps(const void *p1, const void *p2) {
  return strcmp(p1, p2);
}
int bst_remove(struct bst_tree *t, char *key) {
  struct bst_node *dn = bst_pvalnode(bst_search(t, key));
  if (!dn) {
    return 0;
  }
  struct bst_node *node = dn;
  struct bst_node *child = node->right, *tmp = node->left, *top;
  struct bst_node *p;
  if (!tmp) {
    top = node->top;
    if (top) {
      if (top->left == node) {
        top->left = child;
      } else {
        top->right = child;
      }
    } else {
      t->root = child;
    }
    if (child) {
      child->top = top;
    }
  } else if (!child) {
    top = node->top;
    if (top) {
      if (top->left == node) {
        top->left = tmp;
      } else {
        top->right = tmp;
      }
    } else {
      t->root = tmp;
    }
    tmp->top = top;
  } else {
    struct bst_node *successor = child, *child2;
    tmp = child->left;
    if (!tmp) {
      top = successor;
      child2 = successor->right;
    } else {
      do {
        top = successor;
        successor = tmp;
        tmp = tmp->left;
      } while (tmp);
      child2 = successor->right;
      top->left = child2;
      successor->right = child;
      child->top = successor;
    }
    tmp = node->left;
    successor->left = tmp;
    tmp->top = successor;
    p = node->top;
    tmp = p;
    if (tmp) {
      if (tmp->left == node) {
        tmp->left = successor;
      } else {
        tmp->right = successor;
      }
    } else {
      t->root = successor;
    }
    if (child2) {
      child2->top = top;
    }
    successor->top = p;
    tmp = successor;
  }
  free(dn);
  --t->size;
  return 1;
}
int main() {
  struct bst_tree *t = bst_tree(cmps);
  char key[100];
  int value;
  while (scanf("%s", key) == 1) {
    if (strcmp(key, "***") == 0) {
      break;
    }
    scanf("%d", &value);
    bst_add(t, key, value);
  }
  bst_pprint(t);
  while (scanf("%s", key) == 1) {
  	if (strcmp(key, "***") == 0) {
      break;
    }
    int *pval = bst_search(t, key);
    if (pval) {
      printf("Found: (%s: %d)\n", bst_pvalnode(pval)->key, *pval);
    } else {
      printf("Key %s not exists\n", key);
    }
  }
    while (scanf("%s", key) == 1) {
    int ret = bst_remove(t, key);
    if (ret) {
      printf("Da Xoa %s\n", key);
      bst_pprint(t);
    } else {
      printf("Khong Tim Thay %s\n", key);
    }
  }
}

