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
}

bool isFull(const queue_t *const queue)
{
    return queue->size >= queue->capacity;
}

bool isEmpty(const queue_t *const queue)
{
    return queue->size == 0u;
}
