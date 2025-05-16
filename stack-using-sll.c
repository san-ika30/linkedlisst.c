#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* top = NULL;
    struct Node* newNode;
    struct Node* temp;
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Push
                newNode = (struct Node*) malloc(sizeof(struct Node));
                if (newNode == NULL) {
                    printf("Stack overflow (memory allocation failed)\n");
                    break;
                }
                printf("Enter the value to push: ");
                scanf("%d", &newNode->data);
                newNode->next = top;
                top = newNode;
                printf("%d pushed to stack\n", newNode->data);
                break;

            case 2:  // Pop
                if (top == NULL) {
                    printf("Stack underflow (empty stack)\n");
                } else {
                    temp = top;
                    printf("Popped element: %d\n", temp->data);
                    top = top->next;
                    free(temp);
                }
                break;

            case 3: {  // Display
                if (top== NULL) {
                    printf("stack is Empty\n");
                } else {
                    printf("stack is:\n");
                    temp = top;
                    int nodenumber = 1;  // Start node count from 1
                    while (temp != NULL) {
                        printf("Node:%d Data:%d Address:%p Next:%p\n",
                               nodenumber, temp->data, (void*)temp, (void*)temp->next);
                        temp = temp->next;
                        nodenumber++;
                    }
                }
            }
            break;

            case 4:  // Exit
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
