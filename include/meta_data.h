/*
** EPITECH PROJECT, 2022
** meta_data
** File description:
** meta_data
*/

#pragma once
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct s_metaData {
    size_t size;
    struct s_metaData *next;
    struct s_metaData *before;
    bool free;
    void *address;
} *t_metaData;

extern void *heap_start;

t_metaData find_free_block(t_metaData *last_block, size_t size);
void split_free_block(t_metaData current_block, size_t size);
t_metaData add_block(t_metaData last_block, size_t size);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
