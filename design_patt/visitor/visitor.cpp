#include<iostream>
#include<string>
using namespace std;

class Action{
    public:
        virtual void getmanconclusion(Man* concreteA) = 0;
        virtual void getwomanconclusion(Woman* concreteB) = 0;
};

class Person{
    public:
        virtual void accept(Action* visitor) = 0;
};

class Succes:public Action{
    public:
        void getmanconclusion(Man* concreteA)
        {
            cout<<typeid(*concreteA).name()<<" "<<typeid(*this).name()<<"after has a girl"<<endl;
        }
        void getwomanconclusion(Woman* concreteB)
        {
            cout<<typeid(*concreteB).name()<<" "<<typeid(*this).name()<<"after has no man "<<endl;
        }
};

class Man:public Person{
    public:
        void accept(Action* visitor)
        {
            visitor->getmanconclusion(this);
        }
};

class Woman:public Person{
    public:
        void accept(Action* visitor)
        {
            visitor->getwomanconclusion(this);
        }
};

int main()
{
    Succes* Sces = new Succes();

}
