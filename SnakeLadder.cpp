#include <bits/stdc++.h>
using namespace std;

// 2d matrix from 0-99
vector<int> board(100, 0);

int playGame(vector<pair<int, int>> snakes, vector<pair<int, int>> ladders, vector<int> p1, vector<int> p2)
{
    int n = snakes.size();
    int m = ladders.size();

    // for snake update the board with negative value of its new position
    for (int i = 0; i < n; i++)
        board[snakes[i].first] = {-snakes[i].second};

    // for ladder update the board with positive value of its new position
    for (int i = 0; i < m; i++)
        board[ladders[i].first] = {ladders[i].second};

    // take two pointer to keep track of current position of both players
    int p1_pos = 0;
    int p2_pos = 0;
    // increment position of player 1 at time

    // initialize the matrix
    for (int i = 0; i < p1.size(); i++)
    {
        // move player 1
        p1_pos += p1[i];
        // if player 1 is on a snake or ladder, move him to the new position
        if (board[p1_pos] < 0)
            p1_pos = -board[p1_pos];
        else if (board[p1_pos] > 0)
            p1_pos = board[p1_pos];
        // check if player 1 is on a winning position
        if (p1_pos == 100)
            return 1;

        // move player 2
        p2_pos += p2[i];
        // if player 2 is on a snake or ladder, move him to the new position
        if (board[p2_pos] < 0)
            p2_pos = -board[p2_pos];
        else if (board[p2_pos] > 0)
            p2_pos = board[p2_pos];
        // check if player 2 is on a winning position
        if (p2_pos == 100)
            return 2;
    }
    // compare position of both players and return the winner
    if (p1_pos > p2_pos)
        return 1;
    else if (p1_pos < p2_pos)
        return 2;
    else
        return 0;
}

int main()
{
    // n- no of snakes and ladders
    int n;
    // cin >> n;
    n = 2;

    // for snakes start value will be greater than end value
    // for ladders start value will be less than end value
    vector<pair<int, int>> snakes, ladders;
    // for (int i = 0; i < n; i++)
    // {
    //     int s, e;
    //     cin >> s >> e;
    //     if (s > e)
    //         snakes.push_back(make_pair(s, e));
    //     else
    //         ladders.push_back(make_pair(s, e));
    // }
    snakes = {{96, 13}};
    ladders = {{26, 87}};

    int movesCount = 0;
    // cin >> movesCount;
    movesCount = 18;
    // p1 & p1 makes moves alternatively
    vector<int> p1, p2;

    // for (int i = 0; i < movesCount; i++)
    // {
    //     int m;
    //     cin >> m;
    //     if (i % 2 == 0)
    //         p1.push_back(m);
    //     else
    //         p2.push_back(m);
    // }

    p1 = {4, 3, 6, 6, 2, 4, 1, 5, 4};
    p2 = {1, 2, 3, 3, 4, 2, 1, 2, 6};
    int winner = playGame(snakes, ladders, p1, p2);
    cout << winner << endl;
    return 0;
}