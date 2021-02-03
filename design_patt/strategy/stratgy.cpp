#include<iostream>
using namespace std;

class strategy{
public:
    virtual void algo_interface() = 0 ;

};

class concretstrategya:public strategy{
public:
    void algo_interface()
    {
        cout<<"strategy A  "<<endl;
    }
};

class conretstrategyb:public strategy{
public:
    void algo_interface()
    {
        cout<<"strategy B "<<endl;
    }
};

class concretstrategyc:public strategy{
public:
    void algo_interface()
    {
        cout<<"strategy C "<<endl;
    }
};


class context{
private:
    strategy *stg;
public:
    context(strategy *strag):stg(strag) {}
    void contextinterface()
    {
        stg->algo_interface();
    }
};

void test_fn(void)
{
    cout<<"hello world"<<endl;
}

int main()
{
    concretstrategya *stagya = new concretstrategya;
    conretstrategyb  *stagyb = new conretstrategyb;
    context *ctxt = new context(stagya);
    ctxt->contextinterface();
    ctxt=new context(stagyb);
    ctxt->contextinterface();
    test_fn();
}
