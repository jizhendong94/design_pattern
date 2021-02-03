#include<iostream>
#include<list>

using namespace std;

typedef struct{
    string type;
    int num;
}Requst;
class manager{
    protected:
        string name;
        manager* superior;
    public:
        manager(string str):name(str) {}
        ~manager() {}
        void set_superior(manager* man) {superior= man;}
        virtual void requstapplication(Requst request) = 0;

};

class commonmanager:public manager{
    public:
        commonmanager(string str):manager(str) {}
        void requstapplication(Requst requst)
        {
            if(requst.type == "qingjia" && requst.num <=2)
            {
                cout<<"common manager: "<<name<<" num: "<<requst.num<<"ok"<<endl;
            }
            else
            {
                if(nullptr != superior)
                    superior->requstapplication(requst);
            }
        }
};

class majordomo:public manager{
    public:
        majordomo(string str):manager(str) {}
        void requstapplication(Requst requst)
        {
            if(requst.type=="qingjia"&&requst.num <=5)
            {
                cout<<"mojor domo: "<<name<<" num: "<<requst.num<<"ok"<<endl;
            }
            else
            {
                if(nullptr != superior)
                    superior->requstapplication(requst);
            }
        }
};

class generalmanager:public manager{
    public:
        generalmanager(string str):manager(str) {}
        void requstapplication(Requst requst)
        {
            if(requst.type == "qingjia")
            {
                cout<<"general manager: "<<name<<" num: "<<requst.num<<"ok"<<endl;
            }
            else if(requst.type == "jiaxin"&&requst.num<=500)
            {
                cout<<"general manager: "<<name<<"jiaxin: "<<requst.num<<"ok"<<endl;
            }
            else
            {
                cout<<"general manager: "<<name<<"not follow"<<"num: "<<requst.num<<endl;
            }
        }
};

int main()
{
    commonmanager *jinli = new commonmanager("jinli");
    majordomo* zongjian = new majordomo("zongjian");
    generalmanager* zongjingli = new generalmanager("zongjingli");
    jinli->set_superior(zongjian);
    zongjian->set_superior(zongjingli);

    Requst requst = {"qingjia",2};
    jinli->requstapplication(requst);
    requst = {"qingjia",5};
    jinli->requstapplication(requst);
    requst = {"jiaxin",200};
    jinli->requstapplication(requst);
    requst = {"jiaxin",700};
    jinli->requstapplication(requst);
    return 0;






}
