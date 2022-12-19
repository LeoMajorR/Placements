#include <bits/stdc++.h>
using namespace std;

//template class from displaying dictionary
template <typename T, typename U>
std::ostream & operator << (std::ostream & os, const std::unordered_map<T, U> & dict)
{
    for(auto elem : dict)
    {
        os<<elem.first<< " : " << elem.second << endl;
    }
    return os;
}


bool wordPattern(string pattern, string s)
{
    unordered_map<char, int> p2i;
    unordered_map<string, int> w2i;

    istringstream in(s); //input string stream

    int i=0, n=pattern.size(); 
    for(string word; in>>word; ++i) //read word by word
    {
        if(i==n || p2i[pattern[i]] != w2i[word]) //if pattern is not equal to word or pattern is not equal to word
            return false;
        p2i[pattern[i]] = w2i[word] = i+1; //if pattern is equal to word then add to dictionary
    }
    return i==n; //if pattern is equal to word then return true
}

int main()
{
    string pattern = "aaaa";
    string s = "dog cat cat dog";

    string pattern1 = "abc";
    string s1 = "dog cat dog";
    cout << wordPattern(pattern1, s1);
}