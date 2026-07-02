#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int x = 12;
    int y = 21;

    printf("\nx is %i and y is %i", x, y);
    swap(&x, &y);
    printf("\nx is %i and y is %i\n\n", x, y);

    return 0;
}