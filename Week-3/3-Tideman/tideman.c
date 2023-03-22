#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs();
void sort_pairs();
void lock_pairs();
void print_winner();
int getPairStrength(int pairIndex);
void swapItems(pair array[], int firstIndex, int secondIndex);
bool checkIsCycle(int pairWinner, int pairLoser);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for(int i = 0; i < candidate_count; i++){
        const string candidateName = candidates[i];

        if(strcmp(candidateName, name) == 0){
            ranks[rank] = i;

            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for(int i = 0; i < candidate_count; i++){
        const int currentCandidate = ranks[i];

        for(int j = i + 1; j < candidate_count; j++){
            const int nextCandidate = ranks[j];

            preferences[currentCandidate][nextCandidate] += 1;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs()
{
    // TODO
    for(int i = 0; i < candidate_count; i++){
        for(int j = 0; j < candidate_count; j++){
            const int votesForCurrentCandidate = preferences[i][j];
            const int votesAgainstCurrentCandidate = preferences[j][i];

            const bool currentCandidateWins = votesForCurrentCandidate > votesAgainstCurrentCandidate;

            if(currentCandidateWins){
                pair newPair;

                newPair.winner = i;
                newPair.loser = j;

                pairs[pair_count] = newPair;

                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
int getPairStrength(int pairIndex){
    const int pairWinner = pairs[pairIndex].winner;
    const int pairLoser = pairs[pairIndex].loser;

    const int votesForWinner = preferences[pairWinner][pairLoser];
    const int votesAgainstWinner = preferences[pairLoser][pairWinner];

    const int pairStrength = votesForWinner - votesAgainstWinner;

    return pairStrength;
}

void swapItems(pair array[], int firstIndex, int secondIndex){
    const pair firstItem = array[firstIndex];
    const pair secondItem = array[secondIndex];

    array[firstIndex] = secondItem;
    array[secondIndex] = firstItem;
}

void sort_pairs()
{
    // TODO
    int swapCount;

    do{
        swapCount = 0;

        for(int i = 0; i < pair_count - 1; i++){
            const int currentPairStrength = getPairStrength(i);
            const int nextPairStrength = getPairStrength(i + 1);

            const bool itemsShouldSwap = currentPairStrength < nextPairStrength;

            if(itemsShouldSwap){
                swapItems(pairs, i, i + 1);
                swapCount++;
            }
        }
    }while(swapCount > 0);
}

// Lock pairs into the candidate graph in order, without creating cycles
bool checkIsCycle(int pairWinner, int pairLoser){
    // If the loser won someone that won someone that is the winner
    if(locked[pairLoser][pairWinner]){
        return true;
    }

    for(int i = 0; i < candidate_count; i++){
        if(locked[pairLoser][i]){
            const bool isCycle = checkIsCycle(pairWinner, i);

            if(isCycle){
                return true;
            }
        }
    }

    return false;
}

void lock_pairs()
{
    // TODO
    for(int i = 0; i < pair_count; i++){
        const pair currentPair = pairs[i];

        const int pairWinner = currentPair.winner;
        const int pairLoser = currentPair.loser;

        const bool isCycle = checkIsCycle(pairWinner, pairLoser);

        if(!isCycle){
            locked[currentPair.winner][currentPair.loser] = true;
        }
    }
}

// Print the winner of the election
void print_winner()
{
    // TODO
    int winnerIndex = 0;

    for(int i = 0; i < candidate_count; i++){
        bool candidateReceiveNoArrows = true;

        for(int j = 0; j < candidate_count; j++){
            if(locked[j][i]){
                candidateReceiveNoArrows = false;
            }
        }

        if(candidateReceiveNoArrows){
            winnerIndex = i;

            break;
        }
    }

    string winnerName = candidates[winnerIndex];

    printf(
        "%s\n",
        winnerName
    );
}
