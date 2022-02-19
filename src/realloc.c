/*
** EPITECH PROJECT, 2022
** realloc
** File description:
** realloc
*/

#include "../include/meta_data.h"

void *realloc(void *ptr, size_t size)
{
    t_metaData current_block;
    void *new_ptr = NULL;

    if (ptr == NULL && size != 0)
        return (malloc(size));
    current_block = (t_metaData) ptr - 1;
    if (current_block->address != ptr)
        return (ptr);
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    if (current_block->size == size)
        return (ptr);
    new_ptr = malloc(size);
    if (new_ptr != ptr && size < current_block->size)
        memcpy(new_ptr, ptr, size);
    else if (new_ptr != ptr)
        memcpy(new_ptr, ptr, current_block->size);
    free(ptr);
    return (new_ptr);
}
