#include <stdio.h>
//#include<bits/stdc++.h>

struct snakes
{
    int snake_head;
    int snake_tail;
};

struct ladder
{
    int ladder_start;
    int ladder_tail;
};

// int checkonladder(int pos, int **ladder, int N)
// {
//     int temp = pos;
//     int flag = 1;
//     while(flag){
//         for(int i =0; i < N; i++)
//         {
//             if(temp == ladder[i][0])
//             {
//                 pos = ladder[i][1];
//                 i = 0;
//             }
//         }

//         if(temp==pos) flag = 0;
//     }

// }

// int checkonsnake(int pos, int **snake, int N)
// {
//     int temp = pos;
//     int flag = 1;
//     while(flag){
//         for(int i =0; i < N; i++)
//         {
//             if(temp == snake[i][0])
//             {
//                 pos = snake[i][1];
//                 i = 0;
//             }
//         }

//         if(temp==pos) flag = 0;
//     }
// }

int newpos(int pos, int **board, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (board[i][0] == pos)
        {
            return board[i][1];
        }
    }
    return pos;
}
int game(int *arr, int D, int N, int **board)
{
    int Apos = 0, Bpos = 0, chance = 0;
    char A, B;
    for (int i = 0; i < D; i++)
    {
        int diceval = arr[i];
        if (chance == 0)
        {
            if (Apos + diceval < 99)
            {
                Apos = Apos + diceval;
                newpos(Apos, board, N);
                newpos(Apos, board, N);
            }
            // Apos = newpos(board, N, Apos);
            chance = 1;
        }
        else
        {
            Bpos += diceval;
            newpos(Bpos, board, N);
            newpos(Bpos, board, N);
            chance = 0;
        }
    }
    if (Apos > Bpos)
    {
        printf("A", "    %d", Apos);
    }
    else
    {
        printf("B", "    %d", Bpos);
    }
}

void main()
{
    int N;
    int winner;
    // N is the number of ladders.
    // N is the number of snakes.

    printf("Enter the number of snakes and ladders:");
    scanf("%d", &N);
    int board[N][2];

    for (int i = 0; i < N; i++)
    {
        int p, q;
        printf("Enter the start cell for ladder/snake :");
        scanf("%d", &board[i][0]);
        printf("Enter the end cell for ladder/snake :");
        scanf("%d", &board[i][1]);
    }
    int D;
    printf("Enter the total number of moves made by both players A and B");
    scanf("%d", &D);
    int arr[D];
    printf("Enter the moves made by the players starting from player A : ");
    for (int i = 0; i < D; i++)
    {
        scanf("%d", &arr[i]);
    }
    game(&arr, D, N, **board);
}
