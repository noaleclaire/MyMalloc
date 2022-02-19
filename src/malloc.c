/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/

#include "../include/meta_data.h"
#include <stdio.h>

void *heap_start = NULL;

size_t power_of_two(size_t size)
{
    size_t tmp = 1;

    while (tmp < size)
        tmp *= 2;
    return (tmp);
}

void *init_struct(void)
{
    t_metaData node = NULL;
    int multiple_page = (2 * getpagesize()) - sizeof(struct s_metaData);

    if (node == NULL) {
        if ((node = sbrk(multiple_page + sizeof(struct s_metaData)))
        == (void*) -1)
            return (NULL);
        node->size = 0;
        node->next = NULL;
        node->before = NULL;
        node->free = false;
        node->address = node + 1;
    }
    return (node);
}

void *malloc(size_t size)
{
    t_metaData current_block;
    t_metaData last_block = NULL;
    size_t memory_size = 0;

    if (size == 0)
        return (NULL);
    size = power_of_two(size);
    memory_size = size + sizeof(struct s_metaData);

    if (heap_start == NULL)
        heap_start = init_struct();
    if ((current_block = find_free_block(&last_block, size)) == NULL) {
        if ((current_block = add_block(last_block, memory_size)) == NULL)
            return (NULL);
    } else if (memory_size + sizeof(size_t) < current_block->size)
        split_free_block(current_block, memory_size);
    current_block->free = false;
    return (current_block->address);
}
