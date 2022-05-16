#include <math.h>
#include <cs50.h>
#include <stdio.h>
//Checksum using luhn algorithm
int checksum(int count, long n)
{
    int sum = 0;
    for (int i = 0; i < count ; i++)
    {
        //to find each element of credit number
        int remainder = n % 10;
        n = n / 10;


        //starting from last second digit
        if (i % 2 != 0)
        {
            //higher than 10 then it is divided two element
            if (remainder * 2 >= 10)
            {
                remainder = remainder * 2;
                //two element is found using % and /
                sum = sum + remainder % 10 + remainder / 10;
            }
            //otherwise it multiplied element is added to sum
            else
            {
                sum = sum + remainder * 2;
            }
        }
        //others are added
        else
        {
            sum = sum + remainder;
        }

    }
    return sum;

}


int main(void)
{
    long n;

    //Prompt to user to get credit number
    do
    {
        n = get_long("Credit Card Number: ");
    }
    while (n < 0);

    //Finding the length of credit number to eliminate input which is smaller than 13
    long copy_n = n;
    int count = 0;
    do
    {
        copy_n /= 10;
        count = count + 1;
    }
    while (copy_n != 0);



    int sum = checksum(count, n);



    //Visa
    int startswith_Visa16 = n / pow(10, 15);
    if (sum % 10 == 0 && count == 16 && startswith_Visa16 == 4)
    {
        printf("VISA\n");
        return 0;
    }

    int startswith_Visa15 = n / pow(10, 14);
    if (sum % 10 == 0 && count == 15 && startswith_Visa15 == 4)
    {
        printf("VISA\n");
        return 0;
    }

    int startswith_Visa14 = n / pow(10, 13);
    if (sum % 10 == 0 && count == 14 && startswith_Visa14 == 4)
    {
        printf("VISA\n");
        return 0;
    }

    int startswith_Visa13 = n / pow(10, 12);
    if (sum % 10 == 0 && count == 13 && startswith_Visa13 == 4)
    {
        printf("VISA\n");
        return 0;
    }

    //American Express
    int startswith_American_Express_34 = n / pow(10, 13);
    if (sum % 10 == 0 && count == 15 && startswith_American_Express_34 == 34)
    {
        printf("AMEX\n");
        return 0;
    }

    int startswith_American_Express_37 = n / pow(10, 13);
    if (sum % 10 == 0 && count == 15 && startswith_American_Express_37 == 37)
    {
        printf("AMEX\n");
        return 0;
    }

    //Mastercard
    int startswith_Mastercard_51 = n / pow(10, 14);
    if (sum % 10 == 0 && count == 16 && startswith_Mastercard_51 == 51)
    {
        printf("MASTERCARD\n");
        return 0;
    }

    int startswith_Mastercard_52 = n / pow(10, 14);
    if (sum % 10 == 0 && count == 16 && startswith_Mastercard_52 == 52)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    int startswith_Mastercard_53 = n / pow(10, 14);
    if (sum % 10 == 0 && count == 16 && startswith_Mastercard_53 == 53)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    int startswith_Mastercard_54 = n / pow(10, 14);
    if (sum % 10 == 0 && count == 16 && startswith_Mastercard_54 == 54)
    {
        printf("MASTERCARD\n");
        return 0;
    }

    int startswith_Mastercard_55 = n / pow(10, 14);
    if (sum % 10 == 0 && count == 16 && startswith_Mastercard_55 == 55)
    {
        printf("MASTERCARD\n");
        return 0;
    }

    else
    {
        printf("INVALID\n");
    }

}





