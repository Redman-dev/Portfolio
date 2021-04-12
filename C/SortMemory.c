#include <stdio.h>
#include <stdlib.h>

void Sort(int *pStart, int size) {
    int count;
    int swap;
    int order;
    int *pFirst = 0;
    int *pSecond = 0;
    while (1)
    {
        pFirst = pStart;
        pSecond = pStart;
        pSecond++;
        count = 0;
        order = 0;
        while (count < size - 1)
        {
            if (*pFirst < *pSecond)
            {
                swap = *pFirst;
                *pFirst = *pSecond;
                *pSecond = swap;
                order = 1;
            }
            count += 1;
            pFirst++;
            pSecond++;
        }
        if (order == 0)
        {
            break;
        }
    }
}

int main()
{
    int *pMemory = 0;
    pMemory = (int *)malloc(10 * sizeof(int));
    int *pDynamic = 0;
    pDynamic = pMemory;
    int loop = 0;
    int input = 0;
    printf("Enter 10 integers:\n");
    while (loop < 10)
    {
        scanf("%d", &(*pDynamic));
        pDynamic++;
        loop += 1;
    }
    Sort(pMemory, 10);
    loop = 0;
    pDynamic = pMemory;
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
