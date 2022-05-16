#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    //Shows the usage of the program // Program forces the user to put one argument that is key
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }


    // Checks the key given by the user
    if (argc == 2)
    {
        //Checks the length of the string
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }


        //Checks if all characters are alphabetic
        int i = 0;
        while (i < strlen(argv[1]))
        {
            if (isalpha(argv[1][i]) == 0)
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
            i++;
        }

        //Checks if there are repeating characters

        for (int j = 0; j < strlen(argv[1]); j++)
        {
            for (int k = j + 1; k < strlen(argv[1]); k++)
            {
                if (argv[1][j] == argv[1][k])
                {
                    printf("There are repeating characters\n");
                    return 1;
                }
            }
        }

    }
    //Everything above checks whether key is valid or not

    //Starting from here it deals with convertion
    //Prompt user to get the text
    string text = get_string("Text: ");

    //ciphertext to convert the text
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        //if the character of the text is upper; finds its ascii number to get index for argv
        if (isupper(text[i]))
        {
            char char_of_word = text[i];
            int index = char_of_word;
            index = index - 65;
            printf("%c", toupper(argv[1][index]));
        }
        //does it for lower characters
        if (islower(text[i]))
        {
            char char_of_word = text[i];
            int index = char_of_word;
            index = index - 97;
            printf("%c", tolower(argv[1][index]));
        }
        //
        if (isalpha(text[i]) == 0)
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");

}


