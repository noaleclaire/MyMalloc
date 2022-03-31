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

typedef struct s_meta_data {
    size_t size;
    struct s_meta_data *next;
    struct s_meta_data *before;
    bool free;
    void *address;
} *t_meta_data;

extern void *heap_start;

t_meta_data find_free_block(t_meta_data *last_block, size_t size);
void split_free_block(t_meta_data current_block, size_t size);
t_meta_data add_block(t_meta_data last_block, size_t size);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);
size_t power_of_two(size_t size);
