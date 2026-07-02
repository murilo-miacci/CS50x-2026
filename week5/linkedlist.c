#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
            return 1;
        
        printf("Number: ");
        scanf("%i", &n->number);
        
        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }
        else if (n->number < list->number)
        {
            n->next = list;
            list = n;
        }
        else
        {
            for (node *pointer = list; pointer != NULL; pointer = pointer->next)
            {
                if (pointer->next == NULL)
                {
                    pointer->next = n;
                    break;
                }

                if (n->number < pointer->next->number)
                {
                    n->next = pointer->next;
                    pointer->next = n;
                    break;
                }
            }
        }
    }
    /*
    node *pointer = list;
    while (pointer != NULL)
    {
        printf("%i\n", pointer->number);
        pointer = pointer->next;
    }
    */

    printf("\nSorted: ");
    for (node *pointer = list; pointer != NULL; pointer = pointer->next)
        printf("%i ", pointer->number);

    printf("\n");

    node *pointer = list;
    while (pointer != NULL)
    {
        node *next = pointer->next;
        free(pointer);
        pointer = next;
    }

    return 0;
}