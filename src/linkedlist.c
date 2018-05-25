#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

void llist_init(llist_t *ll)
{
    ll->next = NULL;
    ll->prev = NULL;
}

void llist_add(llist_t *ll, void *value)
{
    llist_t *item = (llist_t *)value;
    llist_t *last = ll;
    while(last)
    {
        last = last->next;
    }
    last->next = item;
}

void llist_print(llist_t *ll)
{
    llist_t *item = ll;
    while(item)
    {
        printf("[Prev] %-10p [Next] %-10p\n", item->prev, item->next);
        item = item->next;
    }
}