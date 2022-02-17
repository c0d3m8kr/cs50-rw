#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main()
{
    node *list = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    // let's print the pointers
    int i = 0;
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("Node[%i] = %i\n", i, tmp->number);
        i++;
    }

    // recursively destroy the nodes
    while (list != NULL)
    {
        node *tmp = list->next; // tmp points to list->next
        free(list);             // free the current list
        list = tmp;             // list = current tmp
    }

    // free(list->next);
    // free(list);

    return 0;
}