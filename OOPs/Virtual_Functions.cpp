#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    virtual void calcArea()
    {
        cout << "Shape Area" << endl;
    }
};
class Rectangle : public Shape
{
public:
    int length, breadth, area;
    void calcArea()
    {
        cout << "Enter length and breadth of rectangle" << endl;
        cin >> length >> breadth;
        area = length * breadth;
        cout << "Rectangle Area: " << area << endl;
    }
};

class Square : public Shape
{
public:
    int side, area;
    void calcArea()
    {
        cout << "Enter side of square" << endl;
        cin >> side;
        area = side * side;
        cout << "Square Area: " << area << endl;
    }
};

int main()
{
    Shape *s;
    Rectangle r;
    Square sq;

    s = &r;
    s->calcArea();

    s = &sq;
    s->calcArea();
    return 0;
}