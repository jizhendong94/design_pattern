#include<iostream>
#include<string>
#include<map>
using namespace std;
class user{
    public:
        user(string str):name(str) {}
        string get_name() {return name;}
    private:
        string name;
};
class website{
    public:
        virtual void use(user* who) = 0;
};

class concreteweb:public website{
    public:
        concreteweb(string str):name(str) {}
        void use(user* who) {cout<<"web type:: "<<name<<" yonghu:: "<<who->get_name()<<endl;}
    private:
        string name="";
};

class webfactory{

    private:
        map<string,website*>wbfc;
    public:
        website* get_web(string str)
        {
            if(wbfc.find(str)!=wbfc.end())
            {
                return wbfc[str];
            }
            else
            {
                concreteweb* w=new concreteweb(str);
                wbfc[str] = w;
                return wbfc[str];
            }
        }
        int getwebcount()
        {
            return wbfc.size();
        }
};

int main()
{
    webfactory* w = new webfactory();
    website* wx = w->get_web("show present");
    wx->use(new user("caibi"));
    
    website* wy = w->get_web("show present");
    wy->use(new user("dasheng"));


    website* wb = w->get_web("show blog");
    wb->use(new user("laowu"));

    website* wc = w->get_web("show blog");
    wc->use(new user("lao liu"));

    cout<<"the count is :: "<<w->getwebcount()<<endl;
    return 0;
}
