#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    /**
     * Algorithm: Greedy
     * 1. If the total number of gas is bigger than the total number of cost. There must be a solution.
     * 2. The tank should never be negative, so restart whenever the tank is negative.
     * 3. The tank should be zero when we move the start pointer to the next station.
     * 4. If the total number of gas is equal to the total number of cost. There is a solution if and only if the tank is zero when we move the start pointer to the next station.
     * 5. If the total number of gas is bigger than the total number of cost. There must be a solution.
     * 6. If the total number of gas is smaller than the total number of cost. There is no solution.
     * 7. The key is to make sure that the tank is never negative.
     * 8. If the tank is negative, move the start pointer to the next station.
     * 9. If the tank is zero, move the start pointer to the next station.
     * 10. If the tank is positive, move the end pointer to the next station.
     * 
    */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int start = 0;
        int end = 1;
        if(n == 1)
            return gas[0] >= cost[0] ? 0 : -1;
        int curr = gas[start] - cost[start]; //surplus gas
        while(start != end || curr < 0)
        {
            while(start != end && curr < 0)// if curr < 0, then we need to move start
            {
                curr -= gas[start] - cost[start];
                start = (start + 1) % n; // move start pointer to the next station
                if(start == 0)
                    return -1;
            }
            curr += gas[end] - cost[end]; // move end
            end = (end + 1) % n;
        }
        return start;
    }
};

