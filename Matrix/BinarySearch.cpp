#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int row = 0, col = n-1;
    while(row<m && col>=0)
    {
        if(matrix[row][col]==target)
            return true;
        else if(matrix[row][col]>target)
            col--;
        else
            row++;
    }
    return false;
}

int main()
{
    //[[1,4],[2,5]]
    vector<vector<int>> matrix = {{1, 4}, {2, 5}};
    int target = 2;
    cout << searchMatrix(matrix, target);
}