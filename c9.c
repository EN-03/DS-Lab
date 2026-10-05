#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int job) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! Print queue is full.\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = job;
    printf("Print job %d added successfully.\n", job);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! No print jobs available.\n");
        return;
    }

    printf("Processed print job: %d\n", queue[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("No Pending Print Jobs.\n");
        return;
    }

    printf("Print Queue:\n");

    i = front;
    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice, job;

    while (1) {
        printf("\n--- Circular Print Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Job ID: ");
                scanf("%d", &job);
                enqueue(job);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated successfully.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
