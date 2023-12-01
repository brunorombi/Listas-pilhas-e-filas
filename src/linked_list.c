#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _snode {
    int val;
    struct _snode *next;
} SNode;


typedef struct _linked_list {
    SNode *begin;
} LinkedList;

LinkedList *LinkedList_create(){
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));
    L->begin = NULL;

    return L;
}

SNode *SNode_create(int val){
    SNode *p = (SNode*) calloc (1, sizeof(SNode));
    p->val = val;
    p->next = NULL;

    return p;
}

void LinkedList_add_first(LinkedList *L, int val){
    SNode *p = SNode_create(val);
    p->next = L->begin;
    L->begin = p;
}

void LinkedList_print(const LinkedList *L){
    SNode *p = L->begin;
    printf("L -> ");
    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL");
}