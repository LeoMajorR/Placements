#include <bits/stdc++.h>
using namespace std;

void addElem(stack<pair<int, int>> &s, int new_elem)
{
    int new_min = s.empty() ? new_elem : min(new_elem, s.top().second);
    s.push({new_elem, new_min});
}

void displayStack(stack<pair<int, int>> &s)
{
    while (!s.empty())
    {
        cout << s.top().first << " " << s.top().second << endl;
        s.pop();
    }
    cout << endl;
}

int removeElem(stack<pair<int, int>> &s)
{
    int elem = s.top().first;
    s.pop();
    return elem;
}

int main()
{
    stack<pair<int, int>> st;

    // add elements to stack
    addElem(st, 2);
    addElem(st, 3);
    addElem(st, 1);
    addElem(st, 4);
    addElem(st, 5);

    // print stack
    displayStack(st);

    // removing element
    cout << removeElem(st) << endl;
    cout << removeElem(st) << endl;

    // minimum
    cout << st.top().second << endl;
}