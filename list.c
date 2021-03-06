#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    printf("The size of list is: %i\n", 3);

    for (int i = 0; i < 3; i++)
    {
        printf("list[%i]: %i\n", i, list[i]);
    }

    // Now I wish to expand the list...
    int *list2 = malloc(4 * sizeof(int));
    if (list2 == NULL)
    {
        free(list);
        return 1;
    }

    // otherwise, copy over the items from list original
    for (int i = 0; i < 3; i++)
    {
        list2[i] = list[i];
    }
    list2[3] = 4;

    for (int j = 0; j < 4; j++)
    {
        printf("list2[%i]: %i\n", j, list2[j]);
    }

    free(list);
    list = list2;

    int *tmp = realloc(list, 5 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    for (int k = 0; k < 5; k++)
    {
        tmp[k] = list[k];
    }
    tmp[4] = 99;

    free(list);
    list = tmp;

    for (int j = 0; j < 5; j++)
    {
        printf("list[%i]: %i\n", j, list[j]);
    }

    free(list);
    return 0;
}