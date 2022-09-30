#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next; 
};

int main() {

    int n;
    printf("enter size of linked list\n");
    scanf("%d", &n);

    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("enter head value\n");
    int rand;
    scanf("%d", &rand);
    head->data = rand;
    head->next = NULL;
    struct node *s;
    s = head;

    while (n != 1) {
        int data;
        printf("enter data linked list\n");
        scanf("%d", &data);

        struct node *f;
        f = (struct node *)malloc(sizeof(struct node));

        f->data = data;
        f->next = NULL;

        s->next = f;
        s = f;
        n = n - 1;
    }

    printf("\n");

    struct node *hare;
    struct node *tortoise;
    hare = head;
    tortoise = head;
    while (hare != NULL) {
        printf("%d\n", tortoise->data);
        hare = hare->next;
        hare = hare->next;
        tortoise = tortoise->next;
    }

    return 0;
}
