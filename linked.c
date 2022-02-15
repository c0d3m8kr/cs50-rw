#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{

    // define node:
    node *list = NULL;
    node *n = malloc(sizeof(node));

    if (n == NULL)
    {
        return 1;
    }

    n->number = 1;
    n->next = NULL;

    // update list to point to new node
    list = n;

    // lets add another number to the list...
    n = malloc(sizeof(node));

    if (n == NULL)
    {
        free(list);
        return 1;
    }

    // else add it to the list
    n->number = 2;
    n->next = NULL;
    list->next = n;

    // Add another node
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }

    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    // print the linked list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("Node.number = %i\n", tmp->number);
    }

    // free memory
    free(list);

    return 0;
}