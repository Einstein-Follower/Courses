#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>
#include <math.h>

int find_digit(long);
bool cal_checksum(long);
int main(void)
{
    long number = get_long("Number: ");
    int digit = find_digit(number);                // getting the number of digits
    int starts_with = number / pow(10, digit - 2); //getting the two leftmost digits
    if (cal_checksum(number))
    {
        if (digit == 15 && (starts_with == 34 || starts_with == 37))
        {
            printf("AMEX\n");
        }
        else if (digit == 16 && (starts_with >= 51 && starts_with <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((digit == 13 || digit == 16) && (starts_with / 10) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool cal_checksum(long number)
{
    //returns true if checksum is correct
    //otherwise it will return false
    int check = 0;
    for (int i = 0, n = find_digit(number); i < n; i++)
    {
        int temp;
        if (i % 2 != 0)
        {
            temp = ((number % 10) * 2);
        }
        else
        {
            temp = (number % 10);
        }
        if (temp >= 10)
        {
            temp = (temp / 10) + (temp % 10);
            check += temp;
        }
        else if (temp < 10)
        {
            check += temp;
        }
        number = number / 10;
    }
    if (check % 10 == 0)
    {
        return true;
    }
    return false;
}

int find_digit(long number)
{
    //return the number of digits present in a long variable
    int digit = 0;
    while (number > 0)
    {
        digit += 1;
        number = number / 10;
    }
    return digit;
}