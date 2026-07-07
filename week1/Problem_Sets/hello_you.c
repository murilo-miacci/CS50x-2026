#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[50];
    printf("\nWhat's your name? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Hello, %s!\n\n", name);
}