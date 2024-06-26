#include <stdio.h>
#include<stdlib.h>
#define HLEFT(i) (((i) << 1) + 1)
#define HRIGHT(i) (((i) << 1) + 2)
#define SWAP(a, b) { double _tmp = (a); (a) = (b); (b) = _tmp; }

void heap_shift_down(long i, long n, double *a) {
  for (;;) {
    long lc = HLEFT(i), rc = HRIGHT(i), root = i;
    if (lc < n && a[root] > a[lc]) {
      root = lc;
    }
    if (rc < n && a[root] > a[rc]) {
      root = rc;
    }
    if (root == i) {
      break;
    }
    SWAP(a[i], a[root]);
    i = root;
  }
}
void heap_make(long n, double *a) {
  for (long i = n / 2; i >= 0; --i) {
    heap_shift_down(i, n, a);
  }
}
int main() {
   int x,k;
   scanf("%d %d",&k,&x);
   double *a = (double *)malloc(x * sizeof(double));
    int n = sizeof(a)/sizeof(a[0]);
   for(int i=0;i<x;i++)
	{scanf("%lf",&a[i]);}
   heap_make(x, a);
   for (int i = 0; i < k; ++i) {
   printf("%.2lf\n", a[0]);
   SWAP(a[0], a[n - i - 1]);
   heap_shift_down(0, n - i - 1, a);
  }
  free(a);
  return 0;
}
