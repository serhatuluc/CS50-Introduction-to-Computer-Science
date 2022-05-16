#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Width: ");
    }
    while (n < 1 || n > 8);
    //Using do-while loop user is forced to give number between 1 and 8


    int m = n;
    //New variable is defined to be used in second for loop


    for (int i = 0; i < n; i++)
    {
        m = m - 1;
        // m is decremented so that printing space is done decrementally

        for (int j = 0; j < m; j++)
        {
            printf(" ");
        }

        // Third loop is used to print hash at the end of what is printed by second loop
        for (int k = 0; k < n - m; k++)
        {
            printf("#");
        }

        //This new line take the curser to next line
        printf("\n");
    }
}


