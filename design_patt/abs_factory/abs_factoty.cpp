#include<iostream>
using namespace std;

class productA{
public:
   virtual  void show() = 0;
};

class productA1:public productA{
    public:
        void show()
        {
            cout<<" product A1 "<<endl;
        }
};

class productA2:public productA{
    public:
        void show()
        {
            cout<<" product A2 "<<endl;
        }
};

class productB{
    public:
    virtual void show() = 0;
};

class productB1:public productB{
    public:
        void show()
        {
            cout<<" product B1 "<<endl;
        }
};

class productB2:public productB{
    public:
        void show()
        {
            cout<<" product B2 "<<endl;
        }
};

class factory{
    public:
        virtual productA* creatA() = 0;
        virtual productB* creatB() = 0;
};

class factory1:public factory{
    public:
        productA* creatA()
        {
            return new productA1();
        }
        productB* creatB()
        {
            return new productB1();
        }
};
class factory2:public factory{
    public:
        productA* creatA()
        {
            return new productA2();
        }
        productB* creatB()
        {
            return new productB2();
        }
};
int main()
{
    factory* fc = new factory1();
    productA* pa = fc->creatA();
    productB* pb= fc->creatB();
    pa->show();
    pb->show();
}
