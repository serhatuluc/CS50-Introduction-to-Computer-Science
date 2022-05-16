#include <cs50.h>
#include <stdio.h>


int main(void)
{
    //Prompt user for name. CS50 library is preferred to use
    string name = get_string("What's your name? ");
    printf("Hello, %s\n", name);
}