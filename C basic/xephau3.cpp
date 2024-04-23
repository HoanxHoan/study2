//C
#include<stdio.h>
int Board[100][100];
 void printBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", Board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
 
int check(int x,int y,int n){
	int i,j;
	for(i=0;i<n;i++){
	if(Board[i][y]==1)
	return 0;
    }
    for(j=0;j<n;j++){
    if(Board[x][j]==1)
	return 0;	
	}
	for (i = x, j = y; i >= 0 && j >= 0; i--, j--) {
        if (Board[i][j]==1) {
            return 0;
        }
    }
    for (i = x, j = y; i < n && j >= 0; i++, j--) {
        if (Board[i][j]==1) {
            return 0;
        }
    }
    for (i = x, j = y; i <n  && j < n ; i++, j++) {
        if (Board[i][j]==1) {
            return 0;
        }
    }
    for (i = x, j = y; i >=0  && j < n ; i--, j++) {
        if (Board[i][j]==1) {
            return 0;
        }
    }
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",&Board[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(Board[i][j]==0){
            	check(i,j,n);
			} 
        }
    }
    if(check==0){printf("-1");
	}
	else printBoard();
}
