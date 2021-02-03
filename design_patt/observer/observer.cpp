#include<iostream>
#include<list>
#include<string>
using namespace std;


class Observer;
class subject{
    protected:
        string substate;
    public:
        virtual void attach(Observer *ob) = 0;
        virtual void detach(Observer *ob)= 0;
        virtual void notify() = 0;
        virtual void set_state(string str) = 0;
        virtual string get_state() =0;
};

class boss:public subject{
    private:
        list<Observer*> obs;
    public:
        void attach(Observer* ob)
        {
            obs.push_back(ob);
        }
        void detach(Observer *ob)
        {
            obs.remove(ob);
        }
        void notify();
        void set_state(string str)
        {
            substate = str;
        }
        string  get_state()
        {
            return substate;
        }

};

class Observer{
    protected:
        string name;
        subject *sub;
    public:
        Observer(string _name,subject *_sub):name(_name),sub(_sub) {}
        virtual void update() = 0;
};

class stockobserver:public Observer{
    public:
        stockobserver(string name,subject *sub):Observer(name,sub) {}
        void update()
        {
            cout<<sub->get_state()<<name<<"  close stock contine working"<<endl;
        }
};

class nbaobserver:public Observer{
public:
    nbaobserver(string _name,subject *_sub):Observer(_name,_sub) {}
    void update()
    {
        cout<<sub->get_state()<<name<<" close NBA "<<endl;
    }
};

void boss::notify()
{
    for(auto iter=obs.begin();iter!=obs.end();iter++)
    {
        (*iter)->update();
    }
}

int main()
{
    boss *huhansan = new boss();
    stockobserver *tongshi1 = new stockobserver(string("xiaocai"),huhansan);
    nbaobserver *tongshi2 = new nbaobserver(string("danao"),huhansan);
    huhansan->attach(tongshi1);
    huhansan->attach(tongshi2);
    huhansan->set_state(string("i am back  "));
    huhansan->notify();
    cout<<"2222"<<endl;
    huhansan->detach(tongshi2);
    huhansan->notify();
    return 0;
}
