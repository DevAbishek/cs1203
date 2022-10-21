
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
};

struct node *insert(struct node *node, int value) { 
    if (node == NULL)
        return newnode(value); 

    if (value < node->value)
        node->lchild = insert(node->lchild, value);  
    else
        node->rchild = insert(node->rchild, value); 
    return node;
};

void Inorder(struct node *parent) {
    if (parent != NULL){
        Inorder(parent->lchild);
        printf("%d -> ", parent->value);
        Inorder(parent->rchild);
    }
}

struct node *Isuccessor(struct node *node){
    struct node *first = node;

    while (first && first->lchild != NULL)
    first = first->lchild;

    return first;

}

struct node *NodeDeletion(struct node *parent, int value)
{
    if (parent == NULL)
        return parent;

    if (value < parent->value)
        parent->lchild = NodeDeletion(parent->lchild, value);

    else if (value > parent->value)
        parent->rchild = NodeDeletion(parent->rchild, value);

    else
    {
        if (parent->lchild ==NULL)
        {
            struct node *temp = parent->rchild;
            free(parent);
            return temp;
        }
        else if (parent->rchild == NULL)
        {
            struct node *temp = parent->lchild;
            free(parent);
            return temp;
        }

    struct node *temp = Isuccessor(parent->rchild);
    parent->value = temp->value;
    parent->rchild = NodeDeletion(parent->rchild, temp->value);

}
    return parent;
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


    printf("\n Deleting 69\n");
    parent = NodeDeletion(parent, 69); 
    printf("Inorder traversal after deletion of a node in Binary Search Tree: ");
    Inorder(parent); 
}