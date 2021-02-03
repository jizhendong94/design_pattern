#include<iostream>
#include<memory>
#include<mutex>
using namespace std;
class singleton{
    public:
        typedef shared_ptr<singleton> Ptr;
        ~singleton() {cout<<"destructor"<<endl;}
        static Ptr get_instance()
        {
            if(m_instance_ptr == nullptr)
            {
                lock_guard<mutex> lk(m_mutex);
                if(m_instance_ptr == nullptr)
                {
                    m_instance_ptr = shared_ptr<singleton>(new singleton());
                }
            }
            return m_instance_ptr;
        }
    private:
        singleton() {cout<<"create single"<<endl;}
        static Ptr m_instance_ptr;
        static mutex m_mutex;
};

singleton::Ptr singleton::m_instance_ptr = nullptr;
mutex singleton::m_mutex;

int main()
{
    singleton::Ptr instance = singleton::get_instance();
    singleton::Ptr instance2 = singleton::get_instance();
    return 0;
}
