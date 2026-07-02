#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char string[100];
    printf("\nWord: ");
    if (fgets(string, sizeof(string), stdin) == NULL)
        return 1;
    
    string[strcspn(string, "\n")] = '\0';

    char *copy = malloc(strlen(string) + 1);
    if (copy == NULL)
        return 1;

    strcpy(copy, string);

    if (strlen(string) > 0)
        copy[0] = toupper(copy[0]);

    printf("\nWord capitalized: %s\n", copy);

    free(copy);
}