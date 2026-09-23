#include "structures.h"
#include <stdlib.h>

bool stack_push(Stack *s, int value) {
    if (s->size == CAPACITY) return false;
    s->values[s->size++] = value;
    return true;
}
bool stack_pop(Stack *s, int *value) {
    if (s->size == 0) return false;
    *value = s->values[--s->size];
    return true;
}
bool queue_enqueue(Queue *q, int value) {
    if (q->size == CAPACITY) return false;
    q->values[(q->front + q->size) % CAPACITY] = value;
    q->size++;
    return true;
}
bool queue_dequeue(Queue *q, int *value) {
    if (q->size == 0) return false;
    *value = q->values[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->size--;
    return true;
}
bool list_append(Node **head, int value) {
    Node *node = malloc(sizeof *node);
    if (!node) return false;
    node->value = value;
    node->next = NULL;
    while (*head) head = &(*head)->next;
    *head = node;
    return true;
}
bool list_remove(Node **head, int value) {
    while (*head && (*head)->value != value) head = &(*head)->next;
    if (!*head) return false;
    Node *removed = *head;
    *head = removed->next;
    free(removed);
    return true;
}
void list_free(Node **head) {
    while (*head) {
        Node *next = (*head)->next;
        free(*head);
        *head = next;
    }
}
void insertion_sort(int *values, size_t length) {
    for (size_t i = 1; i < length; i++) {
        int key = values[i];
        size_t j = i;
        while (j > 0 && values[j-1] > key) {
            values[j] = values[j-1];
            j--;
        }
        values[j] = key;
    }
}
