#include <cs50.h>
#include <stdio.h>

void generateFullPyramid(int pyramidHeight);
void generateLeftPyramidLayer(int layerSize, int pyramidHeight);
void generateRightPyramidLayer(int layerSize);
int getPyramidHeight();

int main(){
   const int pyramidHeight = getPyramidHeight();

   generateFullPyramid(pyramidHeight);
}

void generateFullPyramid(int pyramidHeight){
   for(int currentLayer = 0; currentLayer < pyramidHeight; currentLayer++){
      generateLeftPyramidLayer(currentLayer + 1, pyramidHeight);

      printf("  ");

      generateRightPyramidLayer(currentLayer + 1);
   }
}

void generateLeftPyramidLayer(int layerSize, int pyramidHeight){
   const int numberOfSpaces = pyramidHeight - layerSize;

   for(int spaceNumber = 0; spaceNumber < numberOfSpaces; spaceNumber++){
      printf(" ");
   }

   for(int currentLayer = 0; currentLayer < layerSize; currentLayer++){
      printf("#");
   }
}

void generateRightPyramidLayer(int layerSize){
   for(int currentLayer = 0; currentLayer < layerSize; currentLayer++){
      printf("#");
   }

   printf("\n");
}

int getPyramidHeight(){
   int pyramidHeight;
   const int minHeight = 1;
   const int maxHeight = 8;

   do{
      pyramidHeight = get_int("What should the pyramid height be? ");
   }while(pyramidHeight < minHeight || pyramidHeight > maxHeight);

   return pyramidHeight;
}