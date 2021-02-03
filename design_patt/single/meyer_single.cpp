#include<iostream>
using namespace std;

class singleton{
    private:
        singleton() {cout<<"create"<<endl;}
    public:
        static singleton& get_instance()
        {
            static singleton instance;
            return instance;
        }
        ~singleton()
        {
            cout<<"destruct "<<endl;
        }
        singleton& operator=(const singleton&) = delete;
};

int main()
{
    singleton& intance1 = singleton::get_instance();
    singleton& instace2 = singleton::get_instance();

    return 0;
}
