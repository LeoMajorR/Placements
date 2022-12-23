#include <bits/stdc++.h>
using namespace std;

/**
 * queryType: a list of strings representing the type of each query
 * query: a list of integers representing the data of each query
 * 
 * Example : QyerType = ["insert", "insert", "addToValue", "addToKey", "get"]   
 *          query = [[1, 2], [2, 3], [2], [1], [3]]
*/

long long solution(vector<string> queryType, vector<vector<int>> query)
{
    long long res = 0;
    unordered_map<int, int> m;
    int add = 0;
    for (int i = 0; i < queryType.size(); ++i) {
        if (queryType[i] == "insert") {
            m[query[i][0]] = query[i][1] - add;
        } else if (queryType[i] == "addToValue") {
            add += query[i][0];
        } else if (queryType[i] == "addToKey") {
            unordered_map<int, int> tmp;
            for (auto &p : m) {
                tmp[p.first + query[i][0]] = p.second;
            }
            m = tmp;
        } else {
            res += m[query[i][0]] + add;
        }
    }
    return res;
}