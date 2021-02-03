#include<iostream>
using namespace std;

class implementor{
    public:
        virtual void operation() = 0;
};

class concreterimplementA:public implementor{
    public:
        void operation() {cout<<"concreteA operation"<<endl;}
};

class conreterimplementB:public implementor{
    public:
        void operation() {cout<<"concreterB operation"<<endl;}
};

class abstrator{
    protected:
        implementor* im;
    public:
        void set_im(implementor* _im) {im=_im;}
        void operation() {im->operation();}
};

class redefineabstrator:public abstrator{
    public:
        void operation() {im->operation();}
};



int main()
{
    abstrator* ab = new redefineabstrator();
    ab->set_im(new concreterimplementA());
    ab->operation();

    ab->set_im(new conreterimplementB());
    ab->operation();
    return 0;
}
