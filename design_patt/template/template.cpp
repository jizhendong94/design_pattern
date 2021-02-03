#include<iostream>
#include<string>

using namespace std;

class testpaper{
public:
    void test1()
    {
        cout<<"test1:: "<<"anser:: "<<anser1()<<endl;
    }
    void test2()
    {
        cout<<"test2:: "<<"anser:: "<<anser2()<<endl;
    }
    virtual string anser1() = 0;
    virtual string anser2() = 0;
};

class testpaperA:public testpaper{
public:
    virtual string anser1()
    {
        return string("a");
    }
    virtual string anser2()
    {
        return string("b");
    }
};


class testpaperB:public testpaper{
public:
    virtual string anser1()
    {
        return string("c");
    }
    virtual string anser2()
    {
        return string("d");
    }
};

int main()
{
    testpaper *A=new testpaperA();
    A->test1();
    A->test2();
    testpaper *B=new testpaperB();
    B->test1();
    B->test2();
    return 0;
}

