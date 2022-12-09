#include <bits/stdc++.h>
using namespace std;
/**
[] denotes the operational precedence
& denotes the logical AND
| denotes the logical OR
! denotes the logical NOT
1 denotes the logical TRUE
0 denotes the logical FALSE
*/

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    for (auto elem : vec)
    {
        os << elem << " ";
    }
    return os;
}

// input :[|[&1[!0]][![|10][!1]]]]
// iteration 1: |[&1[!0]][![|10][!1]]]
// iteration 2: |[&1[!0]][![|10]]
// iteration 3: |[&1[!0]][!1]
// iteration 4: |[&1[!0]]
// iteration 5: |[&1]
// iteration 6: |1
// iteration 7: 1
// output : 1

vector<int> evaluateOutput(string input)
{
    vector<int> output;
    stack<char> s;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '[')
        {
            s.push(input[i]);
        }
        else if (input[i] == ']')
        {
            vector<int> temp;
            while (s.top() != '[')
            {
                if (s.top() == '1')
                {
                    temp.push_back(1);
                }
                else if (s.top() == '0')
                {
                    temp.push_back(0);
                }
                s.pop();
            }
            s.pop();
            int result = 0;
            if (s.top() == '|')
            {
                for (int i = 0; i < temp.size(); i++)
                {
                    result = result | temp[i];
                }
            }
            else if (s.top() == '&')
            {
                for (int i = 0; i < temp.size(); i++)
                {
                    result = result & temp[i];
                }
            }
            else if (s.top() == '!')
            {
                result = !temp[0];
            }
            s.pop();
            s.push(result + '0');
        }
        else
        {
            s.push(input[i]);
        }
    }

    while (!s.empty())
    {
        if (s.top() == '1')
        {
            output.push_back(1);
        }
        else if (s.top() == '0')
        {
            output.push_back(0);
        }
        s.pop();
    }

    return output;
}

int main()
{
    string input = "[|[&1[!0]][![|10][!1]]]]";
    vector<string> inp = {"[|", "[&", "1", "[!", "0", "]", "]", "[!", "[|", "10", "]", "[!", "1", "]", "]", "]", "]"};
    vector<int> ans = evaluateOutput(input);
    cout << ans << endl;
}