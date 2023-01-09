#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int n = costs.size();
        int i = 0;
        while(i<n && coins>=costs[i])
        {
            coins -= costs[i];
            i++;
        }
        return i;
    }
};