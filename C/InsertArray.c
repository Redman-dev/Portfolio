#include <stdio.h>

int main()
{
    int Array[10] = {34, 123, 324, 45, 78, 32, 12, 96, 39, 49};
    int UserValue;
    int UserPosition;
    puts("Enter an integer: ");
    scanf("%d", &UserValue);
    puts("What position do you want your integer to be put in? ");
    scanf("%d", &UserPosition);
    printf("Array is:\n");
    int count = 0;
    while (count <= 9)
    {
        printf("[%d] ", Array[count]);
        count += 1;
    }
    printf("\nUser is to enter %d at position %d\n", UserValue, UserPosition);
    count = 9;
    if (10 >= UserPosition && UserPosition >= 1)
    {
        while (count >= UserPosition)
        {
            Array[count] = Array[count - 1];
            count -= 1;
        }
        Array[UserPosition - 1] = UserValue;
    }
    else
    {
        puts("Position input was not within array");
    }
    printf("Array becomes:\n");
    count = 0;
    while (count <= 9)
    {
        printf("[%d] ", Array[count]);
        count += 1;
    }
    return 0;
}
