#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Este software realiza una votacion presidencial y ademas por preferencias o ranking de los votantes, son tenidos en cuenta.

// Max voters and candidates
#define MAX_VOTERS 100 //maximo votadores
#define MAX_CANDIDATES 9    //maximo candidatos

// preferences[i][j] is jth preference for voter i //bidemensional
int preferences[MAX_VOTERS][MAX_CANDIDATES];//es el ranking de votantes

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;//clase

// Array of candidates //matriz
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates //variables globales
int voter_count; // cantidad de votos
int candidate_count; // cantidad de postulantes

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;//cantidad de postulantes
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)//asignara dependiendo la cantidad de POSTULADOS sus respectivos datos, al array.
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");// pedir la cantidad de votos
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {               //cantidad Votos

        // Query for each rank //creo nombres y rankin y votos
        for (int j = 0; j < candidate_count; j++)
        {                   //Cpostulados
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
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
        for(int i=0; i <candidate_count;i++){
                    if(strcmp(candidates[i].name,name)==0){
                        preferences[voter][rank]=i;
                        return true;
                    }
        }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
        for(int i=0;i<voter_count;i++){
            
                    for(int j=0;j< candidate_count;j++){
                                if(candidates[preferences[i][j]].eliminated==false){
                                    
                                    candidates[preferences[i][j]].votes +=1;
                                    break;
                                }
                        
                        
                    }

            
        }
    
    
    
    
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
        
        for(int i=0;i<candidate_count;i++){
                
                    if(candidates[i].votes>(voter_count/2)){
                        printf("%s",candidates[i].name);
                        return true;
                    }
            
            
        }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
        int minvotes=voter_count;
            for(int i=0;i<candidate_count;i++){
                        if(candidates[i].votes < minvotes && candidates[i].eliminated==false){
                            minvotes=candidates[i].votes;
                            
                        }
                                            
            }
    
  
    
    return minvotes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
        for(int i=0;i<candidate_count;i++){
                    if(candidates[i].eliminated== false && candidates[i].votes != min){
                            return false;
                        
                    }
            
        }
    return true;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    // TODO
    
    for(int i=0;i<candidate_count;i++){
                if(candidates[i].votes == min){
                        candidates[i].eliminated = true;  
                }
    }
   
    
    return;
}
