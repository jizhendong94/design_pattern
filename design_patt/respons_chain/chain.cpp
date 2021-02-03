#include<iostream>
#include<vector>
using namespace std;

class handler{
    protected:
        handler* successor;
    public:
        void set_successor(handler* _sucess) {successor = _sucess;}
        virtual void handlerequest(int request) = 0;
};

class concretehandler1:public handler{
    public:
        void handlerequest(int request)
        {
            if(request >= 0 && request < 10)
            {
                cout<<"handler 1:: "<<request<<endl;
            }
            else if(successor != nullptr)
            {
                successor->handlerequest(request);
            }
        }
};

class concretehandler2:public handler{
    public:
        void handlerequest(int request)
        {
            if(request >= 10 && request < 20)
            {
                cout<<"handler 2:: "<<request<<endl;
            }
            else if(successor != nullptr)
            {
                successor->handlerequest(request);
            }
        }
};

class concretehandler3:public handler{
    public:
        void handlerequest(int request)
        {
            if(request >= 20 && request<30)
            {
                cout<<"handler 3:: "<<request<<endl;
            }
            else if(successor != nullptr)
            {
                successor->handlerequest(request);
            }
        }
};

int main()
{
    handler* h1 = new concretehandler1();
    handler* h2 = new concretehandler2();
    handler* h3 = new concretehandler3();
    h1->set_successor(h2);
    h2->set_successor(h3);
    
    vector<int>V = {2,5,14,22,18,3,27,20};

    for(auto it=V.begin();it!=V.end();it++)
    {
        h1->handlerequest(*(it));
    }

    return 0;
}
