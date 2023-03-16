#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int getLettersNumber(string textFromUser);
int getSentencesNumber(string textFromUser);
int getWordsNumber(string textFromUser);
int getTextScore(string textFromUser);
void printGrade(int textScore);

int main(){
   string textFromUser = get_string("Text: ");

   const int textScore = getTextScore(textFromUser);

   printGrade(textScore);
}

int getLettersNumber(string textFromUser){
   int lettersNumber = 0;

   for(int i = 0; i < strlen(textFromUser); i++){
      const char currentCharacter = textFromUser[i];

      if(currentCharacter >= 'A' && currentCharacter <= 'z'){
         lettersNumber++;
      }
   }

   return lettersNumber;
}

int getSentencesNumber(string textFromUser){
   int sentencesNumber = 0;

   for(int i = 0; i < strlen(textFromUser); i++){
      const char currentCharacter = textFromUser[i];

      if(currentCharacter == '.' || currentCharacter == '!' || currentCharacter == '?'){
         sentencesNumber++;
      }
   }

   return sentencesNumber;
}

int getWordsNumber(string textFromUser){
   int wordsNumber = 1;

   for(int i = 0; i < strlen(textFromUser); i++){
      const char currentCharacter = textFromUser[i];

      if(currentCharacter == ' '){
         wordsNumber++;
      }
   }

   return wordsNumber;
}

int getTextScore(string textFromUser){
   const int lettersNumber = getLettersNumber(textFromUser);
   const int wordsNumber = getWordsNumber(textFromUser);
   const int sentencesNumber = getSentencesNumber(textFromUser);

   const float averageLettersPer100Words = (lettersNumber * 100.0) / wordsNumber;
   const float averageSentencesPer100Words = (sentencesNumber * 100.0) / wordsNumber;

   const float textScoreFloat = 0.0588 * averageLettersPer100Words - 0.296 * averageSentencesPer100Words - 15.8;
   const int textScoreInt = round(textScoreFloat);

   return textScoreInt;
}

void printGrade(int textScore){
   if(textScore < 1){
      printf("Before Grade 1\n");
   }else if(textScore > 16){
      printf("Grade 16+\n");
   }else{
      printf(
         "Grade %i\n",
         textScore
      );
   }
}