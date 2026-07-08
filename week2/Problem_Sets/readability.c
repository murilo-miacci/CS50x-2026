#include <stdio.h>
#include <ctype.h>
#include <string.h>

int index_calculator(float L, float S){
    float index = 0.0588f * L - 0.296f * S - 15.8f;
    return (int)(index + 0.5f);
}

int main(void)
{
    char text[2000];
    printf("\nText: ");
    if (!fgets(text, sizeof(text), stdin)){
        printf("\n");
        return 1;
    }
    text[strcspn(text, "\n")] = '\0';

    int letters = 0;
    int sentences = 0;
    int words = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha((unsigned char)text[i]))
            letters++;
        
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;

        if (text[i] == ' ')
            words++;
    }

    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    int index = index_calculator(L, S);

    if (index < 1)
        printf("\nBefore Grade 1\n\n");
    else if (index >= 16)
        printf("\nGrade 16+\n\n");
    else
        printf("\nGrade %i\n\n", index);
}