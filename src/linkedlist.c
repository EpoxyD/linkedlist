#include <stdlib.h>

#include "linkedlist.h"

static llist_t *firstvalue = NULL;

bool llist_add(void *value)
{
    llist_t *new = (llist_t *)value;
    llist_t *it = firstvalue;

    if (!new)
    {
        return false;
    }

    new->next = NULL;
    new->prev = NULL;

    if (!it)
    {
        firstvalue = new;
        return true;
    }

    while (it->next)
    {
        it = it->next;
    }

    it->next = value;
    it->next->prev = it;
    return true;
}

bool llist_delete(void *value)
{
    llist_t *it = firstvalue;
    if (!it)
    {
        return false;
    }

    while (it && it != value)
    {
        it = it->next;
    }

    if (it->prev)
    {
        it->prev->next = it->next;
    }
    else
    {
        firstvalue = it->next;
    }

    if (it->next)
    {
        it->next->prev = it->prev;
    }

    return true;
}

void llist_print(void (*print_callback)(void *value))
{
    llist_t *it = firstvalue;
    if (!it)
    {
        return;
    }

    while (it)
    {
        print_callback(it);
        it = it->next;
    }
}