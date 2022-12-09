#include <bits/stdc++.h>
using namespace std;

string getEncrypted(vector<int> numbers)
{
    int n = numbers.size();
    while (n > 2)
    {
        for (int i = 0; i < n - 1; i++)
        {
            numbers[i] = (numbers[i] + numbers[i + 1]) % 10;
        }
        n--;
    }
    return to_string(numbers[0]) + to_string(numbers[1]);
}

int main()
{
    vector<int> numbers = {4,5,6,7};
    cout << getEncrypted(numbers);
    return 0;
}