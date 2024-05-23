#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score_system[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 13, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int score_calc(string Wordby1); // calculate 1st player score

int main(void)
{
    string Player1Word = get_string("Player 1: ");
    string Player2Word = get_string("\nPlayer 2: ");

    int scoreP1 = score_calc(Player1Word);
    int scoreP2 = score_calc(Player2Word);
    if (scoreP1 > scoreP2)
    {
        printf("Player 1 wins!\n");
    }
    else if (scoreP1 < scoreP2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int score_calc(string Wordby1) // calculator score
{
    int sum = 0; // sum of points
    for (int i = 0, scrabblesize_1 = strlen(Wordby1); i < scrabblesize_1; i++)
    {
        int alphanumber = toupper(Wordby1[i]) - 'A';

        if (alphanumber >= 0 && alphanumber <= 25)
        {
            sum += score_system[alphanumber];
        }
    }
    return sum;
}
