#include<iostream>
#include<string>
using namespace std;

class handsetsoft{
    public:
       virtual void run() = 0;
};

class hansetgame:public handsetsoft{
    public:
        void run() {cout<<"phone game"<<endl;}
};

class hangsetaddress:public handsetsoft{
    public:
        void run() {cout<<"phone address"<<endl;}
};

class hangsetbrand{
    protected:
        handsetsoft* soft;
    public:
        void set_soft(handsetsoft* _soft) {soft=_soft;}
        virtual void run() = 0;
};

class hangsetbrandN:public hangsetbrand{
    public:
        void run() {soft->run();}
};

class hangsetbrandM:public hangsetbrand{
    public:
        void run() {soft->run();}
};

int main()
{
    hangsetbrand *ab = new hangsetbrandN();
    ab->set_soft(new hansetgame());
    ab->run();

    ab->set_soft(new hangsetaddress());
    ab->run();
    return 0;
}



