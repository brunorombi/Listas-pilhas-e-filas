#include "linked_list.h"
#include <stdio.h>

int main() {

    LinkedList *L = LinkedList_create();
    
    LinkedList_add_first(L, 10);
    LinkedList_add_first(L, 9);
    LinkedList_add_first(L, 8);
    LinkedList_add_first(L, 7);
    LinkedList_print(L);
    

    // LinkedList_destroy(&L);
    // printf("L == NULL: %d\n", L == NULL);

    // printf("Tamanho da lista: %zu \n", LinkedList_size_slow(L));
    // printf("tamanho da lista: %zu\n", LinkedList_size(L));
    // printf("primeiro elemento %d\n",LinkedList_first_val(L));
    // printf("ultimo elemento %d\n",LinkedList_last_val(L));
    printf("elemento pedido: %d\n", LinkedList_get_val(L, 3));
    printf("primeiro elemento = %d\n", LinkedList_first_val(L));
    printf("ultimo elemento = %d\n", LinkedList_last_val(L));


    LinkedList_destroy(&L);

    return 0;
}