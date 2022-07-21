// Priority Queue using Array

#include <bits/stdc++.h>
using namespace std;

int size = -1;

struct node
{
    int data;
    int priority;
};

node pr[100000];

void enqueue(int data, int priority)
{
    size++;
    pr[size].data = data;
    pr[size].priority = priority;
}

int peek()
{
    int highest_priority = INT_MIN;
    int ind = -1;

    // check element with highest priority
    for (int i = 0; i < size; i++)
    {
        if (highest_priority == pr[i].priority && ind > -1 && pr[ind].data < pr[i].data)
        {
            highest_priority = pr[i].priority;
            ind = i;
        }
        else if (highest_priority < pr[i].priority)
        {
            highest_priority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}

void dequeue()
{
    int ind = peek();
    pr[ind].data = pr[size].data;
    pr[ind].priority = pr[size].priority;
    size--;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the queue: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data, priority;
        cout << "Enter the data and priority of the element: ";
        cin >> data >> priority;
        enqueue(data, priority);
    }
    int ind;
    ind = peek();
    cout << "The element with highest priority is: " << pr[ind].data << endl;
    dequeue();
    ind = peek();
    cout << "The element with highest priority is: " << pr[ind].data << endl;
    return 0;
}