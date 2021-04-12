#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * newInt() {
    int *pMemory = 0;
    pMemory = (int *)malloc(sizeof(int));
    return pMemory;
}

double * newDouble() {
    double *pMemory = 0;
    pMemory = (double *)malloc(sizeof(double));
    return pMemory;
}

float * newFloat() {
    float *pMemory = 0;
    pMemory = (float *)malloc(sizeof(float));
    return pMemory;
}

char * newCharArray(int size) {
    char *pMemory = 0;
    pMemory = (char *)malloc(size * sizeof(char));
    return pMemory;
}

int main()
{
    int *pInt;
    pInt = newInt();
    *pInt = 45;
    double *pDouble;
    pDouble = newDouble();
    *pDouble = 3.5;
    float *pFloat;
    pFloat = newFloat();
    *pFloat = 3.14159f;
    char *pChar;
    pChar = newCharArray(10);
    strcpy(pChar, "test");
    printf("int: %d\ndouble:  %f\nfloat: %f\nchar: %s", *pInt, *pDouble, *pFloat, pChar);
    return 0;
}
