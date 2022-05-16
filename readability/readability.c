#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //float type is preferred to use
    string text = get_string("Text: ");
    float number_of_letters = count_letters(text);
    float number_of_words = count_words(text);
    float number_of_sentences = count_sentences(text);

    float L = number_of_letters / number_of_words * 100;
    float S = number_of_sentences / number_of_words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded_index = round(index);

    if (rounded_index > 1 && rounded_index <= 16)
    {
        printf("Grade %i\n", rounded_index);
    }

    if (rounded_index > 16)
    {
        printf("Grade 16+\n");
    }

    if (rounded_index < 1)
    {
        printf("Before Grade 1\n");
    }



}

int count_letters(string text)
{
    int count = 0;
    int len_str = strlen(text);
    for (int i = 0; i < len_str; i++)
    {
        if (text[i] != ' ' && isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    int len_str = strlen(text);
    for (int i = 0; i < len_str; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

int count_sentences(string text)
{
    int count = 0;
    int len_str = strlen(text);
    for (int i = 0; i < len_str; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}


