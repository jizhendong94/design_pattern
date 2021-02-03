#include<iostream>
using namespace std;

class cashsuper{
public:
    virtual double acceptcash(double money) = 0;
};

class cashnormal:public cashsuper{
    public:
        double acceptcash(double money)
        {
            return money;
        }
};

class cashrebate:public cashsuper{
private:
    double rebate = 1;
public:
    cashrebate(double rbt):rebate(rbt) {}

    double acceptcash(double money)
    {
        return rebate*money;
    }
};

class cashreturn:public cashsuper{
private:
    double mncondition =0;
    double mnreturn = 0;
public:
    cashreturn(double condition,double ret):mncondition(condition),mnreturn(ret) {}
    double acceptcash(double money)
    {
        double res = money;
        if(money >= mncondition)
        {
            res = money-(money/mncondition)*mnreturn;
        }
        return res;
    }

};

class cashcontext{
private:
    cashsuper *cs;
public:
    cashcontext(cashsuper *cashsu):cs(cashsu) {}
    double get_res(double m)
    {
        return cs->acceptcash(m);
    }
};
int main()
{
    cashnormal *cn = new cashnormal;
    cashrebate *cr = new cashrebate(0.5);
    cashreturn *cc = new cashreturn(200,50);
    cashcontext* context = new cashcontext(cn);
    cout<< "normal "<<context->get_res(200)<<endl;
    context = new cashcontext(cr);
    cout<<"rebate "<<context->get_res(600)<<endl;
    context = new cashcontext(cc);
    cout<<"return"<<context->get_res(200)<<endl;
    return 0;
}
