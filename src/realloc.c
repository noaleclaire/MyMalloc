/*
** EPITECH PROJECT, 2022
** realloc
** File description:
** realloc
*/

#include "../include/meta_data.h"

#include <stdio.h>

void *realloc2(void *ptr, size_t size, size_t tmp_size,
t_meta_data current_block)
{
    void *new_ptr = NULL;

    new_ptr = malloc(size);
    if (new_ptr == NULL)
        return (NULL);
    if (new_ptr != ptr && tmp_size < current_block->size)
        memcpy(new_ptr, ptr, tmp_size);
    else if (new_ptr != ptr)
        memcpy(new_ptr, ptr, current_block->size);
    free(ptr);
    return (new_ptr);
}

void *realloc(void *ptr, size_t size)
{
    t_meta_data current_block;
    size_t tmp_size = power_of_two(size);

    if (ptr == NULL)
        return (malloc(size));
    current_block = (t_meta_data) ptr - 1;
    if (current_block->address != ptr)
        return (ptr);
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    if (current_block->size == tmp_size)
        return (ptr);
    return (realloc2(ptr, size, tmp_size, current_block));
}
