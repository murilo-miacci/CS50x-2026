/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[100];
    printf("\nBefore: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    printf("\nAfter:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n\n");
}
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char s[100];
    printf("\nBefore: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    printf("\nAfter:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n\n");
}
