// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 32;

// Hash table
node *table[N];

FILE *dictionaryFile = NULL;
int dictionarySize = 0;

void addToTable(const char *word){
    int wordHash = hash(word);

    node *newNode = malloc(sizeof(node));

    for(int i = 0; i < strlen(word) + 1; i++){
        newNode->word[i] = tolower(word[i]);
    }
    newNode->next = table[wordHash];

    table[wordHash] = newNode;
}

void initializeTable(){
    for(int i = 0; i < N; i++){
        table[i] = malloc(sizeof(node));

        for(int j = 0; j < LENGTH + 1; j++){
            table[i]->word[j] = '\0';
        }
        table[i]->next = NULL;
    }
}

char *lowerString(const char* string){
    char *lowerString = malloc(strlen(string) + 1);

    for (int i = 0; i < strlen(string) + 1; i++){
        lowerString[i] = string[i];

        if (string[i] >= 'A' && string[i] <= 'Z'){
            lowerString[i] += 'a' - 'A';
        }
    }

    return lowerString;
}

void readText(){
    initializeTable();

    char word[LENGTH + 1];
    int currentChar = 0;

    char buffer;
    while(fread(&buffer, sizeof(char), 1, dictionaryFile)){
        if(buffer != '\n'){
            word[currentChar] = buffer;

            currentChar++;
        }else{
            word[currentChar] = '\0';

            addToTable(word);

            currentChar = 0;

            dictionarySize++;
        }
    }
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int wordHash = hash(word);

    node *currentNode = table[wordHash];

    while(currentNode){
        char *nodeWord = currentNode->word;

        char* lowerWord = lowerString(word);

        if(strcmp(nodeWord, lowerWord) == 0){
            free(lowerWord);

            return true;
        }

        currentNode = currentNode->next;

        free(lowerWord);
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int charsSum = 0;

    for(int i = 0; i < strlen(word); i++){
        if(i > 2){
            break;
        }

        charsSum += tolower(word[i]);
    }

    return charsSum % 32;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    dictionaryFile = fopen(dictionary, "r");

    if(dictionaryFile){
        readText();
    }

    return dictionaryFile;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(!dictionaryFile){
        return 0;
    }

    return dictionarySize;
}

// Unloads dictionary from memory, returning true if successful, else false
void freeTableNode(node *nodeToFree){
    if(nodeToFree->next){
        freeTableNode(nodeToFree->next);
    }

    free(nodeToFree);
}

void freeFullTable(){
    for(int i = 0; i < N; i++){
        freeTableNode(table[i]);
    }
}

bool unload(void)
{
    // TODO
    bool fileIsOpen = fclose(dictionaryFile);

    if(!fileIsOpen){
        freeFullTable();
    }

    return !fileIsOpen;
}
