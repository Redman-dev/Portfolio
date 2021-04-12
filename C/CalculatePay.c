#include <stdio.h>

int main() {
    puts("What is your hourly pay?");
    float HourlyPR;
    scanf("%f", &HourlyPR);
    puts("How many hours have you worked?");
    float HoursW;
    scanf("%f", &HoursW);
    float GrossPay = HourlyPR * HoursW;
    float WitholdongT = 0.0f;
    if (GrossPay > 0 && GrossPay <= 300.00f)
    {
        WitholdongT = 0.10 * GrossPay;
    }
    else if (GrossPay <= 400.00f)
    {
        WitholdongT = 0.12 * GrossPay;
    }
    else if (GrossPay <= 500.00f)
    {
        WitholdongT = 0.15 * GrossPay;
    }
    else if (GrossPay > 500.00f)
    {
        WitholdongT = 0.20 * GrossPay;
    }
    else
    {
        puts("Something went wrong");
    }
    float NetPay = GrossPay - WitholdongT;
    printf("Your gross pay is: %.2f\n", GrossPay);
    printf("Your witholding tax is: %.2f\n", WitholdongT);
    printf("Your net pay is: %.2f\n", NetPay);
    return 0;
}