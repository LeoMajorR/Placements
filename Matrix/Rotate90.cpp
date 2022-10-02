#include <bits/stdc++.h>
using namespace std;

void rotateBy90(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            // swap(matrix[i][j], matrix[j][n - i - 1]);
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = temp;
        }
    }
}

void rotate(vector<vector<int>>& matrix) 
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>ans(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        int k=0;
        for(int j=0;j<m;j++)
        {
           int t=matrix[i][j];
           ans[k++][m-1-i]=t;    
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            matrix[i][j]=ans[i][j];
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    rotateBy90(matrix);
    //display matrix
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}