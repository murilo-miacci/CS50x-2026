#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char name[100];
    char number[100];
} person;

int main(void)
{
    const person people[] = {
        {"murilo pereira miacci", "(12) 991914-1686"},
        {"murilo pereira", "(12) 991914-1686"},
        {"murilo miacci", "(12) 991914-1686"},
        {"murilo", "(12) 991914-1686"},
        {"alícia marques dos santos", "(11) 95134-9787"}
    };

    size_t count = sizeof(people) / sizeof(people[0]);

    char name[100];
    printf("\nName: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = tolower(name[i]);
    }

    for (size_t i = 0; i < count; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }

    printf("Not Found\n");
    return 1;
}
