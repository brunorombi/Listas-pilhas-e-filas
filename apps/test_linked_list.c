#include "linked_list.h"
#include <stdio.h>

int main() {

    LinkedList *L = LinkedList_create();
    
    LinkedList_add_first(L, 10);
    LinkedList_add_first(L, 9);
    LinkedList_add_first(L, 8);
    LinkedList_add_first(L, 7);
    LinkedList_print(L);

    LinkedList_remove(L, 10);
    LinkedList_print(L);

    LinkedList_remove(L, 8);
    LinkedList_print(L);

    LinkedList_add_last(L, 20);
    LinkedList_print(L);
    
    LinkedList_remove(L, 20);
    LinkedList_print(L);
    
    LinkedList_add_first(L, 8);
    LinkedList_print(L);

    LinkedList_remove(L, 8);
    LinkedList_print(L);

    LinkedList_destroy(&L);
    printf("L == NULL: %d\n", L == NULL);
    return 0;
}