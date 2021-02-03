#include<iostream>
#include<string>
using namespace std;

class personbuilder{
public:
    virtual void buildhead() = 0;
    virtual void buildbody() = 0;
    virtual void buildleft() = 0;
    virtual void buildright() = 0;
};
class personthinbuild:public personbuilder{
public:
    virtual void buildhead()
    {
        cout<<"thin build head"<<endl;
    }
    virtual void buildbody()
    {
        cout<<"thin build body"<<endl;
    }
    virtual void buildleft()
    {
        cout<<"thin build left"<<endl;
    }
    virtual void buildright()
    {
        cout<<"thin build right"<<endl;
    }

};
class personfatbuild:public personbuilder{
public:
    virtual void buildhead()
    {
        cout<<"fat build head"<<endl;
    }
    virtual void buildbody()
    {
        cout<<"fat build body"<<endl;
    }
    virtual void buildleft()
    {
        cout<<"fat build left"<<endl;
    }
    virtual void buildright()
    {
        cout<<"fat build right"<<endl;
    }
};

class persondirector{
private: personbuilder *pb;
public:
    persondirector(personbuilder *_pb):pb(_pb) {}
    void createperson()
    {
        pb->buildhead();
        pb->buildbody();
        pb->buildleft();
        pb->buildright();
    }
};

int main()
{
    personthinbuild *thin = new personthinbuild(); 
    persondirector *pd = new persondirector(thin);
    pd->createperson();
    cout<<"2222"<<endl;
    personfatbuild *fat = new personfatbuild();
    pd = new persondirector(fat);
    pd->createperson();
    return 0;
}


