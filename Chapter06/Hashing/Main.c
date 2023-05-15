#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE (uint32_t)7u
#define MAX_NAME_SIZE (uint32_t)256u

uint32_t hash(const char key[MAX_NAME_SIZE])
{
    uint32_t hash_value = 0u;

    for (uint32_t i = 0u; i < MAX_NAME_SIZE; i++)
    {
        if ('\0' != key[i])
        {
            hash_value = (hash_value * 128u + key[i]) % TABLE_SIZE;
        }
        else
        {
            break;
        }
    }

    return hash_value;
}

int main()
{
    const char name1[] = "Jan";
    const char name2[] = "Maxi";
    const char name3[] = "Lena";
    const char name4[] = "Peter";
    const char name5[] = "Lara";

    printf("Key: %s, Idx: %u\n", name1, hash(name1));
    printf("Key: %s, Idx: %u\n", name2, hash(name2));
    printf("Key: %s, Idx: %u\n", name3, hash(name3));
    printf("Key: %s, Idx: %u\n", name4, hash(name4));
    printf("Key: %s, Idx: %u\n", name5, hash(name5));
}
