/**
 * @file MultiplePlayer.c
 * @author Upendra Katara
 * @rollno 2003327
 * @version 0.1
 * @date 2022-09-14
 */

#include <stdio.h>
#include <stdlib.h>

int board[101] = {0};

// struct for saving start and end point of each snake and ladder
struct snakeLadder
{
    int start;
    int end;
};

struct Winner
{
    char player;
    int position;
};

struct Winner getWinner(int m, int moves[], int trials)
{
    struct Winner winner;

    int posArr[m];
    // intilaize all players position to 1
    for (int i = 0; i < m; i++)
        posArr[i] = 1;

    printf("\n Player Position:\n");
    for (int i = 0; i < m; i++)
    {
        printf("Player %c: ", 'A' + i);
        for (int j = 0; j < trials; j++)
        {
            posArr[i] += moves[i * trials + j];
            printf("%d ", posArr[i] - 1);
            while (board[posArr[i]] != 0)
            {
                if (board[posArr[i]] < 0)
                    posArr[i] = -board[posArr[i]];
                else
                    posArr[i] = board[posArr[i]];
                printf("%d ", posArr[i] - 1);
            }
        }
        printf("\n");
    }

    // check the max position
    int max = 1;
    for (int i = 0; i < m; i++)
    {
        if (posArr[i] - 1 > max)
        {
            max = posArr[i] - 1;
            winner.player = 'A' + i;
            winner.position = max;
        }
    }
    return winner;
}

int main()
{

    int m; // players count
    // printf("Enter the number of players: ");
    scanf("%d", &m);

    int n; // no of snakes and ladders
    // printf("Enter the number of snakes and ladders: ");
    scanf("%d", &n);

    // array of struct for storing start and end point of each snake and ladder
    // printf("Enter the start and end point of each snake and ladder: ");
    struct snakeLadder snake[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &snake[i].start, &snake[i].end);
    }

    int d;
    // printf("Enter the number of dice trials: ");
    scanf("%d", &d);

    int moves[m * d];
    scanf("Enter the moves of each player: ");
    for (int i = 0; i < m * d; i++)
    {
        // generate a random number between 1 and 6
        int move = rand() % 6 + 1;
        moves[i] = move;
    }

    // display the moves of each player
    printf("Moves of Each player: \n");
    for (int i = 0; i < m; i++)
    {
        printf("Player %c: ", 'A' + i);
        for (int j = 0; j < d; j++)
        {
            printf("%d ", moves[i * d + j]);
        }
        printf("\n");
    }

    /**update board with snakes and ladders
     if start value is less than end value then it is a snake else ladder
     if start value is greater than end value then it is a ladder else snake*/
    for (int i = 0; i < n; i++)
    {
        // ladder
        if (snake[i].start < snake[i].end)
        {
            // update board with ladder
            board[snake[i].start + 1] = snake[i].end + 1;
        }
        else
        {
            // update board with snake
            board[snake[i].start + 1] = -(snake[i].end + 1);
        }
    }

    // display board in 10 *10
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         printf("%d ", board[i * 10 + j]);
    //     }
    //     printf("\n");
    // }

    struct Winner winner;
    winner = getWinner(m, moves, d);
    printf("Player %c wins at position %d\n", winner.player, winner.position);
    return 0;
}