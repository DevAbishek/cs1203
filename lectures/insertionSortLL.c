#include <stdio.h>
#include <stdlib.h>

struct NodeLL {
    int value;
    struct NodeLL *next;
};


void printLL(struct NodeLL *head) {
    struct NodeLL *current = head;
    while (current != NULL) {
        printf(" %d ->", current->value);
        current = current->next;
    }
    printf(" None \n");
}


void appendNode(struct NodeLL **head, int value) {
    struct NodeLL *new_node = malloc(sizeof(struct NodeLL));
    new_node->value = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct NodeLL *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void insertionSort(struct NodeLL **head) {
    struct NodeLL *current = *head;
    while (current != NULL) {

        struct NodeLL *current_anchor = current;
        struct NodeLL *j = current->next;

        while (j != NULL) {
            if (j->value < current_anchor->value) {
                current_anchor = j;
            }
            j = j->next;
        }
        
        int temp = current->value;
        current->value = current_anchor->value;
        current_anchor->value = temp;
        current = current->next;
    }
}


int main (void) {
    int length;
    printf("Enter no. of elements in linked list: ");
    scanf("%d", &length);

    struct NodeLL *head = NULL;
    for (int i = 0; i < length; i++) {
        printf("Element %d: ", i + 1);
        
        int current_val;
        scanf("%d", &current_val);

        appendNode(&head, current_val);
    }

    printf("The unsorted linked list is: ");
    printLL(head);

    insertionSort(&head);

    printf("The sorted linked list is: ");
    printLL(head);
}