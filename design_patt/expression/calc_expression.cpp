#include<iostream>
#include<map>
using namespace std;
class Context{
    private:
        map<string,int>valmap;
    public:
        void add_val(string key,int val) {valmap.insert(make_pair(key,val));}
        int get_val(string key) {return valmap[key];}
};

class Abstractexpression{
    public:
        virtual int interpreter(Context* context) = 0;
};

class Addnoterminalexpression:public Abstractexpression{
    private:
        Abstractexpression* left;
        Abstractexpression* right;
    public:
        Addnoterminalexpression(Abstractexpression* _left,Abstractexpression* _right):left(_left),right(_right) {}
        int interpreter(Context* context)
        {
            return (this->left->interpreter(context) + this->right->interpreter(context));
        }
};

class Subnoterminalexpression:public Abstractexpression{
    private:
        Abstractexpression* left;
        Abstractexpression* right;
    public:
        Subnoterminalexpression(Abstractexpression* _left,Abstractexpression* _right):left(_left),right(_right) {}
        int interpreter(Context* context)
        {
            return (this->left->interpreter(context) - this->right->interpreter(context));
        }
};

class Terminalexpression:public Abstractexpression{
    private:
        int i;
    public:
        Terminalexpression(int _i):i(_i) {}
        int interpreter(Context* context) {return i;}
};

int main()
{
    Context* context = new Context();
    context->add_val("a",7);
    context->add_val("b",8);
    context->add_val("c",2);

    Subnoterminalexpression* subval = new Subnoterminalexpression(new Terminalexpression(context->get_val("a")),
                                                                    new Terminalexpression(context->get_val("b")));

    cout<<"sub:: "<<subval->interpreter(context)<<endl;

    Addnoterminalexpression* addval = new Addnoterminalexpression(subval,new Terminalexpression(context->get_val("c")));
    cout<<"add:: "<<addval->interpreter(context)<<endl;
    return 0;
}





