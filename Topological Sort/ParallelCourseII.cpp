#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @Approach: Topological Sort
     * @Time complexity: O(V+E)
     * @params: n = number of courses
     * @params: relations = vector of vector of int, where each vector represents a dependency
     * @params: k = maximum number of courses that can be taken in a semester
     * return the minimum number of semesters to take all courses
     */
    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k)
    {
        }
};

int main()
{
    Solution s;
    int n = 4;
    vector<vector<int>> relations = {{2, 1}, {3, 1}, {1, 4}};
    int k = 2;
    cout << s.minNumberOfSemesters(n, relations, k) << endl;
    n = 5;
    relations = {{2, 1}, {3, 1}, {4, 1}, {1, 5}};
    k = 2;
    cout << s.minNumberOfSemesters(n, relations, k) << endl;
}
