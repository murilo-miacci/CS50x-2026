#include <stdio.h>

int main(void)
{
    char line[20];
    int h;

    while (1)
    {
        printf("\nHeight: ");

        if (!fgets(line, sizeof(line), stdin))
        {
            printf("\n");
            return 1;
        }
        if (sscanf(line, "%d", &h) == 1 && h >= 1 && h <= 8)
            break;
    }

    printf("\n");

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= (h - i); j++)
            printf(" ");

        for (int k = 1; k <= i; k++)
            printf("#");

        printf("  ");

        for (int l = 1; l <= i; l++)
            printf("#");

        for (int m = 1; m <= (h - i); m++)
            printf(" ");

        printf("\n");
    }
    printf("\n");

    return 0;
}