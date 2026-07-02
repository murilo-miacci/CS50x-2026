#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
        return 1;

    char name[100];
    printf("\nName: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    char number[100];
    printf("\nNumber: ");
    fgets(number, sizeof(number), stdin);
    number[strcspn(number, "\n")] = '\0';

    fprintf(file, "%s, %s\n\n", name, number);

    fclose(file);

    return 0;
}