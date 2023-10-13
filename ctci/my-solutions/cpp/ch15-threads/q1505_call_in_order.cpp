/*
CTCI - Chapter 15 - Question 5

Call in order: Suppose we have the following code:

public class Foo {
    public Foo() {...}
    public void first() {...}
    public void second() {...}
    public void third() {...}
}

The same instance of Foo will be passed to three different threads. ThreadA will
call first(), ThreadB will call second() and ThreadC will call third().Design a 
mechanism to ensure that first is called before second, and second is called 
before third. 

Solution:

Example:

Build:
Linux & Mac:
    g++ <file.cpp> or
    g++ -std=c++11 <file.cpp>
Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

const bool DEBUG = false;

mutex msecond;
mutex mthird;

class Foo 
{
public:

    static void first() {
        cout << "first" << endl;
        msecond.unlock();
    }

    static void second() {
        msecond.lock();
        cout << "second" << endl;
        mthird.unlock();
    }

    static void third() {
        mthird.lock();
        cout << "third" << endl;
    }
};

int main()
{
    Foo foo;

    msecond.lock();
    mthird.lock();

    thread ta(foo.first);
    thread tb(foo.second);
    thread tc(foo.third);

    ta.join();
    tb.join();
    tc.join();
    return 0;
}
