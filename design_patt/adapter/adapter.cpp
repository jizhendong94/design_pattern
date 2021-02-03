#include<iostream>
#include<string>

using namespace std;

class player{
protected:
    string name;
public:
    player(string _name):name(_name) {}
    virtual void attack() = 0;
    virtual void defence() = 0;
};

class forwards:public player{
public:
    forwards(string _name):player(_name) {}
    void attack()
    {
        cout<<name<<"attack "<<endl;
    }
    void defence()
    {
        cout<<name<<" defence "<<endl;
    }
};

class foregincenter{
private:
    string name;
public:
    void set_name(string _name)
    {
        name = _name;
    }
    void jingong()
    {
        cout<<name<<"jin gong "<<endl;
    }
    void fangshou()
    {
        cout<<name<<" fang shou "<<endl;
    }
};
class adapter:public player{
    private:
        foregincenter* wjqy=new foregincenter();
    public:
        adapter(string name):player(name) 
        {
            wjqy->set_name(name);
        }
        void attack()
        {
            wjqy->jingong();
        }
        void defence()
        {
            wjqy->fangshou();
        }
};

int main()
{
    player* b = new forwards(string("badier"));
    b->attack();
    b->defence();

    player* yao = new adapter(string("yaoming"));
    yao->attack();
    yao->defence();


    return 0;
}
