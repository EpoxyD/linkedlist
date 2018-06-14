#pragma once

#include <stdbool.h>

typedef struct llist llist_t;

struct llist
{
    llist_t *next;
    llist_t *prev;
};

bool llist_add(void *newvalue);
void llist_print();