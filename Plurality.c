#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main
(int argc, string argv[])
{
    // Check for invalid usage
    if
    (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if
    (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for
    (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for
    (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if
        (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}




// Update vote totals given a new vote
bool vote
(string name)
{
    int v;

    //loop itterates over the candidate name and the names inputted in the command line
    for
    (v = 0; v < candidate_count; v = v + 1)
    {

        //compares if both names inputted in the command line and name inputted by the votes
        //if they are == 0(equal) then the candidates are true
        if
        (strcmp(candidates[v].name, name) == 0)
        {

            //when true, we add one vote to the candidates
            candidates[v].votes++;
            return true;
        }


    }//when == 0(notequal) we return false and don't add a vote
    return false;



}


// Print the winner (or winners) of the election
void print_winner
(void)
{

    //counts number of winning votes
    int winning_votes = 0;
    int w;

    //itterates over each candidates to check how many votes they have by comparing to candidates.votes variable
    for
    (w = 0; w <= candidate_count; w = w + 1)
    {

        //the winning_votes are less than the candidates votes, the candidate has lost
        if
        (winning_votes <= candidates[w].votes)
        {

            winning_votes = candidates[w].votes;
        }
        //else if the winning number of votes are equal to the candidates.votes, then the candidate(s) have won the election
        if
        (winning_votes == candidates[w].votes)
        {

            //prints out winner(s) of the election
            printf("%s\n", candidates[w].name);

        }

    }

    return;

}
