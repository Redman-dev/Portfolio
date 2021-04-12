#include <stdio.h>

int LargestNum(int X1, int X2, int X3);

int main() {
    int Input1;
    int Input2;
    int Input3;
    puts("Enter an integer");
    scanf(" %d", &Input1);
    puts("Enter a second integer");
    scanf(" %d", &Input2);
    puts("Enter a third integer");
    scanf(" %d", &Input3);
    printf("Largest of %d, %d, and %d is %d", Input1, Input2, Input3, LargestNum(Input1, Input2, Input3));
    return 0;
}

int LargestNum(int X1, int X2, int X3){
    int result;
    if (X1 >= X2)
    {
        if (X1 >= X3)
        {
            result = X1;
        }
        else
        {
            result = X3;
        }
    }
    else
    {
        if (X2 >= X3)
        {
            result = X2;
        }
        else
        {
            result = X3;
        }
    }
    return result;
}