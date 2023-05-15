#include <assert.h>
#include <stdio.h>

#include "Heap.h"

int main(void)
{
    const uint32_t capacity = 10u;
    heap_t *heap = createHeap(capacity);

    insertValue(heap, 42.0f);
    insertValue(heap, 22.0f);
    insertValue(heap, 60.0f);
    insertValue(heap, 72.0f);
    insertValue(heap, -20.0f);

    assert(5u == heap->size);
    assert(10u == heap->capacity);
    assert(-20.0f == heap->data[0]);
    assert(22.0f == heap->data[1]);
    assert(60.0f == heap->data[2]);
    assert(72.0f == heap->data[3]);
    assert(42.0f == heap->data[4]);

    printf("Start printing:\n");
    printHeap(heap);

    removeMinimum(heap);

    printf("Start printing:\n");
    printHeap(heap);

    heap = freeHeap(heap);
    assert(NULL == heap);
}
