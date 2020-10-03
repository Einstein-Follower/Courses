#include<stdio.h>
#include<math.h>
#include<cs50.h>
int main()
{
    int coins = 0;
    float change;
    do
    {
        change = get_float("Change owned:");
    }
    while (!(change > 0));
    //Taking care of inputs

    int cents = round(change * 100);
    while (cents > 0)
    {
        //finding minimum no of coins
        if (cents >= 25)
        {
            cents = cents - 25;
            coins++;
        }
        else if (cents >= 10)
        {
            cents = cents - 10;
            coins++;
        }
        else if (cents >= 5)
        {
            cents = cents - 5;
            coins++;
        }
        else if (cents >= 1)
        {
            cents = cents - 1;
            coins++;
        }
    }
    //minimum no of coins are stored in the coin variable
    //Printing the result
    printf("%d\n", coins);
    return 0;
}
