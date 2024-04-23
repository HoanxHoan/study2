//C 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char word[20];
    int num;
} Wordnum;

int compare(const void *a, const void *b) {
    const Wordnum *wordA = (const Wordnum *)a;
    const Wordnum *wordB = (const Wordnum *)b;

    if (wordB->num != wordA->num) {
        return wordB->num - wordA->num;
    } else {
        return strcmp(wordA->word, wordB->word);
    }
}

void heapify(Wordnum arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && compare(&arr[l], &arr[largest]) > 0)
        largest = l;

    if (r < n && compare(&arr[r], &arr[largest]) > 0)
        largest = r;

    if (largest != i) {
 
        Wordnum temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(Wordnum arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {

        Wordnum temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);

    Wordnum *wordnumArray = (Wordnum *)malloc(n * sizeof(Wordnum));

    for (int i = 0; i < n; i++) {
        scanf("%s %d", wordnumArray[i].word, &wordnumArray[i].num);
    }

    heapSort(wordnumArray, n);

    for (int i = 0; i < k; i++) {
        printf("%s %d\n", wordnumArray[i].word, wordnumArray[i].num);
    }

    free(wordnumArray);

    return 0;
}

