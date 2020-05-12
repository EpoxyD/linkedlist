#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void print_callback(const node_t *node)
{
    printf("[%-20p] [%-20p] [%-20p] [%-20p] \n", node, node->prev, node->value, node->next);
}

int main(void)
{
    char *test = "Hello World";
    int number = 12345;
    int array[] = {1, 2, 3, 4, 5};

    node_t *list = NULL;
    node_add(&list, test, strlen(test) + 1);
    node_add(&list, &number, sizeof(number));
    node_add(&list, array, sizeof(array));
    node_del(list, &number);
    node_clean(list);
}
