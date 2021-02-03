#include<iostream>

using namespace std;
class collegue;

class mediator{
    public:
        virtual void send(string message,collegue* clge) = 0;
};

class collegue{
    protected:
        mediator* my_mediator;
    public:
        collegue(mediator* md):my_mediator(md) {}
        virtual void send(string message) = 0;
        virtual void notify(string message) = 0;

};

class concretecollegue1:public collegue{
    public:
        concretecollegue1(mediator* md):collegue(md) {}
        void send(string message) {my_mediator->send(message,this);}
        void notify(string message) {cout<<"tongshi 1 get message:: "<<message<<endl;}
};

class concretecollegue2:public collegue{
    public:
        concretecollegue2(mediator* md):collegue(md) {}
        void send(string message) {my_mediator->send(message,this);}
        void notify(string message) {cout<<"tongshi2 get message:: "<<message<<endl;}
};

class concretemediator:public mediator{
    private:
        concretecollegue1* collegue1;
        concretecollegue2* collegue2;
    public:
        void set_collegue1(concretecollegue1* c) {collegue1=c;}
        void set_collegue2(concretecollegue2* c) {collegue2=c;}
        void send(string message,collegue* clge)
        {
            if(clge == collegue1)
                collegue2->notify(message);
            else
                collegue1->notify(message);
        }
};

int main()
{
    concretemediator* m = new concretemediator();
    
    concretecollegue1* c1 = new concretecollegue1(m);
    concretecollegue2* c2 = new concretecollegue2(m);

    m->set_collegue1(c1);
    m->set_collegue2(c2);

    c1->send("have eat ??");

    c2->send("no do you favor!");
    return 0;
}








