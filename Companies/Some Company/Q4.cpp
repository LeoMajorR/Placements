#include <bits/stdc++.h>
using namespace std;

/**
 * 
1->1
2->10
3->100
4->101
5->1000
6->1001
7->1010
8->1000
9->10001
10->10010
11->10100
12->100000
*/

template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    for(auto elem : vec)
    {
        os<<elem<< " ";
    }
    return os;
}

vector<int> arr(50);
string CodeGenerator (int N) {
    arr[0]=1;
    arr[1]=2;
    
    for(int i=2;i<40;i++)
    {
        arr[i] = arr[i-1] + arr[i-2]; 
    }
    cout<<arr<<endl;
    string s="";
    int f=0;
        
    for(int i=39;i>=0;i--){
        if(arr[i] <= N){
            f=1;
            s=s+"1";
            N = N-arr[i];
            continue;
        }
            
        if(f==1)
            s=s+"0";       
    }
        
    return s;
}

int main()
{
    cout<<CodeGenerator(3)<<endl;
    cout<<CodeGenerator(9)<<endl;
    cout<<CodeGenerator(5)<<endl;
    cout<<CodeGenerator(7)<<endl;
    return 0;
}
