#include<iostream>
#include<string>
#include<map>
using namespace std;
class flyweight{
public:
    virtual void operation(int ex) = 0;
};

class concreteflyweight:public flyweight{
    public:
        concreteflyweight(string str):name(str) {}
        void operation(int ex) {cout<<"concrete flyweight:: "<<ex<<name<<endl;}
    private:
        string name;
};
class unsharedflyweight:public flyweight{
    public:
        void operation(int ex)  {cout<<"unshared flyweight:: "<<ex<<endl;}
};

class flyweightfactory{
    private:
        map<string,flyweight*>flyws;
    public:
        flyweight* get_fly(string key)
        {
            if(flyws.find(key)!= flyws.end())
                return flyws[key];
            else
            {
                concreteflyweight* f = new concreteflyweight(key);
                flyws[key] = f;
                return flyws[key];
            }
        }
};
int main()
{
    int ex = 22;
    flyweightfactory* f = new flyweightfactory();
    flyweight* fx  = f->get_fly("X");
    fx->operation(--ex);
    return 0;
}
