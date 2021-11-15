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
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool checkCycle(int end, int start_point);
void print_winner(void);

int main(int num, string running[]) {
    // Check for invalid usage
    if (num < 3)
    {
        printf("Usage: tideman requires candidates...\n");
        return 1;
    }

    for (candidate_count = 0; candidate_count < num - 1; candidate_count++) {
        candidates[candidate_count] = running[candidate_count + 1];
    }
    
    int voters;
    for (voters = get_int("How many voters?: "); voters > 0; voters--) {
        int ranks[candidate_count];
        for (int rank = 0; rank < candidate_count;) {
            if ((vote(rank, get_string("%i. ", rank+1), ranks)) == true) rank++;
        }
        record_preferences(ranks);
        printf("\n");
    }
    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
}


// Update ranks given a new vote
bool vote(int rank, string name, int ranks[]) {
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(name, candidates[i]) == 0) {
            ranks[rank] = i;
            return 1;
        }
    }
    printf("INVALID VOTE! SORRY!\n");
    return 0;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[]) {
    for (int i = 0; i < candidate_count; i++) {
        for (int h = i; h < candidate_count; h++) {
            if (h > i) preferences[ranks[i]][ranks[h]] += 1;
    }
  }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void) {
    pair_count = 0;
    for (int i = 0; i < candidate_count; i++) {
        for (int j = i+1; j < candidate_count; j++) {
            int winner = 0;
            int loser = 0;
            if (preferences[i][j] > preferences[j][i]) {
                winner = i;
                loser = j;
                pairs[pair_count].winner = winner;
                pairs[pair_count].loser = loser;
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j]) {
                winner = j;
                loser = i;
                pairs[pair_count].winner = winner;
                pairs[pair_count].loser = loser;
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int swaps = -1;
    while (swaps != 0) {
        swaps = 0;
        for (int i = 0; i < pair_count-1; i++) {
            if (((preferences[pairs[i].winner][pairs[i].loser]+1)/(preferences[pairs[i].loser][pairs[i].winner]+1)) < ((preferences[pairs[i+1].winner][pairs[i+1].loser]+1)/(preferences[pairs[i+1].loser][pairs[i+1].winner]+1))) {
                int tempWinner = pairs[i].winner;
                int tempLoser = pairs[i].loser;
                pairs[i].winner = pairs[i+1].winner;
                pairs[i].loser = pairs[i+1].loser;
                pairs[i+1].winner = tempWinner;
                pairs[i+1].loser = tempLoser;
                swaps++;
            }
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++) {
        if (!checkCycle(pairs[i].loser, pairs[i].winner)) {
            locked[pairs[i].winner][pairs[i].loser] = 1;
        }
    }
    return;
}

bool checkCycle(int end, int start_point) {
    if (end == start_point) return 1;
    for (int i = 0; i < candidate_count; i++) {
        if (locked[end][i]) {
            if (checkCycle(i, start_point)) return true;
        }
    }
    return 0;
}

// Print the winner of the election
void print_winner(void)
{
    int overallWinner = 1;
        for (int i = 0; i < candidate_count; i++) {
            int tempSum = 0;
            for (int j = 0; j < candidate_count; j++) {
                if (locked[j][i]) tempSum += 1; 
            }
            if (tempSum == 0) overallWinner = i;
        }
    printf("Winner: %s\n", candidates[overallWinner]);   
}