#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    /**
     * Algorithm: Greedy
     * 1. Iterate through the string S and record the last occurrence of each character
     * 2. Iterate through the string S again, keeping track of the last occurence of the current partition
     * 3. If the current index is the last occurrence of the current partition, then we have found a partition
     * 4. Add the length of the partition to the answer
     * 5. Repeat steps 2-4 until we have iterated through the entire string
     * 
     * Time: O(N), Space: O(1)
    */
    vector<int> partitionLabels(string S){
        vector<int> ans;
        int n = S.size();
        int last[26]; // last occurence of each character
        for(int i = 0; i < n; i++){
            last[S[i] - 'a'] = i;
        }
        int j = 0, anchor = 0; // anchor is the start of the current partition
        for(int i = 0; i < n; i++){
            j = max(j, last[S[i] - 'a']);
            if(i == j){
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return ans;
    }
};