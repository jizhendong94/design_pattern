#include<iostream>
using namespace std;

class singleton{
    private:
        singleton()
        {
            cout<<"create single "<<endl;
        }
        static singleton* m_single;
    public:
        static singleton* getinstance()
        {
            if(nullptr == m_single)
            {
                m_single = new singleton();
            }
            return m_single;
        }
        ~singleton() {cout<<"destructor called!"<<endl;}
};

singleton* singleton::m_single = nullptr;

int main()
{
    singleton* p1 = singleton::getinstance();
    singleton* p2 = singleton::getinstance();

    if(p1 == p2)
        cout<<"the same "<<endl;
    else
        cout<<"different "<<endl;
}



