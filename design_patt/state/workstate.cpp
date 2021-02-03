#include<iostream>

using namespace std;

class work;
class state{
    public:
        virtual void write_pro(work* w) = 0;
};

class fornoonstate:public state{
    public:
        void write_pro(work* w);
};
class noonstate:public state{
    public:
        void write_pro(work* w);
};
class afternoonstate:public state{
    public:
        void write_pro(work* w);
};
class eveningstate:public state{
    public:
        void write_pro(work* w);
};
class sleepstate:public state{
    public:
        void write_pro(work* w);
};
class reststate:public state{
public:
    void write_pro(work* w);
};
class work{
    private:
        state *st;
        double hour;
        bool   finished = false;
    public:
        work()
        {
            st = new fornoonstate();
        }
        void set_hour(double val) {hour = val;}
        double get_hour() {return hour;}
        void set_finish(bool val) {finished = val;}
        bool get_finish()  {return finished;}
        void set_state(state* s) {st = s;}
        void write_pro();
};

void work::write_pro()
{
    st->write_pro(this);
}
void fornoonstate::write_pro(work* w)
{
    if(w->get_hour() < 12)
    {
        cout<<" current time "<<w->get_hour()<<" fornoon work"<<endl;
    }
    else
    {
        w->set_state(new noonstate());
        w->write_pro();
    }
}
void noonstate::write_pro(work* w)
{
    if(w->get_hour()<13){
        cout<<" current time "<<w->get_hour()<<" noon state work"<<endl;
    }
    else
    {
        w->set_state(new afternoonstate());
        w->write_pro();
    }
}
void afternoonstate::write_pro(work* w)
{
    if(w->get_hour()<17)
    {
        cout<<" current time "<<w->get_hour()<<" afternoon state "<<endl;
    }
    else
    {
        w->set_state(new eveningstate());
        w->write_pro();
    }
}
void eveningstate::write_pro(work* w)
{
    if(w->get_finish())
    {
        w->set_state(new reststate());
        w->write_pro();
    }
    else
    {
        if(w->get_hour()<21)
        {
            cout<<" current time "<<w->get_hour()<<" evening state"<<endl;
        }
        else
        {
            w->set_state(new sleepstate());
            w->write_pro();
        }
    }
}
void sleepstate::write_pro(work* w)
{
    cout<<" current time "<<w->get_hour()<<" sleep state"<<endl;
}
void reststate::write_pro(work* w)
{
    cout<<" current time "<<w->get_hour()<<" go home"<<endl;
}
int main()
{
    work* emwork = new work();
    emwork->set_hour(9);
    emwork->write_pro();

    emwork->set_hour(10);
    emwork->write_pro();

    emwork->set_hour(12);
    emwork->write_pro();

    emwork->set_hour(13);
    emwork->write_pro();

    emwork->set_hour(14);
    emwork->write_pro();

    emwork->set_hour(17);
    emwork->write_pro();

    emwork->set_finish(false);
    emwork->write_pro();

    emwork->set_hour(19);
    emwork->write_pro();

    emwork->set_hour(22);
    emwork->write_pro();

    return 0;
}
