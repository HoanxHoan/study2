#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

char a[MAX_WORDS][MAX_WORD_LENGTH];

int cmp(const void *a, const void *b) {
    char *x = (char *)a;
    char *y = (char *)b;
    return strcmp(x, y);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); 

    char string[MAX_WORD_LENGTH];
    for (int i = 0; i < n; i++) {
        fgets(string, MAX_WORD_LENGTH, stdin);
        string[strcspn(string, "\n")] = '\0'; 
        strcpy(a[i], string);
    }

    qsort(a, n, sizeof(a[0]), cmp);

    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }

    return 0;
}

