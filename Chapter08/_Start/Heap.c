#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Heap.h"

heap_t *createHeap(const uint32_t capacity)
{
    heap_t *heap = (heap_t *)malloc(sizeof(heap_t));

    if (NULL == heap)
    {
        return NULL;
    }

    const size_t data_size = capacity * sizeof(value_type_t);
    value_type_t *data = (value_type_t *)malloc(data_size);

    if (NULL == data)
    {
        free(heap);

        return NULL;
    }

    heap->capacity = capacity;
    heap->size = 0u;
    heap->data = data;

    return heap;
}

heap_t *freeHeap(heap_t *heap)
{
    if (NULL != heap->data)
    {
        free(heap->data);
    }

    if (NULL != heap)
    {
        free(heap);
    }

    return NULL;
}

void printHeap(const heap_t *const heap)
{
    if (NULL == heap)
    {
        return;
    }
}
