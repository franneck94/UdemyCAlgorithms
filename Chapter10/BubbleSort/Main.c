#include <stdint.h>
#include <stdio.h>

typedef float value_type_t;

void printArray(value_type_t arr[], const uint32_t size)
{
    for (uint32_t i = 0u; i < size; i++)
    {
        if (i < size - 1u)
        {
            printf("%f, ", arr[i]);
        }
        else
        {
            printf("%f\n", arr[i]);
        }
    }
}

void swap(value_type_t *a, value_type_t *b)
{
    const value_type_t temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(value_type_t arr[], const uint32_t size)
{
    for (uint32_t i = 0u; i < size - 1u; i++)
    {
        for (uint32_t j = 0u; j < size - i - 1u; j++)
        {
            if (arr[j] > arr[j + 1u])
            {
                swap(&arr[j], &arr[j + 1u]);
            }
        }
    }
}

int main(void)
{
    const uint32_t size = 5u;
    value_type_t data[] = {-10, 20, -20, 40, 12};

    printArray(data, size);
    bubbleSort(data, size);
    printArray(data, size);
}
