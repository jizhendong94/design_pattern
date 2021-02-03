#include<iostream>
#include<string>
using namespace std;

void print(string str)
{
    cout<<"|__________________"<<endl<<"|"<<str<<":"<<endl;
}

class abstable
{
public:
    virtual void puttable() = 0;
};

class basetable:public abstable
{
public:
    virtual void puttable()
    {
        print("xingming");
        print("xuehao");
        print("xueli");
        print("nianling");
        cout<<"|___________"<<endl;
    }
};

class decrator:public abstable
{
private:
    abstable *myabstable;
public:
    decrator(abstable *as):myabstable(as) {}
    virtual void puttable()
    {
        myabstable->puttable();
    }
};


class english:public decrator
{
public:
    english(abstable *abs):decrator(abs) {}
    virtual void puttable()
    {
        print("yingyudengji");
        decrator::puttable();
    }
    
};

class curwage:public decrator
{
public:
    curwage(abstable *abs):decrator(abs) {};
    virtual void puttable()
    {
        print("curwage");
        decrator::puttable();
    }
};

class experience:public decrator
{
public:
    experience(abstable *abs):decrator(abs) {};
    virtual void puttable()
    {
        print("expterince");
        decrator::puttable();
    }
};


int main()
{
    basetable pro1;
    cout<<"1111"<<endl<<endl;
    pro1.puttable();
    
    cout<<"2222"<<endl<<endl;
    english eng(&pro1);
    eng.puttable();
    
    cout<<"3333"<<endl<<endl;
    curwage wg(&eng);
    wg.puttable();
    
    cout<<"4444"<<endl<<endl;
    experience ex(&wg);
    ex.puttable();
    
    return 0;
}
