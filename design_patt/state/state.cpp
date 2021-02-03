#include<iostream>

using namespace std;

class context;
class state{
    public:
        virtual void handle(context* cntx) = 0;
};

class stateA:public state{
    public:
        stateA()
        {
        }
        void handle(context* cntx);
    private:
};

class stateB:public state{
    public:
        stateB()
        {
        }
        void handle(context* cntx);
    private:
};

class context{
    private:
        state* st;
    public:
        context(state* _st):st(_st) {}
        void set_state(state* val)
        {
            st = val;
        }
        state* get_state(void)
        {
            return st;
        }
        void requst();
};

void stateA::handle(context* cntx)
{
    cout<<" state A "<<endl;
    cntx->set_state(new stateB());
}
void stateB::handle(context* cntx)
{
    cout<<" state B "<<endl;
    cntx->set_state(new stateA());
}
void context::requst()
{
    st->handle(this);
}


int main()
{
    context* con = new context(new stateA());
    con->requst();

    con->requst();
    con->requst();
    con->requst();
    return 0;
}
