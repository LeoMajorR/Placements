/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class NumMatrix
{
    vector<vector<int>> sum;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        for (auto &row : matrix)
        {
            vector<int> tmp;
            int s = 0; // sum of row
            for (auto &col : row)
            {
                s += col;
                tmp.push_back(s);
            }
            sum.push_back(tmp);
        }

        // display sum
        for (auto &row : sum)
        {
            for (auto &col : row)
            {
                cout << col << " ";
            }
            cout << endl;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int s = 0;                          // sum of region
        for (auto i = row1; i <= row2; i++) // sum of each row
        {
            if (col1 == 0)
                s += sum[i][col2];
            else
                s += sum[i][col2] - sum[i][col1 - 1];
        }
        return s;
    }
};

int main()
{
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
                                  {5, 6, 3, 2, 1},
                                  {1, 2, 0, 1, 5},
                                  {4, 1, 0, 1, 7},
                                  {1, 0, 3, 0, 5}};
    NumMatrix *obj = new NumMatrix(matrix);
    cout << obj->sumRegion(2, 1, 4, 3) << endl;
    cout << obj->sumRegion(1, 1, 2, 2) << endl;
    cout << obj->sumRegion(1, 2, 2, 4) << endl;
    return 0;
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
