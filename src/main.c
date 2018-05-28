#include "linkedlist.h"

int main(void)
{
    int val1 = 1;
    int val2 = 2;
    int val3 = 3;
    int val4 = 4;
    int val5 = 5;

    llist_t *intlist = NULL;
    llist_addValue(&intlist, &val1);
    llist_addValue(&intlist, &val2);
    llist_addValue(&intlist, &val3);
    llist_addValue(&intlist, &val4);
    llist_addValue(&intlist, &val5);
    llist_print(intlist);
    llist_free(intlist);
}
