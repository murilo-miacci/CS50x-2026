/*
#include <stdio.h>

int main(void)
{
    char name[50];
    printf("What's your name? ");
    scanf("%49s", name);

    printf("Hello, %s!\n", name);
}
*/
// Funciona, porém, só pega a primeira palavra da string.

/*
#include <stdio.h>

int main(void)
{
    char name[100];
    printf("What's your name? ");
    fgets(name, sizeof(name), stdin);

    printf("Hello, %s", name);
}
*/
// Agora pega todas as strings, no entanto, o caractere \n
// atrapalha a exclamação.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100];
    printf("\nWhat's your name? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("\nWelcome, %s.\nThat's C!\n\n", name);
}
// Conclusão
