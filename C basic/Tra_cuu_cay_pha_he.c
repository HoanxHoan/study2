#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Node {
    char data[MAX_SIZE];
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

typedef struct {
    char key[MAX_SIZE];
    Node* value;
} KeyValuePair;

void insertKeyValuePair(KeyValuePair* map, int* size, char* key, char* value) {
    int index = -1;
    for (int i = 0; i < *size; ++i) {
        if (strcmp(map[i].key, key) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        strcpy(map[*size].key, key);
        map[*size].value = createNode(value);
        (*size)++;
    } else {
        Node* newNode = createNode(value);
        newNode->next = map[index].value;
        map[index].value = newNode;
    }
}

int cnt = 0;

void descendants(KeyValuePair* map, int size, char* key) {
    cnt++;
    Node* current = NULL;
    for (int i = 0; i < size; ++i) {
        if (strcmp(map[i].key, key) == 0) {
            current = map[i].value;
            break;
        }
    }

    while (current != NULL) {
        descendants(map, size, current->data);
        current = current->next;
    }
}

int maxg = 0;

void generation(KeyValuePair* map, int size, char* key, int g) {
    if (g > maxg) {
        maxg = g;
    }

    Node* current = NULL;
    for (int i = 0; i < size; ++i) {
        if (strcmp(map[i].key, key) == 0) {
            current = map[i].value;
            break;
        }
    }

    while (current != NULL) {
        generation(map, size, current->data, g + 1);
        current = current->next;
    }
}

int main() {
    KeyValuePair map[MAX_SIZE];
    int size = 0;

    char x[MAX_SIZE];
    do {
        scanf("%s", x);
        if (strcmp(x, "***") != 0) {
            char y[MAX_SIZE];
            scanf("%s", y);
            insertKeyValuePair(map, &size, y, x);
        }
    } while (strcmp(x, "***") != 0);

    do {
        scanf("%s", x);
        if (strcmp(x, "descendants") == 0) {
            char y[MAX_SIZE];
            scanf("%s", y);
            cnt = 0;
            descendants(map, size, y);
            printf("%d\n", cnt - 1);
        } else if (strcmp(x, "generation") == 0) {
            char y[MAX_SIZE];
            scanf("%s", y);
            maxg = 0;
            generation(map, size, y, 0);
            printf("%d\n", maxg);
        }
    } while (strcmp(x, "***") != 0);

    return 0;
}
