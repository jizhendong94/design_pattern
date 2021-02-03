#include<iostream>
using namespace std;

class interface{
public:
    virtual void show() = 0;
};

class realtk:public interface{
public:
    virtual void show()
    {
        cout<<"realtk show "<<endl;
    }
};

class proxy:public interface{
private:
    realtk *real;
public:
    virtual void show()
    {
        if(NULL == real)
            real=new realtk;
        real->show();
    }
};

int main()
{
    proxy *pro=new proxy;
    pro->show();
    return 0;
}
