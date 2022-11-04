#include <stdio.h>
#include <stdlib.h>

struct ll {
    int data;
    struct ll *next;
};

struct ll *createNode(int data) {
    struct ll *temp = (struct ll *)malloc(sizeof(struct ll));
    if (temp == NULL){
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct ll *arrayToLL(int *arr, int size) {
    struct ll *head = createNode(arr[0]);

    if (head == NULL) {
        return NULL;
    }
    struct ll *current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

struct ll *nodeEnd(struct ll *head) {
    if (head == NULL) {
        return head;
    }
    struct ll *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

struct ll *quickSortFn(struct ll *head, struct ll *last) {
    struct ll *pivot = head;
    struct ll *current = head;
    int temp = 0;

    while (current != last) {
        if (current->data < last->data)
        {
            pivot = head;
            temp = pivot->data;
            head->data = current->data;
            current->data = temp;

            head = head->next;
        }
        current = current->next;
    }
    temp = last->data;
    last->data = head->data;
    head->data = temp;
    return pivot;
}
void printLL(struct ll *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
}

void quickSort(struct ll *head, struct ll *last) {
    if (head == last) return;
    struct ll *part = quickSortFn(head, last);
    quickSort(head, part);
    quickSort(part->next, last);
}

int main() {
    int arr[] = {87, 34, 65, 23, 11, 90};
    int size = 6;

    struct ll *ll = arrayToLL(arr, size);
    struct ll *last = nodeEnd(ll);

    quickSort(ll, last); 
    printLL(ll);       
}