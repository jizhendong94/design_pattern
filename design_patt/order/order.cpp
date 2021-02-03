#include<iostream>
#include<string>
#include<list>
using namespace std;
class barbecur{
    public:
        void bakemutton() {cout<<"yang bake"<<endl;}
        void bakechickwing() {cout<<"chick wing bake"<<endl;}
};

class command{
    protected:
        barbecur*  receiver;
    public:
        command(barbecur* bbc):receiver(bbc) {}
        virtual void exec_cmd() = 0;
};

class bakemuttoncmd:public command{
    public:
        bakemuttoncmd(barbecur* bbc):command(bbc) {}
        void exec_cmd() {receiver->bakemutton();}
};

class bakechickwingcmd:public command{
    public:
        bakechickwingcmd(barbecur* bbc):command(bbc) {}
        void exec_cmd() {receiver->bakechickwing();}
};

class waitor{
    private:
        list<command*>cmd;
    public:
        void set_order(command* _cmd)
        {
            cmd.push_back(_cmd);
        }
        void cancel_order(command* _cmd)
        {
            cmd.remove(_cmd);
        }
        void notify()
        {
            for(auto it = cmd.begin();it!=cmd.end();it++)
            {
                (*it)->exec_cmd();
            }
        }
};

int main()
{
    barbecur *boy = new barbecur();
    command *bakemutton1 = new bakemuttoncmd(boy);
    command *bakemutton2 = new bakemuttoncmd(boy);
    command *bakechickwing = new bakechickwingcmd(boy);
    waitor *girl = new waitor();

    girl->set_order(bakemutton1);    
    girl->set_order(bakechickwing);
    girl->set_order(bakemutton2);

    girl->cancel_order(bakechickwing);
    girl->notify();
    return 0;
}
