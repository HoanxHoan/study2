#include<stdio.h>
int board[100][100];
int a[100];
int b[100];
int main()
  {int n;
   scanf("%d",&n);
  for(int i=1;i<=n;i++ )
	{for(int j=1;j<=n ;j++)
	  {scanf("%d",&board[i][j]);
	  if(board[i][j]==1)
		{a[i]++;
		 b[j]++;
        }
      }
    }
  int m;
  int k;
  int ok=1;
  for(int i=1;i<=n;i++){
    if(a[i]==0)
	m=i;
	if(a[i]>1)
	ok=0;}
  for(int i=1;i<=n;i++){
    if(b[i]==0)
	k=i;
	if(b[i]>1)
	ok=0;}
    board[m][k]=1;
  int cnt1=0;
  int cnt2=0;
  for(int i=1;i<=n;i++){
  if(board[i][i])
	cnt1++;
	if(board[i][n+1-i])
	cnt2++;
    }
  if(cnt1>1||cnt2>1)
  ok=0;
  if(ok)
	{for(int i=1;i<=n;i++)
	  {for(int j=1;j<=n;j++)
	   printf("%d ",board[i][j]);
	   printf("\n");
      }
    }
  else
  printf("-1");
  }

