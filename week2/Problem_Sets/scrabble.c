#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    const char letters[] = "abcdefghijklmnopqrstuvwxyz";
    const int values[] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
        5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
        1, 4, 4, 8, 4, 10
    };

    char p1[100];
    printf("\nPlayer 1: ");
    if (!fgets(p1, sizeof(p1), stdin))
    {
        printf("\n");
        return 1;
    }
    p1[strcspn(p1, "\n")] = '\0';

    for (int i = 0, n = strlen(p1); i < n; i++)
        p1[i] = tolower((unsigned char)p1[i]);

    char p2[100];
    printf("\nPlayer 2: ");
    if (!fgets(p2, sizeof(p2), stdin))
    {
        printf("\n");
        return 1;
    }
    p2[strcspn(p2, "\n")] = '\0';

    for (int i = 0, n = strlen(p2); i < n; i++)
        p2[i] = tolower((unsigned char)p2[i]);

    int points1 = 0;
    int points2 = 0;

    for (int i = 0; p1[i] != '\0'; i++)
    {
        for (int j = 0; letters[j] != '\0'; j++)
        {
            if (p1[i] == letters[j])
                points1 += values[j];
        }
    }

    for (int i = 0; p2[i] != '\0'; i++)
    {
        for (int j = 0; letters[j] != '\0'; j++)
        {
            if (p2[i] == letters[j])
                points2 += values[j];
        }
    }

    if (points1 > points2)
        printf("\nPLAYER 1 WINS!\n\n");
    else if (points1 < points2)
        printf("\nPLAYER 2 WINS!\n\n");
    else
        printf("\nTIE!\n\n");
    
    return 0;
}