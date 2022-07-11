#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)                        //check if score1 greater than score 2
    {
        printf("Player 1 wins!\n");             // print player 1 wins
    }
    else if (score2 > score1)                   //check if score2 greater than score 1
    {
        printf("Player 2 wins!\n");             // print player 2 wins
    }
    else                                        // else print tie
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;                               //initilize score variable
    int pt = 0;                                  //initilize point variable

    for (int i = 0; i < strlen(word); i++)       // iterate over word
    {
        int ch = word[i];                       // get ascii equivalent of character
        if (isupper(ch))                        // if upper case substract 65 to ascii equivalent of char to get points equivablent (upper case alphabet start at ascii 65)
        {
            pt = POINTS[ch - 65];
        }
        else if (islower(ch))                   // else if lower case substract 97 to ascii equivalent of char to get points equivablent (lower case alphabet start at ascii 97)
        {
            pt = POINTS[ch - 97];
        }
        else
        {
            pt = 0;                             // else zero score if not alphabet
        }
        score += pt;
    }

    return score;                                // return score
}
