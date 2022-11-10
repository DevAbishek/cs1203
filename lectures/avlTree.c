#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    int height;
    struct node *left;
    struct node *right;
};

int max(int x, int y) {
    if (x > y) {
        return x;
    }
    return y;
}

int getHeight(struct node *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

struct node *nodeCreate(int value) {
    struct node *nodeNew = (struct node *)malloc(sizeof(struct node));
    nodeNew->value = value;
    nodeNew->height = 1;
    nodeNew->left = NULL;
    nodeNew->right = NULL;
    return nodeNew;
}

int DiffTreeHeight(struct node *node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

struct node *rotateRight(struct node *node) {
    struct node *subTreeLeft = node->left;
    struct node *rightSubTreeLeft = subTreeLeft->left;

    subTreeLeft->right = node;
    node->left = rightSubTreeLeft;

    node->height = 1 + max(getHeight(node->right), getHeight(node->left));
    subTreeLeft->height =  1 + max(getHeight(subTreeLeft->right), getHeight(subTreeLeft->left));

    return subTreeLeft;
}

struct node *rotateLeft(struct node *node) {
    struct node *subtreeRight = node->right;
    struct node *leftSubTreeRight = subtreeRight->left;

    subtreeRight->left = node;
    node->right = leftSubTreeRight;

    node->height = 1 + max(getHeight(node->right), getHeight(node->left));
    subtreeRight->height =  1 + max(getHeight(subtreeRight->right), getHeight(subtreeRight->left));

    return subtreeRight;
}

struct node *nodeInsert(struct node *topPos, int val) {
    if (topPos == NULL) {
        return nodeCreate(val);
    }

    if (val < topPos->value) {
        topPos->left = nodeInsert(topPos->left, val);
    } else if (val > topPos->value) {
        topPos->right = nodeInsert(topPos->right, val);
    } else {
        return topPos;
    }

    topPos->height = 1 + max(getHeight(topPos->left), getHeight(topPos->right));

    int diffHeight = DiffTreeHeight(topPos);

    if (diffHeight > 1 && val < topPos->left->value) {
        return rotateRight(topPos);
    }

    if (diffHeight < -1 && val > topPos->right->value) {
        return rotateLeft(topPos);
    }

    if (diffHeight > 1 && val > topPos->left->value) {
        topPos->left = rotateLeft(topPos->left);
        return rotateRight(topPos);
    }

    if (diffHeight < -1 && val < topPos->right->value) {
        topPos->right = rotateRight(topPos->right);
        return rotateLeft(topPos);
    }

    return topPos;
}

void treePrint(struct node *topPos) {
    if (topPos == NULL) {
        return;
    }
    printf("%d ", topPos->value);
    treePrint(topPos->left);
    treePrint(topPos->right);
}

int main (void) {
    struct node *topPos = NULL;

    int k = -1;
    for (int i = 0; i < 50; i+=3) {
        topPos = nodeInsert(topPos, i * k);
        k = k * -1;
    }
    
    treePrint(topPos);
    printf("\n");

    return 0;
}