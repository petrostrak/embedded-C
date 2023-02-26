/*
Write a program to calculate income tax payable
of the user. Tax is calculated as per below
    Total income    % of tax
*   up to 9.525     0
*   9.526-38.700    12%
*   38.701-82.500   22%
*   > 82.500        32% + 1000

    Tax payable = income * (tax rate / 100)
*/

#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    uint64_t income;
    uint64_t tax;
    double temp_income;
    
    printf("Give your income: ");
    
    if (!scanf("%lf", &temp_income)) {
        printf("Invalid Input");
        return 0;
    }

    if (temp_income < 0)
    {
        printf("Invalid input\n");
        return 0;
    }
    

    income = (uint64_t) temp_income;

    if (income <= 9525) {
        tax = 0;
    } else if (income >= 9526 && income <= 38700)
    {
        tax = income * 0.12;
    } else if (income >= 38701 && income <= 82500)
    {
        tax = income * 0.22;
    } else if (income > 82500) {
        tax = income * 0.32;
        tax += 1000;
    }

    printf("Your payable tax is $%64llu\n", tax);

    return 0;
}
