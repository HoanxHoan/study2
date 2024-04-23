#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int icmp(const void *p1,const void *p2){
	return *(const double *)p1 - *(const double *)p2;
}
typedef int (*cmp_t)(const void*,const void*);
void selsort(void*a,int n,int sz,cmp_t cmp){
	char *buff = malloc(sz);
	for(int i=0;i<n;i++){
		for(int j=i+1; j<n;j++){
			void *pi=(char *)a+i*sz,*pj=(char *)a+j*sz;
			if(cmp(pi,pj)>0){
				memcpy(buff,pi,sz);
				memcpy(pi,pj,sz);
				memcpy(pj,buff,sz);
			}
		}
	}
	free(buff);
}

int main(){
	double a[]={3.32,6.32,5.32,7,8.23,95.46,2.56,4.12,10};
	int n=sizeof(a)/sizeof(a[0]);
	selsort(a,n,sizeof(a[0]),icmp);
	for(int i=0;i<n;i++){
		printf("%.2f ",a[i]);
	}
}
