#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct nnode {
  char key[256];
  struct nnode *left;
  struct nnode *rsib;
};
 
struct ntree {
  struct nnode *root;
  long size;
};
 
struct nnode *nnode(const char *key) {
  struct nnode *n = malloc(sizeof(struct nnode));
  strcpy(n->key, key);
  n->left = n->rsib = NULL;
}
 
struct ntree *ntree() {
  struct ntree *t = malloc(sizeof(struct ntree));
  t->root = NULL;
  t->size = 0;
}
 
long int nloop(struct nnode *n, void *u,
           int (*cb)(struct nnode *n, void *u)) {
  if (!n) {
    return 0;
  }
  if (cb(n, u)) {
    return 1;
  }
  if (nloop(n->left, u, cb)) {
    return 1;
  }
  if (nloop(n->rsib, u, cb)) {
    return 1;
  }
  return 0;
}
 
struct nk {
  struct nnode *n;
  const char *k;
};
 
int ncmp_key(struct nnode *n, void *u) {
  struct nk *nk = u;
  if (strcmp(n->key, nk->k) == 0) {
    nk->n = n;
    return 1;
  }
  return 0;
}
 
struct nnode *nfind(struct ntree *t, const char *key) {
  struct nk nk = {NULL, key};
  nloop(t->root, &nk, ncmp_key);
  return nk.n;
}
 
struct ntree *nadd(struct ntree *t, const char *pkey,
              const char *nkey) {
  if (t->root == NULL) {
    t->root = nnode(nkey);
    t->size++;
    return t;
  }
  struct nnode *p = nfind(t, pkey);
  if (!p) {
    return NULL;
  }
  struct nnode *nn = nnode(nkey);
  if (p->left == NULL) {
    p->left = nn;
    t->size++;
    return t;
  }
  struct nnode *x = p->left;
  while (x->rsib != NULL) {
    x = x->rsib;
  }
  x->rsib = nn;
  t->size++;
  return t;
}
 
int nprint_node(struct nnode *n, void *u) {
  printf("%s:", n->key);
  struct nnode *x = n->left;
  while (x) {
    printf(" %s", x->key);
    x = x->rsib;
  }
  printf("\n");
  return 0;
}
 
void nprint(struct ntree *t) {
  nloop(t->root, NULL, nprint_node);
}
long nnode_height(struct nnode *n) {
  int h = 0;
  if (!n) {
    return 0;
  }
  struct nnode *x = n->left;
  while (x) {
    int tmp = nnode_height(x);
    if (tmp > h) {
      h = tmp;
    }
    x = x->rsib;
  }
  return 1 + h;
}
 
long nheight(struct ntree *t) {
  return nnode_height(t->root);
}
 
void nfreeloop(struct nnode *n) {
   if (!n) {
    return;
  }
  struct nnode *x = n->left;
  while (x) {
    struct nnode *tmp = x->rsib;
    nfreeloop(x);
    x = tmp;
  }
  free(n);
}
void nfree(struct ntree *t) {
  nfreeloop(t->root);
  free(t);
}
int ncount_cb(struct nnode *n,void *u){
	long *pc = u;
	++(*pc);
	return 0;
}
long ncount(struct nnode *n){
 	long cc=0;
 	if(!n){
 		return 0;
	 }
 	nloop(n->left,&cc,ncount_cb);
 	return cc+1;
 }
int main() {
  struct ntree *t = ntree();
  nadd(t, NULL, "David");
  nadd(t, "David", "Jame");
  nadd(t, "David", "Peter");
  nadd(t, "David", "John");
  nadd(t, "Jame", "Mike");
  nadd(t, "Peter", "Mary");
  nadd(t, "Peter", "Daisy");
  nadd(t, "Peter", "Maria");
  nadd(t, "Mary", "Pluto");
  nprint(t);
  printf("tong so nut la : %d\n",t->size);
  printf("tong so nut cua cay Peter : %ld\n",ncount(nfind(t,"Peter")));
  printf("do cao ca cay la: %ld\n", nheight(t));
  nfree(t);
  return 0;
}
