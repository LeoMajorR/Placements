#include <bits/stdc++.h>
using namespace std;

// 8*8 grid of buildings
// soldiers are dropped at a coordinate
// a soldier can control all the buildings in the same row and column
// return the buliding in control of the soldier
int GetBuildingCount(int input1, int **input2)
{
    int count = 0;
    set<int> row, col;
    set<pair<int, int>> rowcol;
    for (int i = 0; i < input1; i++)
    {
        int x = input2[i][0];
        int y = input2[i][1];
        row.insert(x);
        col.insert(y);
        rowcol.insert({x, y});
    }
    while (!row.empty())
    {
        count += 8;
        row.erase(row.begin());
    }
    while (!col.empty())
    {
        count += 8;
        col.erase(col.begin());
    }
    int n = rowcol.size();
    int diff = input1 - n;
    count -= input1;
    count += diff;
    return count;
}

int main()
{
    int input1 = 2;
    int **input2 = (int **)malloc(input1 * sizeof(int *));
    for (int i = 0; i < input1; i++)
        input2[i] = (int *)malloc(2 * sizeof(int));
    input2[0][0] = 5;
    input2[0][1] = 5;
    input2[1][0] = 5;
    input2[1][1] = 3;
    // input2[2][0] = 3;
    // input2[2][1] = 3;
    cout << GetBuildingCount(input1, input2);
}