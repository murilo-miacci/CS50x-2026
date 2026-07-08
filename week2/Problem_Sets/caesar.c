#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("\nUsage: ./caesar [key]\n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit((unsigned int)argv[1][i]))
        {
            printf("\nUsage: ./caesar [key]\n");
            return 1;
        }
    }

    char text[100];
    printf("\nplaintext:  ");
    if (!fgets(text, sizeof(text), stdin)){
        printf("\n");
        return 1;
    }
    text[strcspn(text, "\n")] = '\0';
    
    char c_text[sizeof(text)];
    strcpy(c_text, text);

    int key = atoi(argv[1]);

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isupper((unsigned char)text[i]))
        {
            c_text[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
        else if (islower((unsigned char)text[i]))
        {
            c_text[i] = (text[i] - 'a' + key) % 26 + 'a';
        }
        else
            c_text[i] = text[i];
    }

    printf("ciphertext: %s\n\n", c_text);

    return 0;
}