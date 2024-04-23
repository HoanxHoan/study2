#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Pair {
    char str[1000];
    int code;
};


int compare(const void *a, const void *b) {
    struct Pair *pairA = (struct Pair *)a;
    struct Pair *pairB = (struct Pair *)b;

    int strCompare = strcmp(pairA->str, pairB->str);

   
    if (strCompare == 0) {
        return pairA->code - pairB->code;
    }

    return strCompare;
}

int main() {
    int n;
    scanf("%d\n", &n);
    struct Pair pairs[n];
    char* string = (char*) malloc(110*sizeof(char));
    char a[100000];
    for (int i = 0; i < n; ++i) {
    	fgets(string,1000,stdin);
    	int x=strlen(string);
    for(int j=x-1;j>=0;j--){
    	if(string[j]==' '){
    		for(int m=0;m<x-j;m++){
    			a[m]=string[j+m];
			}
		pairs[i].code = atoi(&a[0]);
    	string[j]=0;
    	string[strcspn(string, "\n")] = '\0';
    	string[strcspn(string, "0")] = '\0';
    	strcpy(pairs[i].str,string);
    	break;
    	}
   }	free(string);
}
    qsort(pairs, n, sizeof(struct Pair), compare);
    for (int i = 0; i < n; ++i) {
        printf("%s %d\n", pairs[i].str, pairs[i].code);
    }

    return 0;
}

