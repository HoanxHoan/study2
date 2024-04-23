#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_L 20
#define MAX_W 1000000

typedef struct {
    char word[MAX_L + 1];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    const WordCount *wordA = (const WordCount *)a;
    const WordCount *wordB = (const WordCount *)b;

    if (wordB->count != wordA->count) {
        return wordB->count - wordA->count;
    } else {
        return strcmp(wordA->word, wordB->word);
    }
}
void heap_shift_down(int i, int n, WordCount *arr) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && compare(&arr[left], &arr[largest]) > 0) {
        largest = left;
    }

    if (right < n && compare(&arr[right], &arr[largest]) > 0) {
        largest = right;
    }

    if (largest != i) {
        WordCount temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heap_shift_down(largest, n, arr);
    }
}


void heap_make(WordCount *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heap_shift_down(i, n, arr);
    }
}

int main() {
    char text[MAX_W];
    fgets(text, sizeof(text), stdin);
    char *token = strtok(text, " \n");
    WordCount *wordList = (WordCount *)malloc(MAX_W * sizeof(WordCount));
    int wordCount = 0;

    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < wordCount; ++i) {
            if (strcmp(wordList[i].word, token) == 0) {
                wordList[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(wordList[wordCount].word, token);
            wordList[wordCount].count = 1;
            wordCount++;
        }

        token = strtok(NULL, " \n");
    }

    qsort(wordList, wordCount, sizeof(WordCount), compare);

    for (int i = 0; i < wordCount; ++i) {
        printf("%s %d\n", wordList[i].word, wordList[i].count);
    }

    free(wordList);
    return 0;
}

