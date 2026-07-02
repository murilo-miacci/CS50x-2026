#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c;

    while (1)
    {
        printf("Do you agree? [y|n] ");
        scanf(" %c", &c);

        c = tolower((unsigned char)c);
        // ctype.h -> tolower()

        if (c == 'y')
        {
            printf("Agreed.\n");
            break;
        }
        else if (c == 'n')
        {
            printf("Not agreed.\n");
            break;
        }
    }
}

