#include <stdio.h>
#include <stdbool.h>

bool luhn(unsigned long long num){
    
    unsigned long long n = num;
    int len = 0;

    do
    {
        len++;
        n /= 10;
    }
    while (n != 0);

    unsigned long long b100 = 10;
    int sum = 0;
    int ch;
    int och;

    for (int i = 1; i <= len/2; i++)
    {
        ch = ((num / b100 - (num / (b100 * 10)) * 10) * 2);
        if (ch >= 10)
            sum += ch / 10 + (ch - 10);
        else
            sum += ch;

        och = (num / (b100 / 10) - (num / b100) * 10);
        sum += och;

        b100 *= 100;
    }

    unsigned long long b10 = 1;
    for (int i = 1; i < len; i++)
        b10 *= 10;
    
    if (len % 2 != 0)
        sum += num / b10;

    if (sum % 10 == 0)
        return true;
    else
        return false;
}

int main(void)
{
    char line[100];
    unsigned long long number;

    while (1)
    {
        printf("\nCard number: ");

        if (!fgets(line, sizeof(line), stdin))
        {
            printf("\n");
            return 1;
        }
        if (sscanf(line, "%llu", &number) == 1)
            break;
    }

    bool luhn_status = false;
    if (luhn(number) == true)
        luhn_status = true;

    unsigned long long n_test = number;

    int lenght = 0;
    do
    {
        lenght++;
        n_test /= 10;
    }
    while (n_test != 0);

    unsigned long long b10 = 1;
    for (int i = 1; i < lenght; i++)
        b10 *= 10;

    int first = number / b10;
    int second = (number / (b10 / 10)) - ((number / b10) * 10);

    if (first == 3 && (second == 4 || second == 7) && lenght == 15 && luhn_status == true)
        printf("\nAMEX\n\n");
    else if (first == 5 && (second == 1 || second == 2 || second == 3 || second == 4 || second == 5) && lenght == 16 && luhn_status == true)
        printf("\nMASTERCARD\n\n");
    else if (first == 4 && (lenght == 13 || lenght == 16) && luhn_status == true)
        printf("\nVISA\n\n");
    else
        printf("\nINVALID\n\n");
}
