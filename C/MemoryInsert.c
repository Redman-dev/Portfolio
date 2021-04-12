#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pMemory = 0;
    pMemory = (int *)malloc(10 * sizeof(int));
    int *pDynamic = 0;
    pDynamic = pMemory;
    int loop = 1;
    int sum = 0;
    while (loop <= 10)
    {
        sum += loop;
        *pDynamic = sum; 
        pDynamic++;
        loop += 1;
    }
    int UserValue = 0;
    int UserPosition = 0;
    printf("What value do you want to insert? ");
    scanf("%d", &UserValue);
    printf("What position do you want your value inserted into? ");
    scanf("%d", &UserPosition);
    loop = 0;
    pDynamic = pMemory;
    printf("Stored values are ");
    while (loop < 10)
    {
        printf("%d ", *pDynamic);
        pDynamic++;
        loop += 1;
    }
    printf("\nUser is to enter %d at position %d\n", UserValue, UserPosition);
    UserPosition--;
    while (pMemory + UserPosition < pDynamic)
    {
        *pDynamic = *(pDynamic - 1);
        pDynamic--;
    }
    *(pMemory + UserPosition) = UserValue;
    loop = 0;
    pDynamic = pMemory;
    printf("Stored values become ");
    while (loop < 10)
    {
        printf("%d ", *pDynamic);
        pDynamic++;
        loop += 1;
    }
    free(pMemory);
    free(pDynamic);
    return 0;
}
