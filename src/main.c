#include "linkedlist.h"

typedef struct value value_t;

struct value {
    llist_t ll;
    int value;
};

int main(void)
{
    value_t* value = malloc(sizeof(value_t));
    value->value = 123456;

    llist_t *ll;
    llist_init(ll);
    llist_add(ll, &value);
    llist_print(ll);
    return 0;
}
