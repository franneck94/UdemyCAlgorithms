#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint32_t matrix[3][2] = {{0, 1}, {2, 3}, {4, 5}};

    for (uint32_t i = 0; i < 3; i++)
    {
        for (uint32_t j = 0; j < 2; j++)
        {
            printf("%u, %p\n", matrix[i][j], (void *)&matrix[i][j]);
        }
    }

    return 0;
}
