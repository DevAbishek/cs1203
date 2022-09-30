#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ll {
    int val;
    struct ll *next;
};

struct ll *rev(struct ll *head, int k) {

    struct ll *pres = (struct ll *)malloc(sizeof(struct ll));
    struct ll *nex = (struct ll *)malloc(sizeof(struct ll));
    struct ll *prev = (struct ll *)malloc(sizeof(struct ll));
    prev = NULL;
    pres = head;
    nex = NULL;
    int counter;
    counter = 0;

    while (pres != NULL & counter < k) {
        nex = pres->next;
        pres->next = prev;
        prev = pres;
        pres = nex;
        counter++;
    }
    if (nex != NULL)
        head->next = rev(nex, k);

    return (prev);
}

int main() {

    int n;
    printf("enter size of linked list\n");
    scanf("%d", &n);

    struct ll *head = (struct ll *)malloc(sizeof(struct ll));
    printf("enter head value\n");
    int rand;
    scanf("%d", &rand);
    head->val = rand;
    head->next = NULL;
    struct ll *s;
    s = head;

    while (n != 1)
    {

        int data;
        printf("enter data linked list\n");
        scanf("%d", &data);

        struct ll *f;
        f = (struct ll *)malloc(sizeof(struct ll));

        f->val = data;
        f->next = NULL;

        s->next = f;
        s = f;
        n = n - 1;
    }
    int k;
    printf("enter chunk size to reverse\n");
    scanf("%d\n", &k);

    head = rev(head, k);

    struct ll *p;
    p = head;
    while (p != NULL)
    {
        printf("%d\n", p->val);
        p = p->next;
    }
}