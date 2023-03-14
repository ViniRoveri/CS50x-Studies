#include <cs50.h>
#include <stdio.h>

int getGoalSize(int startSize);
int getStartSize();
int getYearsToGoal(int startSize, int goalSize);

int main()
{
    // TODO: Prompt for start size
    const int startSize = getStartSize();

    // TODO: Prompt for end size
    const int goalSize = getGoalSize(startSize);

    // TODO: Calculate number of years until we reach threshold
    int const yearsToGoal = getYearsToGoal(startSize, goalSize);

    // TODO: Print number of years
    printf(
        "Years: %i\n",
        yearsToGoal
    );
}

int getGoalSize(int startSize){
    int goalSize;

    do{
        goalSize = get_int("End size: ");
    }while(goalSize < startSize);

    return goalSize;
}

int getStartSize(){
    int startSize;

    do{
        startSize = get_int("Start size: ");
    }while(startSize < 9);

    return startSize;
}

int getYearsToGoal(int startSize, int goalSize){
    int yearsToGoal = 0;
    int startLlamasOfYear = startSize;

    while(startLlamasOfYear < goalSize){
        const int addedLlamas = startLlamasOfYear / 3;
        const int subtractedLlamas = startLlamasOfYear / 4;

        const int endLlamasOfYear = startLlamasOfYear + addedLlamas - subtractedLlamas;

        startLlamasOfYear = endLlamasOfYear;

        yearsToGoal++;
    }

    return yearsToGoal;
}
