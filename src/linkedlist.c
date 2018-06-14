#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

static llist_t *firstvalue = NULL;

bool llist_add(void *newvalue)
{
    llist_t *new = (llist_t *) newvalue;
    llist_t *it = firstvalue;

    if(!new)
    {
        return false;
    }

    new->next = NULL;
    new->prev = NULL;

    if(!it)
    {
        firstvalue = new;
        return true;
    }

    while(it->next)
    {
        it = it->next;
    }

    it->next = newvalue;
    it->next->prev = it;
    return true;
}

void llist_print()
{
    llist_t *it = firstvalue;
    if(!it)
    {
        return;
    }

    while(it)
    {
        printf("[Address] %-20p [Previous] %-20p [Next] %-20p\n", it, it->prev, it->next);
        it = it->next;
    }
}