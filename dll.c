#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *newnode, *temp;
int count, pos;

void insertAtFirst() {
    newnode = malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data for newnode: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
}

void insertAtLast() {
    newnode = malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data for newnode: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insertAtPosition() {
    int i = 1;
    if (head == NULL) {
        printf("List is empty. Inserting at first position.\n");
        insertAtFirst();
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    // Count nodes
    count = 0;
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertAtFirst();
        return;
    }
    if (pos == count + 1) {
        insertAtLast();
        return;
    }

    newnode = malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data for newnode: ");
    scanf("%d", &newnode->data);

    temp = head;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void deleteAtFirst() {
    if (head == NULL) {
        printf("Empty linked list\n");
        return;
    }
    temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

void deleteAtLast() {
    if (head == NULL) {
        printf("Empty linked list\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void deleteAtPosition() {
    int i = 1;

    if (head == NULL) {
        printf("Empty linked list\n");
        return;
    }

    // Count nodes
    count = 0;
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Enter position you want to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        deleteAtFirst();
        return;
    }

    if (pos == count) {
        deleteAtLast();
        return;
    }

    temp = head;
    while (i < pos) {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display() {
    printf("Linked list: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1) Insert at first\n");
        printf("2) Insert at last\n");
        printf("3) Insert at position\n");
        printf("4) Delete at first\n");
        printf("5) Delete at last\n");
        printf("6) Delete at position\n");
        printf("7) Display\n");
        printf("8) Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insertAtFirst();
                break;
            case 2:
                insertAtLast();
                break;
            case 3:
                insertAtPosition();
                break;
            case 4:
                deleteAtFirst();
                break;
            case 5:
                deleteAtLast();
                break;
            case 6:
                deleteAtPosition();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
