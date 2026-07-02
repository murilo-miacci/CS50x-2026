#include <stdio.h>

/*
int main(void)
{
    int h;
    printf("\nHeight: ");
    scanf("%i", &h);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
}
*/

void draw(int n){
    if (n <= 0)
        return;

    draw(n - 1);

    for (int i = 0; i < n; i++)
        printf("#");

    printf("\n");
}

int main(void)
{
    int h;
    printf("\nHeight: ");
    scanf("%i", &h);

    printf("\n");
    draw(h);
    printf("\n");
}