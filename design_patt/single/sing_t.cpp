
#include<iostream>
using namespace std;
class data{
    public:
        data() {}
        ~data() {}
        data& operator=(const data& rhs)=delete;
        void fun(float a) = delete;
};

int main()
{
    data data1;
    //data1.fun(0.5);
    data& data2=data1;
    return 0;
}
