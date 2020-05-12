#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linkedlist.h"

static node_t *node_allocate(node_t **node)
{
    if (*node == NULL)
    {
        (*node) = calloc(1, sizeof(node_t));
        (*node)->next = NULL;
        (*node)->prev = NULL;
        return *node;
    }
    else
    {
        node_t *last = *node;
        while (last->next)
            last = last->next;
        last->next = calloc(1, sizeof(node_t));
        last->next->next = NULL;
        last->next->prev = last;
        return last->next;
    }
}

bool node_add(node_t **node, const void *value, const int value_size)
{
    node_t *new = node_allocate(node);
    new->size = value_size;
    new->value = calloc(1, value_size);
    if (!memcpy(new->value, value, value_size))
    {
        new->prev->next = NULL;
        free(new);
        return false;
    }
    return true;
}

bool node_del(node_t *node, const void *value)
{
    node_t *iter = node;
    while (iter)
    {
        if (memcmp(value, iter->value, iter->size))
        {
            iter = iter->next;
            continue;
        }
        if (iter->prev)
            iter->prev->next = iter->next;
        if (iter->next)
            iter->next->prev = iter->prev;
        free(iter->value);
        iter->prev = NULL;
        iter->next = NULL;
        iter->value = NULL;
        free(iter);
        return true;
    }
    return false;
}

bool node_clean(node_t *node)
{
    while (node)
    {
        node_t *next = node->next;
        free(node->value);
        free(node);
        node = next;
    }
    return true;
}

void node_print(node_t *node, void (*print_callback)(const node_t *node))
{
    node_t *tmp = node;
    while (tmp)
    {
        print_callback(tmp);
        tmp = tmp->next;
    }
}

// llist_t * ll_init()
// {
//     llist_t * new = malloc(sizeof(llist_t));
//     new->prev = new;
//     new->next = new;
//     new->value = NULL;
//     return new;
// }

// void ll_add(llist_t* ll, void* value, int value_size)
// {
//     if(!ll) perror("init linkedlist");

//     llist_t *it = ll;
//     while(it->next != ll) {
//         it = it->next;
//     }
//     it->next = ll_init();
//     it->next->prev = it;
//     it->next->next = ll;
//     it->next->value = malloc(value_size);
//     memcpy(it->next->value, value, value_size);
//     return;
// }

// void ll_print(llist_t *ll, void (*print_callback)(void *value))
// {
//     llist_t *it = ll;
//     if (!it) return;

//     it = it->next;
//     while (it != ll)
//     {
//         print_callback(it);
//         it = it->next;
//     }
// }