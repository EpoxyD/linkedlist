#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void print_keyvalue(void *keyvalue)
{
    llist_t *ll = (llist_t*) keyvalue;
    printf("{\"Value\":%p}\n", (void *) ll->value);
}

int main(void)
{
    llist_t *ll = ll_init();

    char * test = "Hello World";
    int * testt = malloc(sizeof(int));
    *testt = 5;

    ll_add(ll, test, strlen(test)+1);
    ll_add(ll, testt, sizeof(testt));
    ll_print(ll, print_keyvalue);
}
