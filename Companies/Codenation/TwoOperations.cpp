#include <bits/stdc++.h>
using namespace std;


/**
 * 1.Given array A of length N
 * 2. Select any value of array and change it to other integer value
 * 3. Above operation can be performed no more than 2 times
 * 4. Create another array B which contains absolute difference of all pairs of elements of array A
 * 5. Minimize the sum of largest and smallest value of array B
 * 6. Return the sum of largest and smallest value of array B
*/
int solve(vector<int> &A)
{
    int n = A.size();
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            vector<int> B;
            for(int k = 0; k < n; k++)
            {
                if(k == i || k == j)
                    continue;
                B.push_back(abs(A[i] - A[k]));
                B.push_back(abs(A[j] - A[k]));
            }
            sort(B.begin(), B.end());
            ans = min(ans, B[0] + B[B.size() - 1]);
        }
    }
    return ans;
}