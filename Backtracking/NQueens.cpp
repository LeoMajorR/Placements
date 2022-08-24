#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> chess, int row, int col)
{
    // check for row
    for (int i = 0; i < col; i++)
        if (chess[row][i] == 'Q')
            return false;

    // check for upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (chess[i][j] == 'Q')
            return false;

    // check for lower diagonal
    for (int i = row, j = col; i < chess.size() && j >= 0; i++, j--)
        if (chess[i][j] == 'Q')
            return false;
    // check for column
    for (int i = 0; i < chess.size(); i++)
        if (chess[i][col] == 'Q')
            return false;
    return true;
}

void nQueensUtil(vector<string> chess, vector<vector<string>> &res, int row)
{
    // base case
    if (chess.size() == 0)
        return;

    // if we reach last row, then add the solution to the result
    if (chess.size() == row)
    {
        res.push_back(chess);
        return;
    }

    // try all columns in the current row
    for (int col = 0; col < chess[0].size(); col++)
    {
        // if the current column is not safe, then continue
        if (isSafe(chess, row, col))
        {
            // place the queen in the current column
            chess[row][col] = 'Q';
            // recurse for the next row
            nQueensUtil(chess, res, row + 1);
            // remove the queen from the current column
            chess[row][col] = '#';
        }
    }
}

vector<vector<string>> nQueens(int n)
{
    vector<vector<string>> result; // result

    string temp;

    for (int i = 0; i < n; i++)
        temp += "#";

    vector<string> board(n, temp); // initialize board
    nQueensUtil(board, result, 0); // call nQueensUtil
    return result;
}

int main()
{
    int n = 4;
    vector<vector<string>> res = nQueens(n);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << endl;
        cout << endl;
    }
}