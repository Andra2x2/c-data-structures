#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <stdbool.h>
#include <stddef.h>
#define CAPACITY 5

typedef struct { int values[CAPACITY]; size_t size; } Stack;
typedef struct { int values[CAPACITY]; size_t front, size; } Queue;
typedef struct Node { int value; struct Node *next; } Node;
bool stack_push(Stack *s, int value);
bool stack_pop(Stack *s, int *value);
bool queue_enqueue(Queue *q, int value);
bool queue_dequeue(Queue *q, int *value);
bool list_append(Node **head, int value);
bool list_remove(Node **head, int value);
void list_free(Node **head);
void insertion_sort(int *values, size_t length);
#endif
