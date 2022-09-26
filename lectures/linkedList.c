#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next; 
};

int main(){
    struct node *head = NULL; 

    // allocate memory to the head node
    head = (struct node*)malloc(sizeof(struct node)); 

    // Values given: 0 (head pointer), 1-9 (for loop)
    head->data = 0;
    head->next = NULL;
    printf("%d\n",head->data);

    struct node *temp = malloc(sizeof(struct node));
    for (int i = 1; i < 10; ++i){
        temp->data = i;
        temp->next = NULL;
        head->next = temp;
        head = temp;
        printf("%d\n",temp->data);
    }
    
    return 0;
}