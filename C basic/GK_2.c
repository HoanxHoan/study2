#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 10000
#define MAX_LINE_LENGTH 256

typedef struct
{
    char time[20];
    char num[5];
    char content[MAX_LINE_LENGTH];
} TB;

int KieuTB(const char* c) {
    if (strcmp(c, "INFO") == 0) return 1;
    if (strcmp(c, "WARN") == 0) return 2;
    if (strcmp(c, "ERRO") == 0) return 3;
    return 0;
}

int comp(const void *a, const void *b)
{
    TB *x = (TB *)a;
    TB *y = (TB *)b;

    int numcmp = KieuTB(y->num) - KieuTB(x->num);
    if (numcmp != 0)
        return numcmp;

    int timecmp = strcmp(x->time, y->time);
    if (timecmp != 0)
        return timecmp;
    return strcmp(x->content, y->content);
}

int main()
{
    TB data[MAX_LINES];
    int n = 0;
    while (fgets(data[n].time, 20, stdin) != NULL)
    {
        data[n].time[19] = '\0';
        scanf("%s", data[n].num);
        getchar();
        fgets(data[n].content, MAX_LINE_LENGTH, stdin);
        char *token = strchr(data[n].content, '\n');
        if (token)
            *token = '\0';
        n++;
    }

    qsort(data, n, sizeof(TB), comp);

    for (int i = 0; i < n; i++)
    {
        printf("%s %s %s\n", data[i].time, data[i].num, data[i].content);
    }

    return 0;
}


