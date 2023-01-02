#include <bits/stdc++.h>
using namespace std;

class Instructor{
    string name;
    string address;
    string phone;
    string email;
    string designation;
    vector<Courses> courses;
};


class Courses{
    string courseID;
    string courseName;
    int credits;
    Instructor instructor;
};

class Student
{
    string name;
    int roll;
    int age;
    string address;
    string phone;
};

class Department
{
    string name;
    string hod;
    vector<Student> students;
    vector<Instructor> instructors;
};
