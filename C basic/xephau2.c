#include<stdio.h>
int Board[100][100];
 
 
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
/*void try(int x){
	if (x >= N) {
        return 0;
    }

    for (int i = 0; i < 8; i++) {
        if (check(x, i)) {
            board[x][i] = 1;

            if (try(x + 1)) {
                return 0;
            }

            board[x][i] = 0; 
        }
    }

    return 0;
}*/

int main(){
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",&Board[i][j]);
        }
    }
    int x=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(Board[i][j]==1){
            	if(check){x=1;
            	break;
				}
			} 
        }if(x==1) {
		break;}    
    }
	if(x==1){printf("1");}
	else printf("0");
}

