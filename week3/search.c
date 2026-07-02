#include <stdio.h>

int main(void){
    
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    int n;
    printf("\nNumber: ");
    scanf("%i", &n);

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n\n");
            return 0;
        }
    }
    printf("Not Found\n\n");
        return 1;
}