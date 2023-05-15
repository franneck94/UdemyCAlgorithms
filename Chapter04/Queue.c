#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

queue_t *createQueue(const uint32_t capacity)
{
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));

    if (NULL == queue)
    {
        return NULL;
    }

    const size_t data_size = capacity * sizeof(value_type_t);
    value_type_t *data = (value_type_t *)malloc(data_size);

    if (NULL == data)
    {
        free(queue);

        return NULL;
    }

    queue->front_idx = 0U;
    queue->back_idx = 0U;
    queue->size = 0U;
    queue->capacity = capacity;
    queue->data = data;

    return queue;
}

queue_t *freeQueue(queue_t *queue)
{
    if (NULL == queue)
    {
        return NULL;
    }

    if (NULL != queue->data)
    {
        free(queue->data);
    }

    free(queue);

    return NULL;
}

void printQueue(const queue_t *const queue)
{
    if (NULL == queue)
    {
        return;
    }

    printf("Queue has a size of %u and a capactiy of %u\n",
           queue->size,
           queue->capacity);

    for (uint32_t i = 0; i < queue->size; i++)
    {
        const uint32_t idx = (i + queue->front_idx) % queue->capacity;

        printf("Element %u at Index %u with Value %f\n",
               i,
               idx,
               queue->data[idx]);
    }
}

bool isFull(const queue_t *const queue)
{
    return queue->size >= queue->capacity;
}

bool isEmpty(const queue_t *const queue)
{
    return queue->size == 0u;
}

void push(queue_t *const queue, const value_type_t value)
{
    if (isFull(queue))
    {
        return;
    }

    if (queue->size > 0)
    {
        queue->back_idx = (queue->back_idx + 1u) % queue->capacity;
    }
    else
    {
        queue->front_idx = 0U;
        queue->back_idx = 0U;
    }

    queue->data[queue->back_idx] = value;
    queue->size++;
}

value_type_t pop(queue_t *const queue)
{
    if (isEmpty(queue))
    {
        return NO_VALUE;
    }

    const value_type_t value = queue->data[queue->front_idx];

    if (queue->size > 1)
    {
        queue->front_idx = (queue->front_idx + 1U) % queue->capacity;
    }
    else
    {
        queue->front_idx = 0U;
        queue->back_idx = 0U;
    }
    queue->size--;

    return value;
}

value_type_t front(queue_t *const queue)
{
    if (isEmpty(queue))
    {
        return NO_VALUE;
    }

    return queue->data[queue->front_idx];
}

value_type_t back(queue_t *const queue)
{
    if (isEmpty(queue))
    {
        return NO_VALUE;
    }

    return queue->data[queue->back_idx];
}
