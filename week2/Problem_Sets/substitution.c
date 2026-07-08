#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("\nUsage: ./substitution [key]\n\n");
        return 1;
    }

    const char *key = argv[1];

    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isalpha((unsigned char)key[i]))
        {
            printf("\nUsage: ./substitution [key]\n\n");
            return 1;
        }
    }

    if (strlen(key) != 26)
    {
        printf("\nUsage: ./substitution [key]\nMust be 26 alphabetic characters.\n\n");
        return 1;
    }

    int seen[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        int index = tolower((unsigned char)key[i]) - 'a';
        if (seen[index])
        {
            printf("\nUsage: ./substitution [key]\nKey must not repeat letters.\n\n");
            return 1;
        }
        seen[index] = 1;
    }

    char text[100];
    printf("plaintext: ");
    if (!fgets(text, sizeof(text), stdin))
    {
        printf("\n");
        return 1;
    }
    text[strcspn(text, "\n")] = '\0';

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isupper((unsigned char)text[i]))
            text[i] = toupper((unsigned char)key[text[i] - 'A']);

        else if (islower((unsigned char)text[i]))
            text[i] = tolower((unsigned char)key[text[i] - 'a']);
    }

    printf("ciphertext: %s\n\n", text);

    return 0;
}