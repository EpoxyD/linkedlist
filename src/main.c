#include "linkedlist.h"

typedef struct test
{
    llist_t *node;
    char *key;
    int value;
} test_t;

int main(void)
{
    test_t test1;
    test_t test2;
    test_t test3;

    llist_add(&test1);
    llist_add(&test2);
    llist_add(&test3);

    llist_print();
}
