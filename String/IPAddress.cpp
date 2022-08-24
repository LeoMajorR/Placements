#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    for(auto elem : vec)
    {
        os<<elem<< " ";
    }
    os<<"\n";
    return os;
}

// check if given string is valid IPV4 address
bool isValid(string s)
{
    // split given string by '.'
    vector<string> v;
    string temp;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='.')
        {
            v.push_back(temp);
            temp="";
        }
        else
        {
            temp+=s[i];
        }
    }
    v.push_back(temp);
    
    for(int i=0;i<v.size();i++)
    {
        // check if each part of IP address has less than 3 digits and it lies in range 0-255
        if(v[i].length()>3 || stoi(v[i])>255 || stoi(v[i])<0) 
            return false;
        
        // check if each part of IP has length greater than 1 and it is not zero
        if(v[i].length()>1 && stoi(v[i])==0)
            return false;
        
        // check if each part of IP address has length greater than 1 and it does not start with 0
        if(v[i].length()>1 && stoi(v[i])!=0 && v[i][0]=='0')
            return false;
        
    }
    return true;
    
}

vector<string> generateIPAddress(string ip)
{
    int n = ip.size();
    if(n<4 || n>12)
    {
        return {};
    }
    vector<string> res;

    string check  = ip;
    // generate all possible ip address
    for(int i = 1;i<n-2;i++)
    {
        for(int j = i+1;j<n-1;j++)
        {
            for(int k = j+1;k<n;k++)
            {
                check = check.substr(0,k)+"."+check.substr(k);
                // cout<<check<<"\n";
                check = check.substr(0,j)+"."+check.substr(j);
                // cout<<check<<"\n";
                check = check.substr(0,i)+"."+check.substr(i);
                // cout<<check<<"\n";
                if(isValid(check))
                {
                    res.push_back(check);
                }
                // cout<<"-------------------\n";
                check = ip;
            }
        }
    }
    return res;
}


int main()
{
    string ipAddress1 = "2552818641";
    string ipAddress2 = "2481476174";
    cout<<"IP address : "<<generateIPAddress(ipAddress1)<<endl;
    // cout<<"IP address : "<<generateIPAddress(ipAddress2)<<endl;
    // cout<<"IP address : "<<generateIPAddress("222255")<<endl;
    return 0;
}