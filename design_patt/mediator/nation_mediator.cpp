#include<iostream>
#include<string>
using namespace std;

class country;
class uintnation{
    public:
        virtual void declare(string message,country* collegue) = 0;
};

class country{
protected:
    uintnation* uina;
    public:
    country(uintnation* _uina):uina(_uina) {}
};

class usa:public country{
    public:
        usa(uintnation* _uina):country(_uina) {}
        void declare(string message) {uina->declare(message,this);}
        void get_message(string message) {cout<<"USA get message:: "<<message<<endl;}
};

class iraq:public country{
    public:
        iraq(uintnation* _uina):country(_uina) {}
        void declare(string message) {uina->declare(message,this);}
        void get_message(string message) {cout<<"IRAQ get message:: "<<message<<endl;}
};

class uintedsecurity:public uintnation{
    private:
        usa* collegue_usa;
        iraq* collegue_iraq;
    public:
        void set_usa(usa* c) {collegue_usa = c;}
        void set_iraq(iraq* c_iraq) {collegue_iraq = c_iraq;}
        void declare(string message,country* ctr)
        {
            if(ctr == collegue_usa)
                collegue_iraq->get_message(message);
            else
                collegue_usa->get_message(message);
        }
};


int main()
{
    uintedsecurity* unsc = new uintedsecurity();
    usa* usa_c1 = new usa(unsc);
    iraq* iraq_c2 = new iraq(unsc);

    unsc->set_usa(usa_c1);
    unsc->set_iraq(iraq_c2);

    usa_c1->declare("do not he weapen  war is comming");

    iraq_c2->declare("wo no weapon  wo do not fri ");
    return 0;
}
















