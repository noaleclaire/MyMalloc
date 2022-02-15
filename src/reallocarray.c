/*
** EPITECH PROJECT, 2022
** reallocarray
** File description:
** reallocarray
*/

#include "../include/meta_data.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return (realloc(ptr, nmemb * size));
}
