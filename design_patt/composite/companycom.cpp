#include<iostream>
#include<string>
#include<list>
using namespace std;

class company{
    protected:
        string name;
    public:
        company(string str):name(str) {};
        virtual void add(company* c) = 0;
        virtual void remove(company* c) = 0;
        virtual void display(int depth) = 0;
        virtual void lineofduty() = 0;
};

class concretecompany:public company{
    private:
        list<company*>child;
    public:
    concretecompany(string str):company(str) {}
    void add(company* c) {child.push_back(c);}
    void remove(company* c) {child.remove(c);}
    void display(int depth)
    {
        int new_dp = depth;
        while(depth--)
            cout<<"-";
        cout<<name<<endl;
        for(auto it = child.begin();it!=child.end();it++)
            (*it)->display(new_dp+2);
    }
    void lineofduty()
    {
        for(auto it= child.begin();it!=child.end();it++)
            (*it)->lineofduty();
    }
};

class hrdepartment:public company{
    public:
        hrdepartment(string str):company(str) {}
        void add(company* c) {}
        void remove(company* c) {}
        void display(int depth)
        {
            while(depth--)
                cout<<"-";
            cout<<name<<endl;
        }
        void lineofduty() {cout<<name<<" HR managment"<<endl;}
};

class financedepartment:public company{
    public:
        financedepartment(string str):company(str) {}
        void add(company* c) {}
        void remove(company* c) {}
        void display(int depth)
        {
            while(depth--)
                cout<<"-";
            cout<<name<<endl;
        }
        void lineofduty() {cout<<name<<" finance managment"<<endl;}
};
int main()
{
    concretecompany* root = new concretecompany("beijing zong ");
    root->add(new hrdepartment("beijing hr"));
    root->add(new financedepartment("beijing finace"));

    concretecompany* comp = new concretecompany("shanghai fen");
    comp->add(new hrdepartment("shanghai hr"));
    comp->add(new financedepartment("shanghai fiance"));

    root->add(comp);
    
    concretecompany* comp2 = new concretecompany(" hang zhou fen");
    comp2->add(new hrdepartment(" hang zhou hr"));
    comp2->add(new financedepartment(" hang zhou finance"));
    comp->add(comp2);

    root->display(1);

    root->lineofduty();



    return 0;
}
