//llqueue
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    struct Node* newNode;
    struct Node* temp;
    int choice;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                newNode = (struct Node*)malloc(sizeof(struct Node));
                printf("Enter value to enqueue: ");
                scanf("%d", &newNode->data);
                newNode->next = NULL;

                if (rear== NULL) {
                    front = rear = newNode;
                } else {
                    rear->next = newNode;
                    rear=newNode;
                }
                printf("%d enqueued to queue\n", newNode->data);
                break;

            case 2:
                if (front == NULL) {
                    printf("Queue is empty\n");
                } else {
                    temp = front;
                    printf("Dequeued: %d\n", temp->data);
                    front = front->next;
                    free(temp);
                    if (front == NULL) {
                        rear = NULL;
                    }
                }
                break;

            case 3:
                if (front == NULL) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue: ");
                    temp = front;
                    while (temp != NULL) {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
