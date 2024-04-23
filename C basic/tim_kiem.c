#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int icmp(const void *p1, const void *p2) {
  return *(const int*)p1 - *(const int *)p2;
}
typedef int (*cmp_t)(const void *p1, const void *p2);
int my_bsearch(const void *a, int n, int sz, const void *v, cmp_t cmp) {
  int l = 0, r = n - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    int x = cmp(a + m * sz, v);
    if (x == 0) {
      return m;
    }
    if (x < 0) {
      l = m + 1;
    } else if (x > 0) {
      r = m - 1;
    }
  }
  return -1;
}
int main() {
    int n_1,n_2;
    scanf("%d",&n_1);
    int a[n_1],v[n_2];
    for(int i=0;i<n_1;i++){
    	scanf("%d",&a[i]);
	}
	qsort(a,n_1,sizeof(a[0]),icmp);
	scanf("%d",&n_2);
    for(int i=0;i<n_2;i++){
    	scanf("%d",&v[i]);
	}
    int m = sizeof(a)/sizeof(a[0]);
    for(int j=0;j<n_2;j++){
    	int x=my_bsearch(a, m, sizeof(int), &v[j], icmp);
    if(x == -1)
    {printf("0\n");}
	else {printf("1\n");}
   }
}
