#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

LinkedList *LinkedList_create();
SNode *SNode_create(int val);
void LinkedList_destroy(LinkedList **L_ref);
void LinkedList_add_first(LinkedList *L, int val);
void LinkedList_add_last_slow(LinkedList *L, int val);
void LinkedList_add_last(LinkedList *L, int val);
void LinkedList_print(const LinkedList *L);
bool LinkedList_is_empty(const LinkedList *L);
void LinkedList_remove(LinkedList *L, int val);
size_t LinkedList_size_slow(const LinkedList *L);


#endif 