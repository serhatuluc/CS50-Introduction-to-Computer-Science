#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
}

int compute_score(string word)
{
    // Finds the length of the string
    int len = 0;
    while (word[len] != '\0')
    {
        len++;
    }

    //Finds the score
    int score = 0;
    for (int i = 0; i < len; i++)
    {
        //ASCII number is used to find index
        char char_of_word = toupper(word[i]);
        int index = char_of_word;
        index = index - 65;

        if (index < 0 || index > 25)
        {
            score = score + 0;
        }
        else
        {
            score = score + POINTS[index];
        }

    }

    return score;

}
