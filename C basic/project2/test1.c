#include"cgen.h"
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	struct vector *v = vcreate(n);
	vtraverse(cur, v){
		scanf("%ld",(long*)cur);
	}
	vtraverse(cur, v){
		printf("%ld",cur->l);
	}
	printf("\n");
	vfree(v);
}
