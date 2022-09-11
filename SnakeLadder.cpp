#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    for (auto elem : vec)
    {
        os << elem << " ";
    }
    return os;
}

// 2d matrix from 0-99
vector<int> board(101, 0);

int playGame(vector<pair<int, int>> snakes, vector<pair<int, int>> ladders, vector<int> p1, vector<int> p2)
{
    int n = snakes.size();
    int m = ladders.size();

    // snakes
    for (int i = 0; i < n; i++)
        board[snakes[i].first + 1] = -(snakes[i].second + 1);

    // ladder
    for (int i = 0; i < m; i++)
        board[ladders[i].first + 1] = ladders[i].second + 1;

    // display board in 10x10 matrix
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << board[i * 10 + j] << " ";
        }
        cout << endl;
    }

    // take two pointer to keep track of current position of both players
    int p1_pos = 1;
    int p2_pos = 1;
    // increment position of player 1 at time

    // initialize the matrix
    for (int i = 0; i < p1.size(); i++)
    {
        // move player 1
        p1_pos += p1[i];
        while (board[p1_pos] != 0)
        {
            // if snake
            if (board[p1_pos] < 0)
                p1_pos = -board[p1_pos];
            // if ladder
            else
                p1_pos = board[p1_pos];
        }
        if (p1_pos >= 99)
            return 1;

        // move player 2
        p2_pos += p2[i];
        // if player 2 is on a snake or ladder, move him to the new position
        while (board[p2_pos] != 0)
        {
            // if snake
            if (board[p2_pos] < 0)
                p2_pos = -board[p2_pos];
            // if ladder
            else
                p2_pos = board[p2_pos];
        }
        if (p2_pos >= 99)
            return 2;

        // display position of both players
        cout << "Player 1: " << p1_pos - 1 << " Player 2: " << p2_pos - 1 << endl;
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
    cin >> n;
    // n = 2;

    // for snakes start value will be greater than end value
    // for ladders start value will be less than end value
    vector<pair<int, int>> snakes, ladders;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        if (s > e)
            snakes.push_back(make_pair(s, e));
        else
            ladders.push_back(make_pair(s, e));
    }
    // snakes = {{96, 13}};
    // ladders = {{26, 87}};

    int movesCount = 0;
    cin >> movesCount;
    // movesCount = 18;
    // p1 & p1 makes moves alternatively
    vector<int> p1, p2;

    for (int i = 0; i < movesCount; i++)
    {
        int m;
        cin >> m;
        if (i % 2 == 0)
            p1.push_back(m);
        else
            p2.push_back(m);
    }

    // p1 = {4, 3, 6, 6, 2, 4, 1, 5, 4};
    // p2 = {1, 2, 3, 3, 4, 2, 1, 2, 6};
    int winner = playGame(snakes, ladders, p1, p2);

    cout << winner << endl;
    return 0;
}