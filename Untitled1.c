#include<stdlib.h>
#include<stdio.h>
int main()
{
	int *p = malloc(sizeof(int));
	scanf("%d",p);
	printf("gia tri da nhap la %d\n", *p);
}
