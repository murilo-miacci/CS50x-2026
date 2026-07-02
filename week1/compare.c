#include <stdio.h>

int main(void)
{
    int x;
    printf("\nType an integer number: ");
    scanf("%i", &x);

    int y;
    printf("Type another integer number: ");
    scanf("%i", &y);

    if (x > y){
        printf("\n%i is greater than %i\n\n", x, y);
    }
    else if (x < y){
        printf("\n%i is less than %i\n\n", x, y);
    }
    else{
        printf("\n%i is equal to %i\n\n", x, y);
    }
}
