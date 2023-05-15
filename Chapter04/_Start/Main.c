#include <assert.h>
#include <stdio.h>

#include "Queue.h"

int main(void)
{
    const uint32_t capacity = 4;
    queue_t *queue = createQueue(capacity);

    push(queue, 0.0f);
    push(queue, 1.0f);
    push(queue, 2.0f);
    push(queue, 3.0f);

    printQueue(queue);

    assert(0.0f == queue->data[queue->front_idx]);
    assert(1.0f == queue->data[queue->front_idx + 1u]);
    assert(2.0f == queue->data[queue->front_idx + 2u]);
    assert(3.0f == queue->data[queue->front_idx + 3u]);
    assert(4u == queue->capacity);
    assert(4u == queue->size);
    assert(NULL != queue);

    const value_type_t value_pop1 = pop(queue);
    const value_type_t value_pop2 = pop(queue);

    assert(2.0f == queue->data[queue->front_idx]);
    assert(3.0f == queue->data[queue->front_idx + 1u]);
    assert(0.0f == value_pop1);
    assert(1.0f == value_pop2);
    assert(4u == queue->capacity);
    assert(2u == queue->size);
    assert(NULL != queue);

    printQueue(queue);
    push(queue, -1.0f);
    printQueue(queue);

    const value_type_t value_pop3 = pop(queue);
    const value_type_t value_pop4 = pop(queue);
    const value_type_t value_pop5 = pop(queue);

    assert(2.0f == value_pop3);
    assert(3.0f == value_pop4);
    assert(-1.0f == value_pop5);
    assert(4u == queue->capacity);
    assert(0u == queue->size);
    assert(NULL != queue);

    printQueue(queue);

    queue = freeQueue(queue);
    assert(NULL == queue);
}
