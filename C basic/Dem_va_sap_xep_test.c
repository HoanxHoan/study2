#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 20

typedef struct {
    char *word;
    int freq;
} WordFreq;

int compare(const void *a, const void *b) {
    WordFreq *w1 = (WordFreq *)a;
    WordFreq *w2 = (WordFreq *)b;
    if (w1->freq != w2->freq) return w2->freq - w1->freq;
    return strcmp(w1->word, w2->word);
}

int is_valid_word(const char *word) {
    while (*word) {
        if (!isspace((unsigned char)*word))
            return 1;
        word++;
    }
    return 0;
}

int main() {
    WordFreq *words = NULL;
    size_t capacity = 0;
    size_t word_count = 0;

    char line[MAX_WORD_LEN * 100000]; 

    if (fgets(line, sizeof(line), stdin) == NULL) {
        fprintf(stderr, "-1\n");
        return 1;
    }

    char *token = strtok(line, " \n");

    while (token != NULL) {
        if (is_valid_word(token)) {
            int found = 0;
            for (size_t i = 0; i < word_count; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].freq++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                if (word_count == capacity) {
                    capacity = (capacity == 0) ? 1 : capacity * 2;
                    words = realloc(words, capacity * sizeof(WordFreq));
                    if (words == NULL) {
                        fprintf(stderr, "-1\n");
                        return 1;
                    }
                }

                words[word_count].word = strdup(token);
                words[word_count].freq = 1;
                word_count++;
            }
        }

        token = strtok(NULL, " \n");
    }

    qsort(words, word_count, sizeof(WordFreq), compare);

    for (size_t i = 0; i < word_count; i++) {
        printf("%s %d\n", words[i].word, words[i].freq);
        free(words[i].word);
    }

    free(words);

    return 0;
}


