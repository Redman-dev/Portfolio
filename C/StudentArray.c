#include <stdio.h>

struct Student
{
    char Name[50];
    int Id;
    int CGrade;
    int SAADGrade;
    int OOPGrade;
    int COMMGrade;
    int APPDGrade;
    int JSGrade;
};

int main()
{
    struct Student StudentArray[5] = {
        { "Ryan", 1, 50, 50, 50, 50, 50, 50 },
        { "George", 2, 99, 97, 90, 92, 98, 100 },
        { "Stephen", 3, 90, 95, 86, 84, 85, 89 },
        { "Parker", 4, 78, 76, 73, 100, 100, 100 },
        { "Ty", 5, 90, 90, 90, 90, 90, 75 },
    };
    int count = 0;
    float Average;
    while (count <= 4)
    {
        Average = 0;
        printf("Student %d:\n", count);
        printf("Name is: %s\n", StudentArray[count].Name);
        printf("ID is: %d\n", StudentArray[count].Id);
        printf("Grade in C is: %d%%\n", StudentArray[count].CGrade);
        Average += StudentArray[count].CGrade;
        printf("Grade in SAAD is: %d%%\n", StudentArray[count].SAADGrade);
        Average += StudentArray[count].SAADGrade;
        printf("Grade in OOP is: %d%%\n", StudentArray[count].OOPGrade);
        Average += StudentArray[count].OOPGrade;
        printf("Grade in COMM is: %d%%\n", StudentArray[count].COMMGrade);
        Average += StudentArray[count].COMMGrade;
        printf("Grade in APPD is: %d%%\n", StudentArray[count].APPDGrade);
        Average += StudentArray[count].APPDGrade;
        printf("Grade in JS is: %d%%\n", StudentArray[count].JSGrade);
        Average += StudentArray[count].JSGrade;
        Average = Average / 6.0f;
        printf("Average grade is: %.2f%%\n\n", Average);
        count += 1;
    }
    return 0;
}
