#include <stdio.h>
#include <stdlib.h>

int compfun (const void * a, const void * b)
{
     const double  *x = a;
	 const double  *y = b;
	 if(*x<*y) return 1;
	 else if(*x>*y) return -1;
	 else return 0; 
}
int main()
{
	int k,n;
	scanf("%d %d",&k,&n);
	double a[n];
	for(int i=0;i<n;i++){
		scanf("%lf",&a[i]);
		if(i!=n-1){
		scanf(" ");}
	}
	qsort(a,n,sizeof(double),compfun);
	for(int i=0;i<k;i++){
		printf("%.2lf\n",a[i]);
	}
	return 0;
} 
