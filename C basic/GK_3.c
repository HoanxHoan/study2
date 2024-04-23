//C 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char *s, char *ht) {
    int n = strlen(s), m = strlen(ht);
    while (n >= 0 && m >= 0) {
        if (s[n] != ht[m]) {
            return 0;
        }
        n--;
        m--;
    }
    return 1;
}

int compare(const void *a, const void *b) {
    const char *s1 = (const char *)a;
    const char *s2 = (const char *)b;
    return strcmp(s1, s2);
}

int main()
{
    char hauto[100];
    scanf("%s", hauto);
    char s[100];
    char words[10000][100];
    int word_count = 0;
    while (scanf("%s", s) == 1)
    {
        if (check(s, hauto))
        {
            strcpy(words[word_count], s);
            word_count++;
        }
    }

    qsort(words, word_count, sizeof(words[0]), compare);

    for (int i = 0; i < word_count; i++)
    {
        printf("%s\n", words[i]);
    }

    return 0;
}

