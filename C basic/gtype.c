#include<stdio.h>
#include<stdlib.h>
typedef union generic_type {
  long l;
  double d;
  char *s;
  void *v;
  union generic_type *g;
  struct gdllist *gdl;
  struct gsllist *gsl;
  struct gvector *gvec;
  struct rbmtree *rbm;
} gtype;
int main()
{
	gtype g;
	scanf("%ld",&g.l);
	printf("ban da nhap %ld\n",g.l);
	scanf("%lf",&g.d);
	printf("ban da nhap %lf\n",g.d);
	g.s=malloc(100);
    scanf("%s",g.s);
	printf("ban da nhap %s\n",g.s);
	free(g.s);
}
