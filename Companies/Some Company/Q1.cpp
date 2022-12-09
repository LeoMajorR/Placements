#include <bits/stdc++.h>
using namespace std;

long long int arr[50]; 
string CodeGenerator (int N) {
    arr[0]=1;
    arr[1]=2;
    
    for(int i=2;i<40;i++)
    {
        arr[i] = arr[i-1] + arr[i-2]; 
    }
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