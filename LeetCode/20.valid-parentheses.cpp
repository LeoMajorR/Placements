/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto it : s)
        {
            if (it == '(' || it == '{' || it == '[')
                st.push(it);
            else
            {
                if (st.size() == 0)
                    return false;
                char c = st.top();
                if (c == '(' && it == ')' || c == '{' && it == '}' || c == '[' && it == ']')
                    st.pop();
                else
                    return false;
            }
        }
        return st.size() == 0;
    }
};
// @lc code=end
