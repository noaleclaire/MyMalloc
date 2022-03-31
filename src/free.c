/*
** EPITECH PROJECT, 2022
** free
** File description:
** free
*/

#include "../include/meta_data.h"

t_meta_data fusion_free_block(t_meta_data current_block)
{
    current_block->size += sizeof(struct s_meta_data)
    + current_block->next->size;
    current_block->next = current_block->next->next;
    if (current_block->next != NULL)
        current_block->next->before = current_block;
    return (current_block);
}

void free(void *ptr)
{
    t_meta_data current_block;
    int multiple_page = (2 * getpagesize());
    if (ptr == NULL || ptr < heap_start || ptr > sbrk(0))
        return;
    current_block = (t_meta_data) ptr - 1;
    if (current_block->address != ptr)
        return;
    current_block->free = true;
    if (current_block->next && current_block->next->free)
        current_block = fusion_free_block(current_block);
    if (current_block->before->free)
        current_block = fusion_free_block(current_block->before);
    if (current_block->next == NULL) {
        current_block->before->next = NULL;
        while (multiple_page <= current_block->size +
        sizeof(struct s_meta_data))
            multiple_page *= 2;
        multiple_page -= current_block->size + sizeof(struct s_meta_data);
        sbrk(-multiple_page -current_block->size -sizeof(struct s_meta_data));
    }
}
