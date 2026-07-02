#include <stdio.h>
#include <stdbool.h>

float get_number(void){

    float n;

    while(1){

        if (scanf("%f", &n) == 1){
            return n;
        }

        printf("\n[ERROR] Type again: ");
        while (getchar() != '\n');
    }
}

int main(void){

    printf("\n<=> The Amazing Calculator 1.0 <=>\n");

    float n1; char op; float n2; float answer;
    bool state = true;
    
    printf("\nFirst number: ");
    n1 = get_number();

    int c;
    while (state){
        printf("\nOperator [ + - * / ] ");
        scanf(" %c", &op);

        switch(op){
            case '+':
            case '-':
            case '*':
            case '/':
                state = false;
                break;
            default:
                while((c = getchar()) != '\n' && c != EOF);
                printf("\n[ERROR] Invalid operator.\n");
                break;
        }
    }
    
    printf("\nSecond number: ");
    n2 = get_number();

    if (op == '/' && n2 == 0){
        printf("\n[ERROR] Division by zero.\n");
        return 1;
    }

    if (op == '+'){
        answer = n1 + n2;
    }
    else if (op == '-'){
        answer = n1 - n2;
    }
    else if (op == '*'){
        answer = n1 * n2;
    }
    else{
        answer = n1 / n2;
    }

    printf("\n%.2f %c %.2f = %.2f\n",n1, op, n2, answer);
}
