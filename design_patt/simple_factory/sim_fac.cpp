#include<iostream>
#include<string>
using namespace std;

typedef enum{
    ADD,
    SUB,
    MUL,
    DIV,

}oper_type;

class Operation {
    private:
        double numberA;
        double numberB;
    public:
        Operation() = default;
        Operation(double a,double b):numberA(a),numberB(b){}
        void set_numbera(double x)
        {
            numberA=x;
        }
        double get_numbera(void)
        {
            return numberA;
        }
        void set_numberb(double x)
        {
            numberB=x;
        }
        double get_numberb(void)
        {
            return numberB;
        }
     virtual double get_res()
     {
         double res = 0;
         return res;
     }

};

class Operationadd:public Operation
{
    double get_res()
    {
        double res = 0;
        res = Operation::get_numbera() + Operation::get_numberb();
        return res;
    }
};

class Operationsub:public Operation
{
    double get_res()
    {
        double res =0;
        res = Operation::get_numbera() - Operation::get_numberb();
        return res;
    }
};

class Operationmul:public Operation
{
    double get_res()
    {
        double res = 0;
        res = Operation::get_numbera()*Operation::get_numberb();
        return res;
    }
};
class Operationdiv:public Operation
{
    double get_res()
    {
        double res = 0;
        res = Operation::get_numbera()/Operation::get_numberb();
        return res;
    }
};
class Oper_fac
{
public:
    Operation* creatopr(oper_type opr)
    {
        Operation oper;
        switch(opr)
        {
            case ADD:
                {
                return (new Operationadd());
                
                break;
                }
            case SUB:
                {
                return (new Operationsub());
                break;
                }
            case MUL:
                {
                    return (new Operationmul());
                    break;
                }
           case DIV:
                {
                    return (new Operationdiv());
                    break;
                }
            default:
                return NULL;
                cout<<"ERROR"<<endl;

        }
    }

};
int main()
{
    Oper_fac op_fact;
    Operation* Oper= op_fact.creatopr(MUL);
    Oper->set_numbera(4);
    Oper->set_numberb(5);
    cout<<Oper->get_res()<<endl;
    delete Oper;
    return 0;
}
