#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct test
{
    llist_t node;
    int value;
    char *key;
} test_t;

void print_keyvalue(void *keyvalue)
{
    test_t *value = (test_t *)keyvalue;
    printf("{\"Key\":\"%s\",\"Value\":%d}\n", value->key, value->value);
}

int main(void)
{
    test_t testlist[6];
    char key[10] = {'\0'};

    for (int i = 0; i < 6; ++i)
    {
        sprintf(key, "Test%d", i);
        testlist[i].key = malloc(strlen(key) + 1);
        strcpy(testlist[i].key, key);
        testlist[i].value = i;
        llist_add(&testlist[i]);
    }

    llist_print(&print_keyvalue);
    printf("\n");

    llist_delete(&testlist[0]);
    llist_delete(&testlist[2]);
    llist_delete(&testlist[5]);

    llist_print(&print_keyvalue);
    printf("\n");

    llist_add(&testlist[2]);
    llist_add(&testlist[5]);

    llist_print(&print_keyvalue);
    printf("\n");
}
