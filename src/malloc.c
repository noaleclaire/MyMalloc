/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/

#include "../include/meta_data.h"

void *heap_start = NULL;

size_t power_of_two(size_t size)
{
    size_t tmp = 1;

    while (tmp < size)
        tmp *= 2;
    return (tmp);
}

void *init_struct()
{
    t_metaData node = NULL;
    if (node == NULL) {
        if ((node = sbrk(sizeof(struct s_metaData))) == (void*) -1)
            return (NULL);
        node->size = 0;
        node->next = NULL;
        node->before = NULL;
        node->free = false;
        node->address = NULL;
    }
    return (node);
}

void *malloc(size_t size)
{
    t_metaData current_block;
    t_metaData last_block = NULL;
    size_t memorySize = 0;

    if (size == 0)
        return (NULL);
    size = power_of_two(size);
    memorySize = size + sizeof(struct s_metaData);

    if (heap_start == NULL)
        heap_start = init_struct();
    if ((current_block = find_free_block(&last_block, size)) == NULL) {
        if ((current_block = add_block(last_block, memorySize)) == NULL)
            return (NULL);
    } else if (memorySize + sizeof(size_t) < current_block->size)
        split_free_block(current_block, memorySize);
    current_block->free = false;
    return (current_block->address);
}
