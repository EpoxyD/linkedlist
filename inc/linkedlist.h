#pragma once

#include <stdbool.h>

typedef struct node node_t;

struct node
{
    node_t *next;
    node_t *prev;
    const void *value;
    int size;
};

bool node_add(node_t **node, const void *value, const int value_size);
bool node_del(node_t *node, const void *value);
bool node_clean(node_t *node);

void node_print(node_t *node, void (*print_callback)(const node_t *value));