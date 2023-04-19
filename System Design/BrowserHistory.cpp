#include <bits/stdc++.h>
using namespace std;

/**
 * @Intution: We can use a vector to store the history of the browser. We can use an iterator to point to the current position in the history. When we visit a new page, we can delete all the history after the current position and add the new page to the history. When we go back or forward, we can move the iterator to the corresponding position.
 * @Approach:
 * @Time Complexity: O(1)
 * @Space Complexity: O(n)
 */
class BrowserHistory
{
public:
    vector<string> history;
    vector<string>::iterator current;

    BrowserHistory(string homepage)
    {
        history.push_back(homepage);
        current = history.begin();
    }

    void visit(string url)
    {
        // if we are not at the end of the history
        if (current != history.end() - 1)
        {
            // delete all the history after the current position
            history.erase(current + 1, history.end());
        }
        history.push_back(url);
        current = history.end() - 1;
    }

    string back(int steps)
    {
        if (current - history.begin() < steps)
        {
            current = history.begin();
        }
        else
        {
            current -= steps;
        }
        return *current;
    }

    string forward(int steps)
    {
        if (history.end() - current <= steps)
        {
            current = history.end() - 1;
        }
        else
        {
            current += steps;
        }
        return *current;
    }
};

int main()
{
    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com");
    cout << browserHistory.back(1) << endl;
    cout << browserHistory.back(1) << endl;
    cout << browserHistory.forward(1) << endl;
    browserHistory.visit("linkedin.com");
    cout << browserHistory.forward(2) << endl;
    cout << browserHistory.back(2) << endl;
    cout << browserHistory.back(7) << endl;
    return 0;
}