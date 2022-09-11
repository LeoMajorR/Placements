#include <stdio.h>

int board[101] = {0};

// struct for saving start and end point of each snake and ladder
struct snakeLadder
{
    int start;
    int end;
};

struct Winner
{
    int player;
    int position;
};

struct Winner getWinner(int p1[], int p2[], int m)
{
    struct Winner winner;

    // initialize both players position to 0
    int p1_pos, p2_pos;
    p1_pos = p2_pos = 1;

    for (int i = 0; i < m / 2; i++)
    {
        // move player 1
        p1_pos += p1[i];
        // while snake or ladder is present
        while (board[p1_pos] != 0)
        {
            // snake
            if (board[p1_pos] < 0)
                p1_pos = -board[p1_pos];
            // ladder
            else
                p1_pos = board[p1_pos];
        }

        // check if player 1 is on the last position
        if (p1_pos >= 100)
        {
            winner.player = 1;
            winner.position = p1_pos - 1;
            return winner;
        }

        // move player 2
        p2_pos += p2[i];
        // while snake or ladder is present
        while (board[p2_pos] != 0)
        {
            // snake
            if (board[p2_pos] < 0)
                p2_pos = -board[p2_pos];
            // ladder
            else
                p2_pos = board[p2_pos];
        }

        // check if player 2 is on the last position
        if (p2_pos >= 99)
        {
            winner.player = 2;
            winner.position = p2_pos - 1;
            return winner;
        }
    }
    // if no one is on the last position, compare positions
    if (p1_pos > p2_pos)
    {
        winner.player = 1;
        winner.position = p1_pos - 1;
    }
    else if (p1_pos < p2_pos)
    {
        winner.player = 2;
        winner.position = p2_pos - 1;
    }
    else
    {
        winner.player = 0;
        winner.position = p1_pos - 1;
    }
    return winner;
}

int main()
{
    int n; // no of snakes and ladders
    scanf("%d", &n);

    // array of struct for storing start and end point of each snake and ladder
    struct snakeLadder snake[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &snake[i].start, &snake[i].end);
    }

    int m; // moves count
    scanf("%d", &m);
    int p1Moves[m / 2];
    int p2Moves[m / 2];

    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            scanf("%d", &p1Moves[i / 2]);
        }
        else
        {
            scanf("%d", &p2Moves[i / 2]);
        }
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

    struct Winner winner;

    winner = getWinner(p1Moves, p2Moves, m);
    if (winner.player == 0)
        printf("Draw\n");
    else
        printf("Player %d wins at position %d\n", winner.player, winner.position);
    return 0;
}