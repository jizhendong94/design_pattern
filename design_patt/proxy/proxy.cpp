#include<iostream>
#include<string>

using namespace std;

class schoolgirl{

public:
    string name;
    schoolgirl(string str):name(str) {}
};

class givgift{
public:
    virtual void givedolls() = 0;
    virtual void giveflowers() = 0;
    virtual void givechoc() = 0;
};

class pursuit:public givgift{
private:
    schoolgirl *mm;
public:
    pursuit(schoolgirl *smm):mm(smm) {}
    virtual void givedolls()
    {
        cout<<mm->name<<" give u dolls "<<endl;
    }
    virtual void giveflowers()
    {
        cout<<mm->name<<" give u flowers "<<endl;
    }
    virtual void givechoc()
    {
        cout<<mm->name<<" give u choc "<<endl;
    }
};

class proxy:public givgift{
private:
    pursuit *gg;
public:
    proxy(schoolgirl *smm)
    {
        gg = new pursuit(smm);
    }
    virtual void givedolls()
    {
        gg->givedolls();
    }
    virtual void giveflowers()
    {
        gg->giveflowers();
    }
    virtual void givechoc()
    {
        gg->givechoc();
    }
};



int main()
{
    schoolgirl *jiao=new schoolgirl("jiaojiao ");
    proxy *daili = new proxy(jiao);
    daili->givedolls();
    daili->giveflowers();
    daili->givechoc();
    return 0;
}
