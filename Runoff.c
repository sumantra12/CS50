#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;



//declaration of methods
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);


int main
(int argc, string argv[])
{


    if
    (argc < 2)
    {

        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

// Populate array of candidates
    candidate_count = argc - 1;
    if
    (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for
    (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if
    (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for
    (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for
        (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while
    (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if
        (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if
        (tie)
        {
            for
            (int i = 0; i < candidate_count; i++)
            {
                if
                (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for
        (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;



}

// Record preference if vote is valid
bool vote
(int voter, int rank, string name)
{
    int v;
    //itterates over each candidate that has been chosen in the command line arguments
    for
    (v = 0; v < candidate_count; v = v + 1)
    {
        //strcmp used to compare name of the candidate vote, and candidates in the race
        //when they are == 0(equal) the preference will be recorded in the candidates name and where they've been ranked
        if
        (strcmp(name, candidates[v].name) == 0)
        {
            //counts the voter records their preference and return true
            preferences[voter][rank] = v;
            return true;
        }

    }
    //if name and candidates in the race aren't equal to 0, then it'll return false as invalid vote
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate
(void)
{
    //variable declaration
    int t, v, index;

    //nested loops for 2D array

    //itterates over the voter_count(counts the number of voters)
    for
    (t = 0; t < voter_count; t = t + 1)
    {
        //itterates over the number of candidate
        for
        (v = 0; v < candidate_count; v = v + 1)
        {
            //the index inside the loop itterates over the voters and candidates
            //the array represents the voters, candidate preference
            index = preferences[t][v];

            //if the candidate is not eliminated
            if
            (!candidates[index].eliminated)
            {
                //a vote will be added to the candidate via the preference
                candidates[index].votes += 1;
                break;
            }

        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner
(void)
{
    //variable declration
    int winning_votes;
    int w;

    //the winning amount of votes is only when the the voter have more than off the votes
    winning_votes = (voter_count / 2 + 0.5);

    //itterates over each candidate
    for
    (w = 0; w < candidate_count; w = w + 1)
    {
        //when the votes are greater than the winning votes the candidate will be the winner
        if
        (candidates[w].votes > winning_votes)
        {
            //prints the winner name and returns true
            printf("%s\n", candidates[w].name);
            return true;

        }


    }
    //else the loop will break and return false
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min
(void)
{
    //veriables declared
    int votes_minimum, min;

    //minimum votes start from the 0th candidate
    votes_minimum = candidates[0].votes;

    //itterates over each candidate
    for
    (min = 0; min < candidate_count; min = min + 1)
    {
        //when candidate is not eliminated and the minimum votes is greater than the candidates votes, the candidate min vote total will be counted
        if
        (!candidates[min].eliminated && votes_minimum > candidates[min].votes)
        {
            //stops counting the votes of candidates out of the race
            votes_minimum = candidates[min].votes;
        }

    }
    //returns the minimum vote total of the candidates
    return votes_minimum;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie
(int min)
{
    int t;

    //itterates over each candidate
    for
    (t = 0; t < candidate_count; t = t + 1)
    {
        //the candidate votes are greater than the minimum votes, than their is a tie
        if
        (candidates[t].votes > min)
        {

            return false;

        }

    }
    return true;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate
(int min)
{
    int e;

    //itterates of each candidate
    for
    (e = 0; e < candidate_count; e = e + 1)
    {
        //when the candidate vote is equal to the min, candidate will have least votes and will be elimintade
        if
        (candidates[e].votes == min)
        {
            //eliminates candidate
            candidates[e].eliminated = true;
        }
    }
    return;
}
