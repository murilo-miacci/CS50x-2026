#include <stdio.h>

int main(void)
{
    char line[20];
    int money;

    while (1)
    {
        printf("\nChange owed: ");

        if (!fgets(line, sizeof(line), stdin))
        {
            printf("\n");
            return 1;
        }
        if (sscanf(line, "%d", &money) == 1 && money >= 0)
            break;
    }

    printf("\n");

    unsigned int count = 0;

    if (money >= 25)
    {
        count += money / 25;
        money %= 25;
    }
    if (money >= 10)
    {
        count += money / 10;
        money %= 10;
    }
    if (money >= 5)
    {
        count += money / 5;
        money %= 5;
    }
    if (money >= 1)
    {
        count += money;
        money = 0;
    }
    
        printf("Amount of coins: %u\n\n", count);
}