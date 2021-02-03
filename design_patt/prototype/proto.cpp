#include<iostream>
#include<string>
using namespace std;

class prototype{
    virtual prototype* clone() = 0;
};

class workex:public prototype{
private:
public: 
    string workdate,company;
    workex() = default;
    workex(string _work,string _com):workdate(_work),company(_com) {}
    virtual prototype* clone()
    {
        workex *p = new workex();
        *p=*this;
        return p;
    }
};

class resume:public prototype{
private:
    string name,sex,age;
    workex *work;
public:
    resume() =default;
    resume(string _name)
    {
        name = _name;
        work = new workex();
    }
    resume(workex *_wk)
    {
        work=(workex *)_wk->clone();
    }
    void setpersoninfo(string _sex,string _age)
    {
        sex=_sex;
        age=_age;
    }
    void setexperence(string _timearea,string _company)
    {
        work->workdate=_timearea;
        work->company=_company;
    }
    void display()
    {
        cout<<"name::"<<name<<" sex::"<<sex<<" age::"<<age<<" timearea::"<<work->workdate<<" company::"<<work->company<<endl;
    }
    virtual prototype* clone()
    {
    //    resume *p = new resume();
    //    *p=*this;
    //    return p;
#if 1
        resume *p = new resume(this->work);
        p->name = this->name;
        p->sex = this->sex;
        p->age = this->age;
        return p;
#endif
    }
};

int main()
{
    resume *a = new resume("daniao");
    a->setpersoninfo(string("male"),string("29"));
    a->setexperence(string("1992-2000"),string("XXcompany"));

    a->display();

    resume *b = (resume *)(a->clone());
    b->setpersoninfo(string("nu"),string("19"));
    b->setexperence(string("1996-2003"),string("YYcompamy"));
    b->display();
    a->display();
}

