#include <cs50.h>
#include <stdio.h>
#include <math.h>

long getCardNumber();
int getMultipliedNumbersDigitsSum(long cardNumber, int numberLength);
int getNonMultipliedDigitsSum(long cardNumber, int numberLength);
int getNumberLength(long number);
int getNumberNthDigit(long number, int digitIndex);
void sayCardCompany(long cardNumber);
bool validateCardNumber(long cardNumber);

int main(){
   const long cardNumber = getCardNumber();

   bool cardNumberIsValid = validateCardNumber(cardNumber);

   if(cardNumberIsValid){
      sayCardCompany(cardNumber);
   }else{
      printf("INVALID\n");
   }
}

long getCardNumber(){
   long cardNumber = get_long("What's the card number? ");

   return cardNumber;
}

int getMultipliedNumbersDigitsSum(long cardNumber, int numberLength){
   int multipliedNumbersDigitsSum = 0;

   for(int i = 2; i <= numberLength; i += 2){
      const int multipliedNumber = cardNumber / (long)pow(10, i - 1) % 10;
      const int multipliedResult = multipliedNumber * 2;

      const int firstResultDigit = multipliedResult % 10;
      const int secondResultDigit = multipliedResult / 10;
      const int resultDigitsSum = firstResultDigit + secondResultDigit;

      multipliedNumbersDigitsSum += resultDigitsSum;
   }

   return multipliedNumbersDigitsSum;
}

int getNonMultipliedDigitsSum(long cardNumber, int numberLength){
   int nonMultipliedDigitsSum = 0;

   for(int i = 1; i <= numberLength; i += 2){
      const int nonMultipliedNumber = cardNumber / (long)pow(10, i - 1) % 10;

      nonMultipliedDigitsSum += nonMultipliedNumber;
   }

   return nonMultipliedDigitsSum;
}

int getNumberNthDigit(long number, int digitIndex){
   const int numberLength = getNumberLength(number);

   const int numberFirstDigit = number / (long)pow(10, numberLength - digitIndex) % 10;

   return numberFirstDigit;
}

int getNumberLength(long number){
   int numberLength = 0;
   long divisionResult = number;

   while(divisionResult > 0){
      divisionResult /= 10;

      numberLength++;
   }

   return numberLength;
}

void sayCardCompany(long cardNumber){
   const int numberFirstDigit = getNumberNthDigit(cardNumber, 1);
   const int numberSecondDigit = getNumberNthDigit(cardNumber, 2);

   const bool itsAmex = numberFirstDigit == 3;
   const bool itsVisa = numberFirstDigit == 4;
   const bool itsMastercard = numberFirstDigit == 5;

   if(!itsAmex && !itsVisa && !itsMastercard){
      printf("INVALID\n");
   }else if(itsVisa){
      printf("VISA\n");
   }else if(itsAmex){
      if(
      numberSecondDigit == 4 ||
      numberSecondDigit == 7
      ){
         printf("AMEX\n");
      }else{
         printf("INVALID\n");
      }
   }else if(itsMastercard){
      if(
      numberSecondDigit == 1 ||
      numberSecondDigit == 2 ||
      numberSecondDigit == 3 ||
      numberSecondDigit == 4 ||
      numberSecondDigit == 5
      ){
         printf("MASTERCARD\n");
      }else{
         printf("INVALID\n");
      }
   }

}

bool validateCardNumber(long cardNumber){
   const int numberLength = getNumberLength(cardNumber);

   const bool lengthIsInvalid = numberLength < 13 || numberLength > 16;
   if(lengthIsInvalid){
      return false;
   }

   int multipliedNumbersDigitsSum = getMultipliedNumbersDigitsSum(cardNumber, numberLength);
   int nonMultipliedDigitsSum = getNonMultipliedDigitsSum(cardNumber, numberLength);

   const int totalSum = multipliedNumbersDigitsSum + nonMultipliedDigitsSum;
   const int totalSumLastDigit = totalSum % 10;

   if(totalSumLastDigit == 0){
      return true;
   }else{
      return false;
   }
}