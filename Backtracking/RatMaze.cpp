#include <bits/stdc++.h>
using namespace std;

void findPathUtil(vector<vector<int>> &m, int n, int row, int col, string path, vector<string> &ans, vector<vector<bool>> &visited)
{
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }

    if (row < 0 || col < 0 || row >= n || col >= n || m[row][col] == 0 || visited[row][col])
        return;

    visited[row][col] = true;

    findPathUtil(m, n, row + 1, col, path + "D", ans, visited);
    findPathUtil(m, n, row, col - 1, path + "L", ans, visited);
    findPathUtil(m, n, row, col + 1, path + "R", ans, visited);
    findPathUtil(m, n, row - 1, col, path + "U", ans, visited);

    visited[row][col] = false;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    int row = 0, col = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    string path;
    findPathUtil(m, n, row, col, path, ans, visited);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    vector<string> ans = findPath(m, n);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}