#include "linked_list.h"


int main() {

    LinkedList *L = LinkedList_create();
    
    LinkedList_add_first(L, 10);
    LinkedList_add_first(L, 9);
    LinkedList_add_first(L, 8);
    LinkedList_print(L);

    return 0;
}