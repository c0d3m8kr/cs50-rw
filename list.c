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

    list = list2;

    free(list);
    return 0;
}