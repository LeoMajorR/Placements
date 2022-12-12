#include <bits/stdc++.h>
using namespace std;

class MyHashMap{
    public:
        int arr[1000000];
        MyHashMap()
        {
            for (int i = 0; i < 1000000; i++)
            {
                arr[i] = -1;
            }
        }

        void put(int key,  int val)
        {
            arr[key] = val;
        }

        int get(int key)
        {
            return arr[key];
        }

        void remove(int key)
        {
            arr[key] = -1;
        }
};