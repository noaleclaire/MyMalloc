/*
** EPITECH PROJECT, 2022
** block
** File description:
** block
*/

#include "../include/meta_data.h"

t_metaData find_free_block(t_metaData *last_block, size_t size)
{
    t_metaData current_block = heap_start;
    t_metaData best_block = NULL;
    int i = 0;

    while (current_block) {
        if (i == 0 && current_block->free && current_block->size >= size) {
            best_block = current_block;
            i++;
        } else if (i != 0 && current_block->free &&
        current_block->size >= size && best_block->size > current_block->size)
            best_block = current_block;
        *last_block = current_block;
        current_block = current_block->next;
    }
    return (best_block);
}
// first_node 4 = |[----]-------------|  |------------------|
//second_node 5 = |[----][-----]--------|  |------------------|

t_metaData add_block(t_metaData last_block, size_t size)
{
    t_metaData current_block;

    if ((current_block = sbrk(size)) == (void*) - 1)
        return (NULL);
    current_block->size = size - sizeof(struct s_metaData);
    current_block->next = NULL;
    current_block->before = last_block;
    current_block->address = current_block + 1;
    last_block->next = current_block;
    return (current_block);
}

void split_free_block(t_metaData current_block, size_t size)
{
    t_metaData split_block = (t_metaData)((char*)current_block + size);
    split_block->size = current_block->size - size;
    split_block->next = current_block->next;
    split_block->before = current_block;
    split_block->free = true;
    split_block->address = split_block + 1;
    if (current_block->next)
        current_block->next->before = split_block;
    current_block->next = split_block;
    current_block->size = size - sizeof(struct s_metaData);
}
