#pragma once

typedef struct llist llist_t;

struct llist
{
    llist_t *next;
    llist_t *prev;
    void * value;
};

llist_t * ll_init();
void ll_add(llist_t* ll, void* value, int value_size);
void ll_print(llist_t *ll, void (*print_callback)(void *value));

// bool llist_add(void *value);
// bool llist_delete(void *value);
// void llist_print(void (*print_callback)(void *value));