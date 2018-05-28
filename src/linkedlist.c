#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

void llist_addValue(llist_t **ll, void *value)
{
    llist_t *prev = NULL;
    while (*ll)
    {
        prev = *ll;
        ll = &((*ll)->next);
    }
    *ll = malloc(sizeof(llist_t));
    (*ll)->next = NULL;
    (*ll)->prev = prev;
    (*ll)->value = value;
}

void llist_print(llist_t *ll)
{
    llist_t *item = ll;
    while (item)
    {
        printf("[Prev] %-10p [Next] %-10p [Value] %-10d\n", item->prev, item->next, *((int *)(item->value)));
        item = item->next;
    }
}

void llist_free(llist_t *ll)
{
    llist_t *curr = ll;
    llist_t *next = curr->next;
    while(curr)
    {
        free(curr);
        curr = next;
        next = curr->next;
    }
}