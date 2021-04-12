#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *pFile;
    char input[100];
    char output[100];
    pFile = fopen("text.txt", "w+");
    while (1)
    {    
        printf("Please enter a string or a -1 to retrieve all entered strings:\n");
        fgets( input, 100, stdin );
        if (strstr(input, "-1") != NULL)
        {
            break;
        }
        else
        {
            fprintf(pFile, "%s", input);
        }
    }
    rewind(pFile);
    printf("File reads:\n");
    while (fgets(output, 100, pFile) != NULL)
    {
        printf("%s", output);
    }

    fclose(pFile);
    return 0;
}
