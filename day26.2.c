#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;


/** Initialize */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}


/** Get value at index */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size)
        return -1;

    Node* temp = obj->head;
    for(int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}


/** Add at head */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = val;
    newnode->next = obj->head;

    obj->head = newnode;
    obj->size++;
}


/** Add at tail */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = val;
    newnode->next = NULL;

    if(obj->head == NULL) {
        obj->head = newnode;
    } else {
        Node* temp = obj->head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    obj->size++;
}


/** Add at index */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index < 0 || index > obj->size)
        return;

    if(index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = val;

    Node* temp = obj->head;
    for(int i = 0; i < index - 1; i++)
        temp = temp->next;

    newnode->next = temp->next;
    temp->next = newnode;

    obj->size++;
}


/** Delete at index */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size)
        return;

    Node* temp = obj->head;

    if(index == 0) {
        obj->head = temp->next;
        free(temp);
    } else {
        for(int i = 0; i < index - 1; i++)
            temp = temp->next;

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        free(deleteNode);
    }

    obj->size--;
}


/** Free entire list */
void myLinkedListFree(MyLinkedList* obj) {
    Node* temp = obj->head;
    while(temp != NULL) {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(obj);
}