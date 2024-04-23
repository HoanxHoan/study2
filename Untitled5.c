#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

// Khoi tao cap = n, sz = 0
struct vector *vec_create(int n) {
   struct vector *v = malloc(sizeof(struct vector));
   v->sz = 0;
   v->cap = n;
   v->elems = malloc(n * sizeof(int));
   return v;
}

void vec_free(struct vector *v) {
   free(v->elems);
   free(v);
}

// Ðoc
int vec_get(struct vector *v, int idx) { 
  return v->elems[idx];
}

// Cap nhat
void vec_set(struct vector *v, int idx, int value) {
  v->elems[idx] = value;
}

// Kích thuoc hien tai
int vec_size(struct vector *v) {  
  return v->sz;
}

// Dung luong hien tai
int vec_cap(struct vector *v) {
  return v->cap;
}

// Ðieu chinh bo nho du phòng
void vec_reserve(struct vector *v, int newcap) {
  // Không giai phóng các phan tu dã su dung
  if (newcap <= v->sz) {
    return;
  }
  v->elems = realloc(v->elems, newcap * sizeof(int));
  v->cap = newcap;
}

// Thêm phan tu vào sau phan tu cuoi cùng,
// thay doi dung luong neu can.
void vec_append(struct vector *v, int value) {
  if (v->cap == 0) {
    vec_reserve(v, 16);
  } else if (v->sz == v->cap) {
    vec_reserve(v, 2 * v->cap);
  }
  v->elems[v->sz] = value;
  ++v->sz;
}

// Xuat noi dung cua vec-to de ho tro go roi
void vec_pprint(struct vector *v) {
  printf("size: %d\n", v->sz);
  printf("cap: %d\n", v->cap);
  printf("elems:");
  for (int i = 0; i < v->sz; ++i) {
    printf(" %d", v->elems[i]);
  }
  printf("\n");
}


