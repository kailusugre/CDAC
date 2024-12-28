#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void enqueue(int *, int *, int *, int);
int dequeue(int *, int *, int *);
void display(int *, int, int);

int main() {
    int arr[SIZE];
    int front = -1, rear = -1;
    int choice, ele;
    int ret;

    // Initialize the array with -99 (indicating empty slots)
    for (int i = 0; i < SIZE; i++) {
        arr[i] = -99;
    }

    while (1) {
        printf("Enter 1->enqueue, 2->dequeue, 3->display, 4->exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Element to enqueue: ");
                scanf("%d", &ele);
                enqueue(arr, &front, &rear, ele);
                break;

            case 2:
                ret = dequeue(arr, &front, &rear);
                if (ret != EMPTY_QUEUE) {
                    printf("Dequeued item = %d\n", ret);
                }
                break;

            case 3:
                printf("Queue: ");
                display(arr, front, rear);
                printf("\n");
                break;

            case 4:
                exit(0);
        }
    }
}

void enqueue(int *arr, int *f, int *r, int ele) {
       if ((*r + 1) % SIZE == *f) {   // Check if the queue is full
        printf("Queue is full\n");
        return;
    }

    if (*f == -1) { // If the queue is initially empty
        *f = *r = 0;
    } else {
        *r = (*r + 1) % SIZE; // Move rear circularly
    }
    
    arr[*r] = ele;
}

int dequeue(int *arr, int *f, int *r) {
    // Check if the queue is empty
    if (*f == -1) {
        printf("Queue is empty\n");
        return -77;
    }

    int temp = arr[*f];
    arr[*f] = -99;

    // If the queue becomes empty after this operation
    if (*f == *r) {
        *f = *r = -1;
    } else {
        *f = (*f + 1) % SIZE; // Move front circularly
    }

    return temp;
}

void display(int *arr, int f, int r) {
    if (f == -1) {
        printf("Queue is empty");
        return;
    }

    // Display elements from front to rear circularly
    int i = f;
    while (1) {
        printf("|%d|", arr[i]);
        if (i == r) {
            break;
        }
        i = (i + 1) % SIZE;
    }
}

