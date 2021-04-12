#include <stdio.h>

void Sort(int *UnsortedArray, int ArraySize) {
    int count;
    int swap;
    int order;
    while (1)
    {
        count = 0;
        order = 0;
        while (count < ArraySize - 1)
        {
            if (*(UnsortedArray + count) < *(UnsortedArray + count + 1))
            {
                swap = *(UnsortedArray + count);
                *(UnsortedArray + count) = *(UnsortedArray + count + 1);
                *(UnsortedArray + count + 1) = swap;
                order = 1;
            }
            count += 1;
        }
        if (order == 0)
        {
            break;
        }
    }
}

int main()
{
    int size = 10;
    int count = 0;
    int Array[size];
    while (count <= size - 1)
    {
        puts("Enter an integer: ");
        scanf("%d", &Array[count]);
        count +=1;
    }
    Sort(Array, size);
    count = 0;
    printf("Your sorted array is: ");
    while (count <= size - 1)
    {
        printf("[%d] ", Array[count]);
        count += 1;
    }
    return 0;
}
