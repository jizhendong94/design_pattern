#include<iostream>
#include<string>

using namespace std;

class gamememento{
    private:
        int lif;
        int atk;
        int def;
    public:
        gamememento(int val1,int val2,int val3):lif(val1),atk(val2),def(val3) {}
        int get_lif() {return lif;}
        int get_atk() {return atk;}
        int get_def() {return def;}

};

class gamerole{
    private:
        int lif;
        int atk;
        int def;
    public:
        void set_lif(int val) {lif = val;}
        int get_lif() {return lif;}
        void set_atk(int val) {atk = val;}
        int get_atk() {return atk;}
        void set_def(int val) {def = val;}
        int get_def() {return def;}
        void show()
        {
            cout<<"lif is "<<lif<<endl;
            cout<<"atk is "<<atk<<endl;
            cout<<"def is "<<def<<endl;
        }
        void get_init()
        {
            lif = 100;
            atk = 100;
            def = 100;
        }
        void fight()
        {
            lif = 0;
            atk = 0;
            def = 0;
        }
        gamememento* save_stat() {return new gamememento(lif,atk,def);}
        void recovery_stat(gamememento* mem)
        {
            lif = mem->get_lif();
            atk = mem->get_atk();
            def = mem->get_def();
        }
};


class gamecaretaker{
    private:
        gamememento* gamemem;
    public:
        void set_mem(gamememento* _mem) {gamemem = _mem;}
        gamememento* get_mem(void) {return gamemem;}
};

int main()
{
    gamerole* lixiaoyao = new gamerole();
    lixiaoyao->get_init();
    lixiaoyao->show();

    gamecaretaker* statadmin = new gamecaretaker();
    statadmin->set_mem(lixiaoyao->save_stat());

    lixiaoyao->fight();
    lixiaoyao->show();


    lixiaoyao->recovery_stat(statadmin->get_mem());
    lixiaoyao->show();
    return 0;
}





