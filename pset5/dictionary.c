/**
 * Implements a dictionary's functionality.
 */

#include "dictionary.h"

// Create node struct
typedef struct node
{
    char word[LENGTH+1];
    struct node *next;
}
node;

// Create pointers to as many buckets as HASHTABLE_SIZE
node *hashtable[HASHTABLE_SIZE];

// Hash function from Reddit
int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % HASHTABLE_SIZE;
}

// Establish word count
unsigned int count = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // *word is a const char and thus cannot be passed into hash_it
    // Store copy of *word in a char array
    int word_len = strlen(word);
    char word_copy[word_len + 1];

    for (int i = 0; i < word_len; i++)
    {
        word_copy[i] = word_copy[i];
    }

    word_copy[word_len] = '\0';

    // Find hash bucket of word
    int h = hash_it(word_copy);

    node *cursor = hashtable[h];

    while (cursor != NULL)
    {

        // if strcasecmp returns 0, word is spelled correctly
        if (strcasecmp(cursor->word, word_copy) == 0)
        {
            // word in dictionary
            return true;
        }
        else
        {
            // move cursor to next word
            cursor = cursor->next;
        }
    }
    return false;

    // Check last word in list
    if (cursor == NULL)
    {
        if (strcasecmp(cursor->word, word_copy) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{

    // Set hashtable buckets to NULL
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary and read it
    FILE *dp = fopen(dictionary, "r");
    if (dp == NULL)
    {
        fprintf(stderr, "No dictionary found\n");
        return false;
    }

    while (true)
    {
        // Allocate memory for each word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Could not malloc node.\n");
            return false;
        }

        // Put each string from file into new node
        fscanf(dp, "%s", new_node->word);
        new_node->next = NULL;

        if (feof(dp))
        {
            // hit end of file
            free(new_node);
            break;
        }

        // Increment count for each word
        count++;

        // Hash each word's node
        int h = hash_it(new_node->word);
        node *head = hashtable[h];

        // if bucket is empty
        if (head == NULL)
        {
            // new_node becomes head of list
            hashtable[h] = new_node;
        }
        else
        {
            // if there is already a head
            // point new_node to head
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
        }
    }

    fclose(dp);
    return true;

}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return count;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // Traverse linked list and free each node

    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        // Set a pointer at the i'th element of hashtable
        node *cursor = hashtable[i];
        while (cursor != NULL)
        {
            // Use *temp to move cursor along list
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}