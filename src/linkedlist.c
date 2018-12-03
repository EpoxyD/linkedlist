#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linkedlist.h"

llist_t * ll_init()
{
    llist_t * new = malloc(sizeof(llist_t));
    new->prev = new;
    new->next = new;
    new->value = NULL;
    return new;
}

void ll_add(llist_t* ll, void* value, int value_size)
{
    if(!ll) perror("init linkedlist");

    llist_t *it = ll;
    while(it->next != ll) {
        it = it->next;
    }
    it->next = ll_init();
    it->next->prev = it;
    it->next->next = ll;
    it->next->value = malloc(value_size);
    memcpy(it->next->value, value, value_size);
    return;
}

void ll_print(llist_t *ll, void (*print_callback)(void *value))
{
    llist_t *it = ll;
    if (!it) return;

    it = it->next;
    while (it != ll)
    {
        print_callback(it);
        it = it->next;
    }
}

// bool llist_add(void *value)
// {
//     llist_t *new = (llist_t *)value;
//     llist_t *it = firstvalue;

//     if (!new)
//     {
//         return false;
//     }

//     new->next = NULL;
//     new->prev = NULL;

//     if (!it)
//     {
//         firstvalue = new;
//         return true;
//     }

//     while (it->next)
//     {
//         it = it->next;
//     }

//     it->next = value;
//     it->next->prev = it;
//     return true;
// }

// bool llist_delete(void *value)
// {
//     llist_t *it = firstvalue;
//     if (!it)
//     {
//         return false;
//     }

//     while (it && it != value)
//     {
//         it = it->next;
//     }

//     if (it->prev)
//     {
//         it->prev->next = it->next;
//     }
//     else
//     {
//         firstvalue = it->next;
//     }

//     if (it->next)
//     {
//         it->next->prev = it->prev;
//     }

//     return true;
// }
