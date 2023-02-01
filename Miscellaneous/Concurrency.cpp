#include <bits/stdc++.h>
using namespace std;

class Foo
{
public:
    mutex m;
    condition_variable cv;
    bool firstDone;
    bool secondDone;
    Foo()
    {
        firstDone = false;
        secondDone = false;
    }

    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstDone = true;
        cv.notify_all();
    }

    void second(function<void()> printSecond)
    {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this]
                { return firstDone; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondDone = true;
        cv.notify_all();
    }

    void third(function<void()> printThird)
    {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this]
                { return secondDone; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};