//In order traversal in Binary Search Tree 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *lchild, *rchild;
};

struct node *newnode(int data) { // create a new node 
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

struct node *insert(struct node *node, int value) { 
    if (node == NULL)
        return newnode(value); 

    if (value < node->value)
        node->lchild = insert(node->lchild, value);  
    else
        node->rchild = insert(node->rchild, value); 
    return node;


}

void Inorder(struct node *parent) {
    if (parent != NULL){
        Inorder(parent->lchild);
        printf("%d -> ", parent->value);
        Inorder(parent->rchild);
    }
}





int main(){
    struct node *parent = NULL;
    parent = insert(parent, 89);
    parent = insert(parent, 12);
    parent = insert(parent, 54);
    parent = insert(parent, 69);
    parent = insert(parent, 57);
    parent = insert(parent, 11);
    parent = insert(parent, 14);
    parent = insert(parent, 32);

    printf("Inorder traversal of Binary Search Tree: ");
    Inorder(parent); 


}
