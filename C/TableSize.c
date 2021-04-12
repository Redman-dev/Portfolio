#include <stdio.h>

int main() {
    puts("Choose 1 for pine, 2 for oak, 3 for mahogany");
    int WoodType = 0;
    float cost = 0.0f;
    char TableSize;
    scanf("%d", &WoodType);
    if (WoodType == 1)
    {
        cost = 100.0f;
    }
    else if (WoodType == 2)
    {
        cost = 225.0f;
    }
    else if (WoodType == 3)
    {
        cost = 310.0f;
    }
    else
    {
        cost = 0.0f;
    }
    if (cost != 0.0f)
    {
        puts("Do you want a (l)arge table or a (s)mall table");
        scanf(" %c", &TableSize);
        if (TableSize == 'l')
        {
            cost += 35.0f;
        }
        else if (TableSize == 's')
        {
            cost += 0.0f;
        }
        else
        {
            puts("Size not recognised, defaulting to small");
            cost += 0.0f;
        }
        
        
    }
    printf("The cost of your table is: %.2f", cost);
    
    return 0;
}