#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct {
    struct Node *dummy;
    int size;
} MyLinkedList;

/** Initialize object */
MyLinkedList* myLinkedListCreate(void) {
    MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    obj->dummy = (struct Node *)malloc(sizeof(struct Node));
    obj->dummy->next = NULL;
    obj->size = 0;
    return obj;
}

/** Helper: get pointer to node at index, or NULL if invalid */
static struct Node* getNodeAt(MyLinkedList *obj, int index) {
    if (index < 0 || index >= obj->size) return NULL;
    struct Node *cur = obj->dummy->next;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur;
}

int myLinkedListGet(MyLinkedList *obj, int index) {
    struct Node *node = getNodeAt(obj, index);
    return node ? node->data : -1;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = obj->dummy->next;
    obj->dummy->next = ptr;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = NULL;

    struct Node *p = obj->dummy;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val) {
    if (index > obj->size) return;      // too far,
    if (index < 0) index = 0;           // (LeetCode treats negative index as 0)

    struct Node *prev = obj->dummy;
    for (int i = 0; i < index; i++) {
        prev = prev->next;
    }

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = prev->next;
    prev->next = ptr;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index) {
    if (index < 0 || index >= obj->size) return;

    struct Node *prev = obj->dummy;
    for (int i = 0; i < index; i++) {
        prev = prev->next;
    }
    struct Node *toDelete = prev->next;
    prev->next = toDelete->next;
    free(toDelete);
    obj->size--;
}

/** Free everything */
void myLinkedListFree(MyLinkedList *obj) {
    struct Node *cur = obj->dummy;
    while (cur != NULL) {
        struct Node *next = cur->next;
        free(cur);
        cur = next;
    }
    free(obj);
}

