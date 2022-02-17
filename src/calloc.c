/*
** EPITECH PROJECT, 2022
** calloc
** File description:
** calloc
*/

#include "../include/meta_data.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;
    if (size == 0 || nmemb == 0)
        return (NULL);
    ptr = malloc(nmemb * size);
    if (ptr)
        memset(ptr, 0, nmemb * size);
    return (ptr);
}
