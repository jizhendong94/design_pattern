#include<iostream>
#include<string>
using namespace std;

class memento{
    private:
        string state;
    public:
        memento(string str):state(str) {}
        string get_state() {return state;}
};


class originator{
    private:
        string state;
    public:
        void set_state(string str) {state = str;}
        string get_state(void) {return state;}

        memento* creat_mem() {return new memento(state);}

        void set_mem(memento* mem) {state = mem->get_state();}
        void show()
        {
            cout<<" state is "<<state<<endl;
        }
};
class caretaker{
    private:
        memento* mem;
    public:
        void set_mem(memento* _mem) {mem=_mem;}
        memento* get_mem(void) {return mem;}

};

int main()
{
    originator* o = new originator();
    o->set_state(string("ON"));
    o->show();

    caretaker* c = new caretaker();
    c->set_mem(o->creat_mem());

    o->set_state(string("OFF"));
    o->show();


    o->set_mem(c->get_mem());
    o->show();
    return 0;
}
