#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Context{
    public:
        Context(string str):text(str) {}
        void set_text(string str) {text = str;}
        string get_text(void) {return text;}
private:
    string text;
};
//abstraction 
class Expression{
    public:
        void interpret(Context* my_text)
        {
            if(my_text->get_text().length() == 0)
            {
                cout<<"len is 0"<<endl;
                return;
            }
            else
            {
                string playkey = my_text->get_text().substr(0,1);
                string strtmp = my_text->get_text().substr(2);
                my_text->set_text(strtmp);

                size_t npos = my_text->get_text().find(" ");
                string s_playval = my_text->get_text().substr(0,npos);
                int playval = atof(s_playval.c_str());
                my_text->set_text(my_text->get_text().substr(npos+1));
                excute(playkey,playval);
            }

        }
        virtual void excute(string key,double val) = 0;
};

class Note:public Expression{
    public:
        void excute(string key,double val)
        {
            char c_key[2];
            strncpy(c_key,key.c_str(),key.length());
            string s_node;
            switch(c_key[0])
            {
                case 'C':
                    s_node = "1";
                    break;
                case 'D':
                    s_node = "2";
                    break;
                case 'E':
                    s_node = "3";
                    break;
                default:
                    s_node = "error";
                    break;
            }
            cout<<s_node<<" "<<endl;
        }
};

class Scale:public Expression{
    public:
        void excute(string key,double val)
        {
            string scale;
            switch(int(val))
            {
                case 1:
                    scale = "low";
                    break;
                case 2:
                    scale = "middle";
                    break;
                case 3:
                    scale = "high";
                    break;
            }
            cout<<scale<<" "<<endl;
        }
};
int main()
{
    Context* context = new Context("O 2 E 0.5 G 0.5 A 3 E 0.5 G 0.5 D 3 E 0.5 G 0.5 A 0.5 O 3 C 1 O 2 A 0.5 G 1 C 0.5 E 0.5 D 3");
    Expression* expression = NULL;
    while(context->get_text().length()>0)
    {
        string str = context->get_text().substr(0,1);
        char c_str[2];
        strncpy(c_str,str.c_str(),str.length());
        switch(c_str[0])
        {
            case 'O':
                expression = new Scale();
                break;
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'A':
            case 'B':
            case 'P':
                expression = new Note();
                break;
        }
        expression->interpret(context);
    }
    return 0;
}






