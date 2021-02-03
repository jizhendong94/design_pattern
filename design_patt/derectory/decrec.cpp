#include<iostream>
#include<string>
using namespace std;

class person{
private:
    string name;
public:
    person() =default;
    void set_name(string str)
    {
        this->name = str;
    }
    virtual void show(void)
    {
        cout<<"person:: "<<name<<endl;
    }
};


class finery:public person{
private:
    person *fperson;
public:
    finery(person *ps):fperson(ps) {}
    void show(void)
    {
        fperson->show();
    }
};

class Tshirt:public finery{
public:
    Tshirt(person *ps):finery(ps) {}
    void show()
    {
        cout<<"Tshirt"<<endl;
        finery::show();
    }
};

class bighos:public finery{
public:
    bighos(person *ps):finery(ps) {}
    void show()
    {
        cout<<"bighos"<<endl;
        finery::show();
    }
};

class xizhuang:public finery{
public:
    xizhuang(person *ps):finery(ps) {}
    void show()
    {
        cout<<"xizhuang"<<endl;
        finery::show();
    }

};
int  main()
{
    person *pson = new person;
    pson->set_name("xiaocai");
    pson->show();

    cout<<"2"<<endl;
    Tshirt *ts = new Tshirt(pson);
    ts->show();
    bighos *bs = new bighos(ts);

    cout<<"3"<<endl;
    bs->show();

    cout<<"4"<<endl;
    xizhuang *xz = new xizhuang(bs);
    xz->show();
    return 0;
}





