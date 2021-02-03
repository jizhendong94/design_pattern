#include<iostream>
#include<string>
#include<list>

using namespace std;

class component{
    protected:
        string name;
    public:
        component(string str):name(str) {};
        virtual void add(component* c) = 0;
        virtual void remove(component* c) = 0;
        virtual void display(int depth) = 0;
};

class leaf:public component{
    public:
        leaf(string str):component(str) {}
        void add(component* c) {cout<<"can not add to leaf"<<endl;}
        void remove(component* c) {cout<<"can not remove from leaf "<<endl;}
        void display(int depth)
        {
            while(depth--)
            {
                cout<<"-";
            }
            cout<<name<<endl;
        }
};

class composite:public component{
    private:
        list<component*>child;
    public:
        composite(string name):component(name) {}
        void add(component* c) {child.push_back(c);}
        void remove(component* c) {child.remove(c);}
        void display(int depth)
        {
            int new_dp = depth;
            while(depth--)
                cout<<"-";
            cout<<name<<endl;
            for(auto it = child.begin();it!=child.end();it++)
            {
                (*it)->display(new_dp+2);
            }
        }
};




int main()
{
    composite* root = new composite("root");
    root->add(new leaf(string("leaf A")));
    root->add(new leaf(string("leaf B")));
    
    composite* comp = new composite("composite X");
    comp->add(new leaf("leaf XA"));
    comp->add(new leaf("leaf XB"));

    root->add(comp);

    composite* comp2 = new composite("composite XY");
    comp2->add(new leaf("lead XYA"));
    comp2->add(new leaf("lead XYB"));
    comp->add(comp2);

    root->add(new leaf("leaf C"));
    root->display(1);
    return 0;
}






