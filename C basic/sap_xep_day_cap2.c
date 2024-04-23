#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
char c[100000][1000];
int cmp(const void *a,const void *b)
    {
        char *x=(char *)a;
        char *y=(char *)b;
        return  strcmp(x,y);
    }
typedef int (*cmp_t)(const void *, const void *);
/*void vswap(char *p, char *q, int sz) {
  char tmp;
  for (int i = 0; i < sz; ++i) {
    tmp = *p;
    *p = *q;
    *q = tmp;
    ++p;
    ++q;
  }
}
void q2sort(void *a, int n, int sz, cmp_t cmp) {
  if (n <= 1) {
    return;
  }
  void *left = a, *right = a + (n - 2) * sz;
  void *v = a + (n - 1) * sz;
  for (;;) {
    while (cmp(v, left) > 0) {
      left += sz;
    }
    while (cmp(right, v) > 0) {
      if (right == a) {
        break;
      }
      right -= sz;
    }
    if (left >= right) {
      break;
    }
    vswap(left, right, sz);
    left += sz;
    right -= sz;
  }
  vswap(left, v, sz);
  right = left + sz;(a, (left - a)/sz + 1, sz, cmp);
  q2sort(right, (a - right)/sz + n, sz, cmp);
}*/
void selsort(void*a,int n,int sz,cmp_t cmp){
	char *buff = malloc(sz);
	for(int i=0;i<n;i++){
		for(int j=i+1; j<n;j++){
			void *pi=a+i*sz,*pj=a+j*sz;
			if(cmp(pi,pj)>0){
				memcpy(buff,pi,sz);
				memcpy(pi,pj,sz);
				memcpy(pj,buff,sz);
			}
		}
	}
	free(buff);
}
int main()
{
	int n;
	scanf("%d",&n);  
	getchar(); 
	char s[1000];
	for(int i = 0; i<n; i++)
	{
		fgets(s,1000,stdin);
		strcpy(c[i],s); 
		
	} 
	selsort(c,n,sizeof(c[0]),cmp); 
	for(int i = 0; i<n; i++)
	{
		printf("%s",c[i]) ;
	 } 
	return 0;
}

