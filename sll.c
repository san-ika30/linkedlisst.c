#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *newnode, *temp;
    struct node *head = NULL;
    struct node *prevnode;
    int choice, value;

    while (1) {
        printf("\n1.Insert at first\n2.Insert at last\n3.Delete at first\n4.Delete at last\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                newnode = malloc(sizeof(struct node));
                printf("Enter the data for newnode: ");
                scanf("%d", &newnode->data); // Corrected scanf
                newnode->next = NULL;
                if (head == NULL) {
                    head = newnode;
                } else {
                    newnode->next = head;
                    head = newnode;
                }
            }
            break;

            case 2: {
                newnode = malloc(sizeof(struct node));
                printf("Enter the data for newnode: ");
                scanf("%d", &newnode->data);
                newnode->next = NULL;

                if (head == NULL) {
                    head = newnode;
                } else {
                    temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newnode;  // moved out of loop
                }
            }
            break;

            case 3: {
                if (head == NULL) {
                    printf("Empty SLL\n");
                } else {
                    temp = head;
                    head = head->next;
                    printf("First node deleted\n");
                    free(temp);
                }
            }
            break;

            case 4: {
        if (head == NULL) {
        printf("Empty SLL\n");
       } else {
        temp = head;
        prevnode = NULL;

        while (temp->next != NULL) {
            prevnode = temp;
            temp = temp->next;
        }

        if (temp == head) {
            // Only one node in the list
            head = NULL;
        } else {
            prevnode->next = NULL;
        }

        free(temp);
        printf("Last node deleted\n");
    }
}
break;

            

            case 5: {
                if (head == NULL) {
                    printf("Linked list is Empty\n");
                } else {
                    printf("Linked list is:\n");
                    temp = head;
                    int nodenumber = 1;
                    while (temp != NULL) {
                        printf("Node:%d Data:%d Current node address:%p Next node address:%p\n",
                               nodenumber, temp->data, (void*)temp, (void*)temp->next);
                        temp = temp->next;
                        nodenumber++;
                    }
                }
            }
            break;

            case 6:
                printf("Exiting program\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
