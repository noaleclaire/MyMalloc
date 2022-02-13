/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/

#include "../include/meta_data.h"

void *heap_start = NULL;

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
    if (size == 0)
        return (NULL);
    t_metaData current_block;
    t_metaData last_block = NULL;

    if (size % 2 != 0)
        size += 1;
    size_t memorySize = size + sizeof(struct s_metaData);

    if (heap_start == NULL)
        heap_start = init_struct();
    if ((current_block = find_free_block(&last_block, size)) == NULL) {
        if ((current_block = increase_memory(last_block, memorySize)) == NULL)
            return (NULL);
    } else if (memorySize + sizeof(size_t) < current_block->size)
        split_free_block(current_block, memorySize);
    current_block->free = false;
    return (current_block->address);
}
