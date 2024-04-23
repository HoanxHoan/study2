#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
char a[100000][100];
int cmp(const void *a,const void *b)
    {
        char *x=(char *)a;
        char *y=(char *)b;
        return  strcmp(x,y);
    }
int main()
{
	int n;
	scanf("%d",&n);  
	getchar(); 
	char string[100];
	for(int i = 0; i<n; i++)
	{
		fgets(string,100,stdin);
		strcpy(a[i],string); 
		
	} 
	qsort(a,n,sizeof(a[0]),cmp); 
	for(int i = 0; i<n; i++)
	{
		printf("%s",a[i]) ;
	 } 
	return 0;
}
