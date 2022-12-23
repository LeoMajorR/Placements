#include <bits/stdc++.h>
using namespace std;

struct College
{
    string name;
    int seats;
};

struct Student
{
    int id;
    int marks;
    int noOfPrefers;
    vector<string> collegeName; //descending order of preference
};

int main()
{
    int N;
    // cout<<"Enter the number of colleges: ";
    cin>>N;
    vector<College> colleges(N);
    for(int i=0;i<N;i++)
    {
        // cout<<"Enter the name of college "<<i+1<<": ";
        cin>>colleges[i].name;
        // cout<<"Enter the number of seats in college "<<i+1<<": ";
        cin>>colleges[i].seats;
    }
    int c; //no of candidates
    // cout<<"Enter the number of candidates: ";
    cin>>c;
    vector<Student> students(c);
    for(int i=0;i<c;i++)
    {
        // cout<<"Enter the id of student "<<i+1<<": ";
        cin>>students[i].id;
        // cout<<"Enter the marks of student "<<i+1<<": ";
        cin>>students[i].marks;
        // cout<<"Enter the number of preferences of student "<<i+1<<": ";
        cin>>students[i].noOfPrefers;
        // cout<<"Enter the preferences of student "<<i+1<<": ";
        for(int j=0;j<students[i].noOfPrefers;j++)
        {
            string s;
            cin>>s;
            students[i].collegeName.push_back(s);
        }
    }
    sort(students.begin(),students.end(),[](Student a,Student b){
        return a.marks>b.marks;
    });
    vector<vector<int>> allotment(N);
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<students[i].noOfPrefers;j++)
        {
            for(int k=0;k<N;k++)
            {
                if(students[i].collegeName[j]==colleges[k].name)
                {
                    if(colleges[k].seats>0)
                    {
                        allotment[k].push_back(students[i].id);
                        colleges[k].seats--;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        cout<<"Allotment for college "<<colleges[i].name<<": ";
        for(int j=0;j<allotment[i].size();j++)
        {
            cout<<allotment[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}