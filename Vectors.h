#ifndef VECTOR_H_
#define VECTOR_H_

struct vector {
  int sz;  // K�ch thuoc: So luong phan tu d� c� trong vec-to
  int *elems;  // con tro tai phan tu dau ti�n
  int cap;  // Dung luong: So luong phan tu duoc cap ph�t
};

struct vector *vec_create(int n);
void vec_free(struct vector *v);
int vec_get(struct vector *v, int idx);
void vec_set(struct vector *v, int idx, int value);
int vec_size(struct vector *v);
int vec_cap(struct vector *v);
void vec_reserve(struct vector *v, int newcap);
void vec_append(struct vector *v, int value);
void vec_pprint(struct vector *v);

#endif  // VECTOR_H_
