#include <stdio.h>
#include <stdlib.h>

// Khai b�o cau tr�c node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Khai b�o cau tr�c queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// H�m tao queue
void initializeQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

// H�m kiem tra queue c� rong hay kh�ng
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// H�m th�m mot phan tu v�o queue
void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Enqueued %d to the queue\n", value);
}

// H�m bot mot phan tu khoi queue
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
    } else {
        Node* temp = queue->front;
        queue->front = queue->front->next;

        printf("Dequeued %d from the queue\n", temp->data);
        free(temp);

        // Neu queue tro th�nh rong sau khi dequeue, cap nhat rear de tr�nh loi kh�ng x�c dinh
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
    }
}

// H�m ch�n mot phan tu giua hai gi� tri cu the trong queue
void insertBetweenValues(Queue* queue, int value, int value1, int value2) {
    Node* current = queue->front;
    Node* previous = NULL;

    // T�m vi tr� cua value1 v� value2 trong queue
    while (current != NULL) {
        if (current->data == value1 && current->next != NULL && current->next->data == value2) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            if (newNode == NULL) {
                printf("Memory allocation failed\n");
                return;
            }

            newNode->data = value;
            newNode->next = current->next;
            current->next = newNode;

            printf("Inserted %d between %d and %d\n", value, value1, value2);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Values not found in the queue\n");
}

