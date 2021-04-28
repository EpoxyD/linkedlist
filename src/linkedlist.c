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
    if(node == NULL)
        return false;
    if(value == NULL)
        return false;
    node_t *new = node_allocate(node);
    new->size = value_size;
    new->value = (void *)value;
    return true;
}

bool node_del(node_t *node, const void *value)
{
    if(node == NULL)
        return false;
    if(value == NULL)
        return false;
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
