#pragma once

#include <stdbool.h>

typedef struct llist llist_t;

struct llist
{
    llist_t *next;
    llist_t *prev;
};

bool llist_add(void *value);
bool llist_delete(void *value);
void llist_print(void (*print_callback)(void *value));