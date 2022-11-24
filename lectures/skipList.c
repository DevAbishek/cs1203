#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define SKIPLIST_MAX_LEVEL 6

typedef struct node {
    int key;
    int value;
    struct node **forward;
} node;

typedef struct sl {
    int level;
    struct node *header;
} sl;

sl *createSL(sl *list) {
    int i;
    node *header = (node *) malloc(sizeof(struct node));
    list->header = header;
    header->key = INT_MAX;
    header->forward = (node **) malloc(
            sizeof(node*) * (SKIPLIST_MAX_LEVEL + 1));
    for (i = 0; i <= SKIPLIST_MAX_LEVEL; i++) {
        header->forward[i] = list->header;
    }

    list->level = 1;

    return list;
}

static int lvlRandom() {
    int level = 1;
    while (rand() < RAND_MAX / 2 && level < SKIPLIST_MAX_LEVEL)
        level++;
    return level;
}

int insertSL(sl *list, int key, int value) {
    node *update[SKIPLIST_MAX_LEVEL + 1];
    node *x = list->header;
    int i, level;
    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
        update[i] = x;
    }
    x = x->forward[1];

    if (key == x->key) {
        x->value = value;
        return 0;
    } else {
        level = lvlRandom();
        if (level > list->level) {
            for (i = list->level + 1; i <= level; i++) {
                update[i] = list->header;
            }
            list->level = level;
        }

        x = (node *) malloc(sizeof(node));
        x->key = key;
        x->value = value;
        x->forward = (node **) malloc(sizeof(node*) * (level + 1));
        for (i = 1; i <= level; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
    return 0;
}

node *searchSL(sl *list, int key) {
    node *x = list->header;
    int i;
    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
    }
    if (x->forward[1]->key == key) {
        return x->forward[1];
    } else {
        return NULL;
    }
    return NULL;
}

static void freeNodeSL(node *x) {
    if (x) {
        free(x->forward);
        free(x);
    }
}

int delSL(sl *list, int key) {
    int i;
    node *update[SKIPLIST_MAX_LEVEL + 1];
    node *x = list->header;
    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
        update[i] = x;
    }

    x = x->forward[1];
    if (x->key == key) {
        for (i = 1; i <= list->level; i++) {
            if (update[i]->forward[i] != x)
                break;
            update[i]->forward[i] = x->forward[i];
        }
        freeNodeSL(x);

        while (list->level > 1 && list->header->forward[list->level]
                == list->header)
            list->level--;
        return 0;
    }
    return 1;
}

void freeSL(sl *list)
{
    node *current_node = list->header->forward[1];
    while(current_node != list->header) {
        node *next_node = current_node->forward[1];
        free(current_node->forward);
        free(current_node);
        current_node = next_node;
    }
    free(current_node->forward);
    free(current_node);
    free(list);
}

static void dumpSL(sl *list) {
    node *x = list->header;
    while (x && x->forward[1] != list->header) {
        printf("%d[%d]->", x->forward[1]->key, x->forward[1]->value);
        x = x->forward[1];
    }
    printf("NIL\n");
}

int main() {
    int arr[] = { 58, 36, 98, 23, 1, 90, 52, 8 }, i;
    sl * list;
    list = (sl *)malloc(sizeof(sl));
    createSL(list);

    printf("Insert\n");
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        insertSL(list, arr[i], arr[i]);
    }
    dumpSL(list);

    printf("Search\n");
    int keys[] = { 121, 3, 8, 36, 24 };

    for (i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        node *x = searchSL(list, keys[i]);
        if (x) {
            printf("key = %d | value = %d\n", keys[i], x->value);
        } else {
            printf("key = %d | absent\n", keys[i]);
        }
    }
    delSL(list, 3);
    delSL(list, 9);
    dumpSL(list);
    freeSL(list);

    return 0;
}