#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int rowBegin = 0, rowEnd = n - 1, colBegin = 0, colEnd = n - 1;
    int num = 1;
    while (rowBegin <= rowEnd && colBegin <= colEnd)
    {
        // Traverse Right
        for (int i = colBegin; i <= colEnd; i++)
            matrix[rowBegin][i] = num++;
        rowBegin++;

        // Traverse Down
        for (int i = rowBegin; i <= rowEnd; i++)
            matrix[i][colEnd] = num++;
        colEnd--;

        // Traverse Left
        if (rowBegin <= rowEnd)
        {
            for (int i = colEnd; i >= colBegin; i--)
                matrix[rowEnd][i] = num++;
        }
        rowEnd--;

        // Traverse Up
        if (colBegin <= colEnd)
        {
            for (int i = rowEnd; i >= rowBegin; i--)
                matrix[i][colBegin] = num++;
        }
        colBegin++;
    }
    return matrix;
}

int main()
{
    int n = 3;
    vector<vector<int>> matrix = generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}