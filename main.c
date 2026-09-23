#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
int main(void) {
    Stack stack = {0}; Queue queue = {0}; Node *list = NULL; int value;
    for (int i=1; i<=3; i++) {
        stack_push(&stack,i*10); queue_enqueue(&queue,i*10);
        if (!list_append(&list,i*10)) { list_free(&list); fputs("Allocation failed\n",stderr); return EXIT_FAILURE; }
    }
    printf("Stack (LIFO):");
    while (stack_pop(&stack,&value)) printf(" %d",value);
    printf("\nQueue (FIFO):");
    while (queue_dequeue(&queue,&value)) printf(" %d",value);
    list_remove(&list,20);
    printf("\nList after removing 20:");
    for (Node *node=list; node; node=node->next) printf(" %d",node->value);
    list_free(&list);
    int values[]={42,12,8,25,3}; insertion_sort(values,5);
    printf("\nInsertion sort:");
    for (size_t i=0; i<5; i++) printf(" %d",values[i]);
    putchar('\n'); return EXIT_SUCCESS;
}
