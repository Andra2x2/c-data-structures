#include <assert.h>
#include <stdio.h>
#include "structures.h"
int main(void) {
    Stack s = {0}; Queue q = {0}; int value = 0; Node *head = NULL;
    assert(!stack_pop(&s,&value));
    for(int i=0;i<CAPACITY;i++) assert(stack_push(&s,i));
    assert(!stack_push(&s,99));
    for(int i=CAPACITY-1;i>=0;i--){assert(stack_pop(&s,&value));assert(value==i);}
    assert(!queue_dequeue(&q,&value));
    for(int i=0;i<CAPACITY;i++) assert(queue_enqueue(&q,i));
    assert(!queue_enqueue(&q,99));
    for(int i=0;i<CAPACITY;i++){assert(queue_dequeue(&q,&value));assert(value==i);assert(queue_enqueue(&q,i+10));}
    for(int i=0;i<CAPACITY;i++){assert(queue_dequeue(&q,&value));assert(value==i+10);}
    assert(list_append(&head,10));assert(list_append(&head,20));assert(list_append(&head,30));
    assert(!list_remove(&head,99));assert(list_remove(&head,20));
    assert(head->next->value==30);assert(list_remove(&head,10));
    list_free(&head);assert(head==NULL);
    int a[]={3,-1,3,0};int expected[]={-1,0,3,3};
    insertion_sort(a,4);for(int i=0;i<4;i++)assert(a[i]==expected[i]);
    insertion_sort(NULL,0);
    puts("All C structure checks passed");return 0;
}
