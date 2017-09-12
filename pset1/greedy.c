#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Quarter variable
    int quarter = 25;

    // Dime
    int dime = 10;

    // Nickel
    int nickel = 5;

    // Keep count of coins initialized at 0
    int count = 0;

    // Penny
    int penny = 1;

    float change;

    do
    {
    // Get change variable from user
    printf("How much change? ");
    change = get_float();

    }
    while(change < 0);

    int balance = (change * 100);
    printf("%i\n", balance);
    // Divide change by Quarter using modulo
    // 32 > 25
    while(balance > 0)
    {
        if(balance - quarter >= 0)
        {
        // change = 7
        count++;
        balance = (balance - quarter);
        printf("%i\n", count);
        printf("%i\n", balance);
        }


        // if change logic
        else if(balance - dime >= 0)
        {
            // change = 7
            count++;
            balance = (balance - dime);
            printf("%i\n", count);
            printf("%i\n", balance);
        }


        // change = 5
        else if(balance - nickel >= 0)
        {
            count++;
            balance = (balance - nickel);
            printf("%i\n", count);
            printf("%i\n", balance);
        }

        // change = 2
        else if(balance - penny >= 0)
        {
            count++;
            balance = (balance - penny);
            printf("%i\n", count);
            printf("%i\n", balance);
        }
    }
    printf("%i\n", count);
}
