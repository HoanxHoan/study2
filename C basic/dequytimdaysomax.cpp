#include <stdio.h>
	int max=0;
	int s=0;
int max(int n,int x,list[n]){
	if(n<3){return 0;}
	s=list[n]+list[n-1]+list[n-2];
	int max(n-1,k,list);
	if(s>max){max=s;}
	return max;
	}

int main()
{
  int n,k,list[n];
  scanf("%d %d",&n,&k);
  for(int i=0;i<n;i++)
  {scanf("%d",&list[i]);}
  printf("%d",max(n,k,list););
  return 0;
  
}	
