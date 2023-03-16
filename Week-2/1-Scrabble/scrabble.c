#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int POINTS_LENGTH = 26;

int compute_score(string word);
string convertToUpper(string word);
void printWinner(int score1, int score2);

int main(){
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    string formattedWord1 = convertToUpper(word1);
    string formattedWord2 = convertToUpper(word2);

    // Score both words
    int score1 = compute_score(formattedWord1);
    int score2 = compute_score(formattedWord2);

    // TODO: Print the winner
    printWinner(score1, score2);
}

int compute_score(string word){
    // TODO: Compute and return score for string
    int totalScore = 0;

    for(int i = 0; i < strlen(word); i++){
        const int letterIndex = (int)word[i] - 65;

        const int letterScore = POINTS[letterIndex];

        if(letterIndex >= 0 && letterIndex <= POINTS_LENGTH){
            totalScore += letterScore;
        }
    }

    return totalScore;
}

string convertToUpper(string word){
    for(int i = 0; i < strlen(word); i++){
        char currentCharacter = word[i];

        if(islower(currentCharacter)){
            word[i] = toupper(currentCharacter);
        }
    }

    return word;
}

void printWinner(int score1, int score2){
    if(score1 > score2){
        printf("Player 1 wins!\n");
    }else if(score1 < score2){
        printf("Player 2 wins!\n");
    }else{
        printf("Tie!\n");
    }
}
