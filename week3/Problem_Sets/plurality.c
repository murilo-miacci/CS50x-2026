#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    char *name;
    int votes;
} candidate;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("\nUsage: ./plurality [Candidates]\nAt least 2 Candidates!\n\n");
        return 1;
    }

    int amount = argc - 1;
    candidate candidates[amount];

    for (int i = 0; i < amount; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;

        for (int j = 0, n = strlen(candidates[i].name); j < n; j++)
        {
            if (!isalpha((unsigned char)candidates[i].name[j]))
            {
                printf("\nUsage: ./plurality [Candidates]\nMust be only alphabetic!\n\n");
                return 1;
            }
        }
    }

    int n_voters;
    int result;
    do
    {
        printf("\nNumber of voters: ");
        result = scanf("%i", &n_voters);

        if (result != 1)
        {
            printf("\nInvalid input. Please enter an integer.\n\n");
            while (getchar() != '\n');
        }
        else if (n_voters <= 0)
        {
            printf("\nThe number os n_voters must be greater than zero.\n\n");
        }
    } while (result != 1 || n_voters <= 0);

    while (getchar() != '\n');

    printf("\n");

    char vote[100];

    for (int i = 0; i < n_voters; i++)
    {
        printf("Vote: ");
        if (!fgets(vote, sizeof(vote), stdin))
        {
            printf("\n");
            return 1;
        }
        vote[strcspn(vote, "\n")] = '\0';

        int found = 0;
        for (int j = 0; j < amount; j++)
        {
            if (strcmp(vote, candidates[j].name) == 0)
            {
                candidates[j].votes++;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("Invalid vote!\n");
            i--;
        }
    }

    for (int i = 0; i < amount; i++)
        printf("\n%s: %d votes", candidates[i].name, candidates[i].votes);
    
    printf("\n");

    int max_n = 0;
    int max_i = 0;
    for (int i = 0; i < amount; i++)
    {
        if (candidates[i].votes > max_n)
        {
            max_n = candidates[i].votes;
            max_i = i;
        }
    }

    int with_max = 0;
    for (int i = 0; i < amount; i++)
    {
        if (candidates[i].votes == max_n)
            with_max++;
    }
    if (with_max > 1)
        printf("\nDRAW!\n\n");
    else
        printf("\nThe winner is %s!\n\n", candidates[max_i].name);

    return 0;
}