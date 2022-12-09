#include <bits/stdc++.h>
using namespace std;


/**
 *  n : no of elements in array A
 * A : array of integers
 * k: no of queries in array h
 * h : array of integers
 * 
 * return : array of integers for each h find the number of elements in A which are greater than h
*/
vector<int> Solve(int n, vector<int> A, int k, vector<int> h)
{
    vector<int> ans;
    sort(A.begin(), A.end());
    for (int i = 0; i < k; i++)
    {
        int index = upper_bound(A.begin(), A.end(), h[i]) - A.begin();
        ans.push_back(n - index);
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<int> A = {1,5,3,2,4};
    int k = 2;
    vector<int> h = {2, 4};
    vector<int> ans = Solve(n, A, k, h);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;

}