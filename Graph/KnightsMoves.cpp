#include <bits/stdc++.h>
using namespace std;

class cell
{
public:
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

int minStepsToReachTarget(pair<int, int> knightsPos, pair<int, int> targetPos, int N)
{
    // knights moves' a;omg x and y directions
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    // queue for storing states of knight in board
    queue<cell> q;

    // push starting position of knight with 0 distance
    q.push(cell(knightsPos.first, knightsPos.second, 0));

    cell t;
    int x, y; // x and y coordinates of knight
    // 2d matrix of n+1 * n+1 to store visited cells
    // initialise all cells as not visited
    bool visited[N + 1][N + 1];
    memset(visited, false, sizeof visited);

    // visit starting state
    visited[knightsPos.first][knightsPos.second] = true;

    // loop until we have one element in queue
    while (!q.empty())
    {
        t = q.front();
        q.pop();

        // if current cell is equal to target cell,
        // return its distance
        if (t.x == targetPos.first && t.y == targetPos.second)
            return t.dis;

        // loop for all reachable states
        for (int i = 0; i < 8; i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];

            // If reachable state is not yet visited and
            // inside board, push that state into queue
            if (isInside(x, y, N) && !visited[x][y])
            {
                visited[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
    return -1;
}

int main()
{
    int N = 30;
    pair<int, int> knightPos = make_pair(1, 1);
    pair<int, int> targetPos = make_pair(30, 30);
    cout << minStepsToReachTarget(knightPos, targetPos, N);
    return 0;
}