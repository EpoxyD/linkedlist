#pragma once

#include <stdlib.h>

typedef struct llist llist_t;

struct llist
{
    llist_t *next;
    llist_t *prev;
    void *value;
};

void llist_addValue(llist_t **ll, void *value);
void llist_print(llist_t *ll);
void llist_free(llist_t *ll);