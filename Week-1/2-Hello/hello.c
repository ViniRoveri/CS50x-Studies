#include <stdio.h>
#include <cs50.h>

string getUsername();
void printUsername(string username);

int main(){
   string username = getUsername();

   printUsername(username);
}

string getUsername(){
   string username = get_string("What's your name? ");

   return username;
}

void printUsername(string username){
   printf(
      "hello, %s\n",
      username
   );
}