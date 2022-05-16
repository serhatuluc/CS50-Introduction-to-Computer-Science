// Implements a dictionary's functionality

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];

//Counter for size function
int count;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char copy[LENGTH];
    for (int i = 0; i < strlen(word) + 1 ; i++)
    {
        copy[i] = tolower(word[i]);
    }

    // Hash word to obtain a hash value
    int value = hash(copy);

    //Access linked list at that index
    node *curser = table[value];

    //Traverse linked list, looking for the word
    while (curser != NULL)
    {
        if (strcasecmp(curser->word, copy) == 0)
        {
            return true;
        }
        curser = curser->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //https://www.reddit.com/r/cs50/comments/eo4zro/good_hash_function_for_speller/
    unsigned long hash = 5381;

    int c = *word;

    while (c == *word++)
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Opening the dictionary file
    FILE *dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL)
    {
        return false;
    }

    //Read string from the file
    count = 0;
    int index;
    char w[LENGTH];

    while (fscanf(dictionary_file, "%s", w) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        //Create new node
        strcpy(n->word, w);
        n->next = NULL;

        //Hash word
        index = hash(w);

        //Insert node into Hash Table
        n->next = table[index];
        table[index] = n;

        count += 1;
    }
    fclose(dictionary_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Freeing linked list
    for (int j = 0; j < N; j++)
    {
        node *curser = table[j];
        node *tmp = curser;
        while (curser != NULL)
        {
            curser = curser->next;
            free(tmp);
            tmp = curser;
        }
    }
    return true;
}
