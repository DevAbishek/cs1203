#include <stdio.h>
#include <stdlib.h>

struct nodeLL {
    int value;
    struct nodeLL *next;
};


void printLL(struct nodeLL *head) {
    struct nodeLL *current = head;
    while (current != NULL) {
        printf(" %d ->", current->value);
        current = current->next;
    }
    printf(" None \n");
}


void nodeAppend(struct nodeLL **head, int value) {
    struct nodeLL *new_node = malloc(sizeof(struct nodeLL));
    new_node->value = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct nodeLL *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void selectionSort(struct nodeLL **head) {
    struct nodeLL *current = *head;
    while (current != NULL) {
        struct nodeLL *min = current;
        struct nodeLL *j = current->next;
        while (j != NULL) {
            if (j->value < min->value) {
                min = j;
            }
            j = j->next;
        }
        int temp = current->value;
        current->value = min->value;
        min->value = temp;
        current = current->next;
    }
}


int main (void) {
    int length;
    printf("Enter no. of elements linked list: ");
    scanf("%d", &length);

    struct nodeLL *head = NULL;
    for (int i = 0; i < length; i++) {
        printf("Element %d: ", i + 1);
        
        int current_val;
        scanf("%d", &current_val);

        nodeAppend(&head, current_val);
    }

    printf("The unsorted linked list is: ");
    printLL(head);

    selectionSort(&head);

    printf("The sorted linked list is: ");
    printLL(head);
}