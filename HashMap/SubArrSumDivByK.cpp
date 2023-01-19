#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    /**
     * @algorithm: HashMap
     * 1. Create a map to store the frequency of the remainder of the sum of the subarray
     * 2. Traverse the array and update the sum and the remainder of the sum
     * 3. If the remainder is already present in the map, then add the frequency of the remainder to the count
     * 4. Increment the frequency of the remainder in the map
     * 5. Return the count
     * 
    */
    int subArraySumDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0, count=0;
        vector<int> res(k);
        res[0] = 1; // for the case when the sum is divisible by k
        for(auto i: nums)
        {
            sum += i;
            int rem = sum%k;
            if(rem<0) rem += k;
            count += res[rem];
            res[rem]++;
        }
        return count;
    }
};

