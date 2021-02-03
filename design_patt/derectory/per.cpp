#include<iostream>
#include<string>
using namespace std;


class absperson{
public:
    virtual void show(void) = 0;
};

class person:public absperson{
private:
    string name;
public:
    virtual void show()
    {
        cout<<"person::"<<endl;
    }
};

class decrator:public absperson{
public:
    decrator(absperson *ps):myperson(ps) {}
    virtual void show()
    {
        myperson->show();
    }
private:
    absperson *myperson;
};

class tshirt:public decrator{
public:
    tshirt(absperson *ps):decrator(ps) {}
    virtual void show()
    {
        cout<<"tshirt"<<endl<<endl;
        decrator::show();
    }
};

class bighos:public decrator{
public:
    bighos(absperson *ps):decrator(ps) {}
    virtual void show()
    {
        cout<<"big house"<<endl<<endl;
        decrator::show();
    }
};

class shoe:public decrator{
public:
    shoe(absperson *ps):decrator(ps) {}
    virtual void show()
    {
        cout<<"shoe"<<endl<<endl;
        decrator::show();
    }
};
int main()
{
    person *ps1 = new person();
    cout<<"1111"<<endl;
    ps1->show();

    cout<<"2222"<<endl;
    tshirt ts=tshirt(ps1);
    ts.show();
    
    cout<<"3333"<<endl;
    bighos bh=bighos(&ts);
    bh.show();

    cout<<"4444"<<endl;
    shoe se=shoe(&bh);
    se.show();
    return 0;
}
