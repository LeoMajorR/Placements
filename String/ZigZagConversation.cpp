#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * Algorithm
     * 1. The string is divided into numRows rows, and each row is filled with a string.
     * 2. The first row is filled with the first numRows characters of the string, the second row is filled with the next numRows characters of the string, and so on.
     * 3. The characters in each row are filled in order from left to right, and the order of the rows is from top to bottom.
     * 4. The characters in the same row are filled in the same order as the characters in the string.
     */
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int n = s.size();
        string res = "";
        int cycleLen = 2 * numRows - 2; // cycleLength is
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j + i < n; j += cycleLen)
            {
                res += s[j + i];                                        // first element in each cycle
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) // middle elements in each cycle
                    res += s[j + cycleLen - i];
            }
        }
        return res;
    }
};
