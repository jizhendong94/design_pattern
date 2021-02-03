#include<iostream>
#include<string>
using namespace std;

class operation{
private:
    int number1,number2;
public:
    void set_number1(int val)
    {
        number1=val;
    }
    void set_number2(int val)
    {
        number2= val;
    }
    int get_number1()
    {
        return number1;
    }
    int get_number2()
    {
        return number2;
    }
    virtual int get_res() = 0;
};

class addop:public operation{
public:
    virtual int get_res()
    {
        return operation::get_number1()+operation::get_number2();
    }
};

class subop:public operation{
public:
    virtual int get_res()
    {
        return operation::get_number1() - operation::get_number2();
    }
};

class factory{
public:
    virtual operation* creatop() = 0;
};

class addfactory:public factory{
public:
    virtual operation* creatop()
    {
        return new addop();
    }
};
class subfactory:public factory{
public:
    virtual operation* creatop()
    {
        return new subop();
    }
};


int main()
{
    factory *fc = new subfactory();
    operation *op = fc->creatop();
    op->set_number1(4);
    op->set_number2(5);
    cout<<op->get_res()<<endl;
    fc = new addfactory();
    op = fc->creatop();
    op->set_number1(8);
    op->set_number2(9);
    cout<<op->get_res()<<endl;
    delete op;
    delete fc;
    return 0;
}

