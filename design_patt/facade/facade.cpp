#include<iostream>

using namespace std;

class subsystem1{
public:
    void method1()
    {
        cout<<"method1"<<endl;
    }
};

class subsystem2{
public:
    void method2()
    {
        cout<<"method2"<<endl;
    }
};

class subsystem3{
public:
    void method3()
    {
        cout<<"method3"<<endl;
    }
};

class facade{
subsystem1 *one;
subsystem2 *two;
subsystem3 *three;
public:
    facade()
    {
        one = new subsystem1();
        two = new subsystem2();
        three = new subsystem3();
    }
    void methodA()
    {
        cout<<"method A::"<<endl;
        one->method1();
        two->method2();
    }
    void methodB()
    {
        cout<<"method B::"<<endl;
        two->method2();
        three->method3();
    }
};
int main()
{
    facade *fa = new facade();
    fa->methodA();

    cout<<"2222"<<endl;
    fa->methodB();
    return 0;
}
