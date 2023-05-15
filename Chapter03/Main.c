#include <assert.h>
#include <stdio.h>

#include "Stack.h"

int main(void)
{
    const uint32_t capacity = 4U;
    stack_t *stack = createStack(capacity);

    assert(NULL != stack);

    push(stack, 0.0F);
    push(stack, 1.0F);
    push(stack, 2.0F);
    push(stack, 3.0F);

    printStack(stack);

    assert(0.0F == stack->data[0]);
    assert(1.0F == stack->data[1]);
    assert(2.0F == stack->data[2]);
    assert(3.0F == stack->data[3]);
    assert(4U == stack->size);
    assert(4U == stack->capacity);
    assert(true == isFull(stack));
    assert(false == isEmpty(stack));

    const value_type_t top1 = top(stack);
    assert(3.0F == top1);

    const value_type_t pop1 = pop(stack);
    assert(3.0F == pop1);
    assert(3U == stack->size);
    assert(4U == stack->capacity);

    const value_type_t pop2 = pop(stack);
    assert(2.0F == pop2);
    assert(2U == stack->size);
    assert(4U == stack->capacity);

    const value_type_t pop3 = pop(stack);
    assert(1.0F == pop3);
    assert(1U == stack->size);
    assert(4U == stack->capacity);
}
