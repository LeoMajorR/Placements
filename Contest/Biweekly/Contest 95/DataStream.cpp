#include <bits/stdc++.h>
using namespace std;

class DataStream {
public:
    int value;
    int k;
    int valCount=0;
    DataStream(int value, int k)
    {
        this->value = value;
        this->k = k;
    }
    bool consec(int num)
    {
        if(this->value==num)
            valCount++;
        else valCount=0;
        return valCount>=k;
    }
};