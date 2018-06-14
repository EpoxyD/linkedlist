#include "linkedlist.h"

#include <stdio.h>

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
    test_t test4;
    test_t test5;
    test_t test6;

    llist_add(&test1);
    llist_add(&test2);
    llist_add(&test3);
    llist_add(&test4);
    llist_add(&test5);
    llist_add(&test6);

    llist_print();
    printf("\n");

    llist_delete(&test1);
    llist_delete(&test3);
    llist_delete(&test6);

    llist_print();
    printf("\n");

    llist_add(&test3);
    llist_add(&test6);

    llist_print();
    printf("\n");
}
