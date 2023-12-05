#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _snode {
    int val;
    struct _snode *next;
} SNode;


typedef struct _linked_list {
    SNode *begin;
    SNode *end;
    size_t size;
} LinkedList;

LinkedList *LinkedList_create(){
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

SNode *SNode_create(int val){
    SNode *p = (SNode*) calloc (1, sizeof(SNode));
    p->val = val;
    p->next = NULL; 

    return p;
}

// void LinkedList_add_first(LinkedList *L, int val){
//     SNode *p = SNode_create(val);
//     p->next = L->begin;
//     L->begin = p;
// }

void LinkedList_add_last_slow(LinkedList *L, int val){
    SNode *q = SNode_create(val);
    if (LinkedList_is_empty(L)) {
        L->begin = q;
    } 
    else {
        SNode *p = L->begin;
        while (p->next != NULL) {
            p = p->next;
        } 
        p->next = q;
    }

    L->size++;
}

void LinkedList_add_last(LinkedList *L, int val){
    SNode *q = SNode_create(val);
    if (LinkedList_is_empty(L)) {
        L->begin = L->end = q;
    } 
    else {
        L->end->next = q;
        L->end = q; 
    }

    L->size++;
}

void LinkedList_print(const LinkedList *L){
    SNode *p = L->begin;

    printf("L -> ");

    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
    printf("Size: %zu\n", L->size);
}

void LinkedList_add_first(LinkedList *L, int val){
    SNode *p = SNode_create(val);
    p->next = L->begin;

    if(LinkedList_is_empty(L)){
        L->end = p;
    }
    
    L->begin = p;
    L->size++;
}

bool LinkedList_is_empty(const LinkedList *L){
    return L->size == 0;
}

void LinkedList_remove(LinkedList *L, int val) {
    if(!LinkedList_is_empty(L)) { 
        if(L->begin->val == val) {
            SNode *pos = L->begin;

            if (L->begin == L->end) {
                L->end = NULL;
            }
            L->begin = L->begin->next;
            free(pos);

            L->size--;
        }
        else {
            SNode *prev = L->begin;
            SNode *pos = L->begin->next;

            while(pos->val != val && pos != NULL) {
                prev = prev->next;
                pos = pos->next;
            }
            if(pos != NULL) {
                prev->next = pos->next;
            
                if(pos->next == NULL) {
                    L->end = prev;
                }
                free(pos);
                L->size--;
            }
        }
    }
}

void LinkedList_destroy(LinkedList **L_ref){
    LinkedList *L = *L_ref;

    SNode *p = L->begin;
    SNode *aux = NULL;
    while(p != NULL) {
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}

size_t LinkedList_size_slow(const LinkedList *L){
    size_t size = 0;
    if(!LinkedList_is_empty(L)) {
        SNode *p = L->begin;
        
        while(p != NULL){
            size++;
            p = p->next;
        }
    }
    return size;

}

size_t LinkedList_size(const LinkedList *L){
    return L->size;
}

int LinkedList_first_val(const LinkedList *L){
    if(!LinkedList_is_empty(L)){
        return L->begin->val;
    }
    exit(EXIT_FAILURE);
}    

int LinkedList_last_val(const LinkedList *L){
    if(!LinkedList_is_empty(L)){
        return L->end->val;
    }
    exit(EXIT_FAILURE);
}

int LinkedList_get_val(const LinkedList *L, unsigned index){
    if(!LinkedList_is_empty(L)) {
        int i = 0;
        SNode *p = L->begin;

        while (i != index && p != L->end->next){
                p = p->next;
                i++;
            }
            return p->val;
    }
}