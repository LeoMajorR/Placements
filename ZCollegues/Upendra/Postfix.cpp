// Given a postfix expression in terms of character string containing integer and binary operator +, -, * and /,
// evaluate the postfix expression and print its value. Assume blank space as a separator between two tokens. You
// are expected to use stack container class from STL. Assume that the given input is valid postfix expression
// and there is no need for you to test the validity of the input expression.
// The functions associated with stack are:
// • empty() – Returns whether the stack is empty
// • size() – Returns the size of the stack
// • top() – Returns a reference to the top most element of the stack
// • push(g) – Adds the element ‘g’ at the top of the stack
// • pop() – Deletes the top most element of the stack
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evaluatePostfix(string S)
    {
        stack<int> st;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == ' ')
                continue;
            else if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/')
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                switch (S[i])
                {
                case '+':
                    st.push(val2 + val1);
                    break;
                case '-':
                    st.push(val2 - val1);
                    break;
                case '*':
                    st.push(val2 * val1);
                    break;
                case '/':
                    st.push(val2 / val1);
                    break;
                }
            }
            else
            {
                int val = 0;
                while (i < S.length() && S[i] >= '0' && S[i] <= '9')
                {
                    val = (val * 10) + (S[i] - '0');
                    i++;
                }
                i--;
                st.push(val);
            }
        }
        return st.top();
    }
};

int main()
{
    string s = "23 7 *";
    string s1 = "25 45 5 * +";
    string s2 = "25 45 5 * - ";
    Solution obj;
    cout << obj.evaluatePostfix(s) << endl;
    cout << obj.evaluatePostfix(s1) << endl;
    cout << obj.evaluatePostfix(s2) << endl;
    return 0;
}