#include <assert.h>
#include <stdio.h>

#include "DoubleLinkedList.h"

int main(void)
{
    list_t *list = createList();
    assert(NULL != list);

    node_t *a = createNode(1.0f);
    node_t *b = createNode(2.0f);
    node_t *c = createNode(3.0f);
    assert(NULL != a);
    assert(NULL != b);
    assert(NULL != c);

    assert(NULL == a->next);
    assert(NULL == a->prev);
    assert(1.0f == *a->value);
    assert(2.0f == *b->value);
    assert(3.0f == *c->value);

    pushBack(list, a);
    assert(list->front == a);
    assert(list->back == a);
    assert(list->front->next == NULL);
    assert(list->front->prev == NULL);
    assert(list->back->next == NULL);
    assert(list->back->prev == NULL);
    assert(1u == list->size);

    pushBack(list, b);
    assert(list->front == a);
    assert(list->back == b);
    assert(list->front->next == b);
    assert(list->front->prev == NULL);
    assert(list->back->next == NULL);
    assert(list->back->prev == a);
    assert(2u == list->size);

    pushBack(list, c);
    assert(list->front == a);
    assert(list->back == c);
    assert(list->front->next == b);
    assert(list->front->prev == NULL);
    assert(list->back->next == NULL);
    assert(list->back->prev == b);
    assert(b->next == c);
    assert(b->prev == a);
    assert(3u == list->size);

    printList(list);

    const value_type_t value_c = popBack(list);
    assert(3.0f == value_c);
    assert(list->front == a);
    assert(list->back == b);
    assert(list->front->next == b);
    assert(list->front->prev == NULL);
    assert(list->back->next == NULL);
    assert(list->back->prev == a);
    assert(b->next == NULL);
    assert(b->prev == a);
    assert(2u == list->size);

    const value_type_t value_b = popBack(list);
    assert(2.0f == value_b);
    assert(list->front == a);
    assert(list->back == a);
    assert(list->front->next == NULL);
    assert(list->front->prev == NULL);
    assert(list->back->next == NULL);
    assert(list->back->prev == NULL);
    assert(1u == list->size);

    const value_type_t value_a = popBack(list);
    assert(1.0f == value_a);
    assert(list->front == NULL);
    assert(list->back == NULL);
    assert(0u == list->size);

    node_t *d = createNode(4.0f);
    pushFront(list, d);
    assert(list->front == d);
    assert(list->back == d);
    assert(1u == list->size);

    node_t *e = createNode(5.0f);
    pushFront(list, e);
    assert(list->front == e);
    assert(list->back == d);
    assert(2u == list->size);
    printList(list);

    popNode(list, 0);
    assert(list->front == d);
    assert(list->back == d);
    assert(1u == list->size);

    (void)popFront(list);
    assert(NULL == list->front);
    assert(NULL == list->back);
    assert(0u == list->size);

    // Clean-Up
    freeNode(a);
    freeNode(b);
    freeNode(c);
    freeNode(d);
    freeNode(e);
    list = freeList(list);
    assert(NULL == list);

    return 0;
}
