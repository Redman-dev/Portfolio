#include <stdio.h>

int addThem(int X1, int X2);

int subtractThem(int X1, int X2);

int multiplyThem(int X1, int X2);

int divideThem(int X1, int X2);

int main() {
    int ch;
    int Input1;
    int Input2;
    int count = 0;
    while (1)
    {
        puts("Enter an integer");
        if(scanf(" %d", &Input1) == 1)
        {
            break;
        }
        else
        {
            puts("Entered value was not an integer");
        }
        while ( ( ch=getchar() ) != '\n' && ch != EOF );
    }
    while (1)
    {
        puts("Enter another integer");
        if(scanf(" %d", &Input2) == 1)
        {
            break;
        }
        else
        {
            puts("Entered value was not an integer");
        }
        while ( ( ch=getchar() ) != '\n' && ch != EOF );
    }
    printf("The sum of the 2 integers is: %d\n", addThem(Input1, Input2));
    printf("The difference between the 2 integers is: %d\n", subtractThem(Input1, Input2));
    printf("The product of the 2 integers is: %d\n", multiplyThem(Input1, Input2));
    printf("The quotient of the 2 integers is: %d\n", divideThem(Input1, Input2));
    return 0;
}

int addThem(int X1, int X2){
    int result = X1 + X2;
    return result;
}

int subtractThem(int X1, int X2){
    int result = X1 - X2;
    return result;
}

int multiplyThem(int X1, int X2){
    int result = X1 * X2;
    return result;
}

int divideThem(int X1, int X2){
    int result = X1 / X2;
    return result;
}