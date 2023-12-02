#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

LinkedList *LinkedList_create();
SNode *SNode_create(int val);
void LinkedList_add_first(LinkedList *L, int val);
void LinkedList_add_last_slow(LinkedList *L, int val);
void LinkedList_add_last(LinkedList *L, int val);
void LinkedList_print(const LinkedList *L);


#endif 