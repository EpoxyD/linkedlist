#pragma once

#include <stdlib.h>

typedef struct llist llist_t;

struct llist
{
    llist_t *next;
    llist_t *prev;
};

void llist_init(llist_t *ll);
void llist_add(llist_t *ll, void * value);
void llist_print(llist_t *ll);