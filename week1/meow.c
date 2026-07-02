#include <stdio.h>

void meow(int n){

    for (int i = 0; i < n; i++){
        printf("\nMEOW\n");
    }
}

int main(void)
{
    int n;
    do{
        printf("\nHow many times will the cat meow: ");
        scanf("%i", &n);
    }
    while (n <= 0);

    meow(n);

    printf("\n");
}