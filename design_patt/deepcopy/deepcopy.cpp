#include<iostream>
#include<cstring>

using namespace std;

class String{
private:
    char *str;
public:
    String(const char *s="")
    {
        if(NULL == s)
        {
            str=new char[1];
            *str='\0';
        }
        else
        {
            str  = new char[strlen(s)+1];
            strcpy(str,s);
        }
    }
    String(const String& s):str(new char[strlen(s.str)+1])
    {
        strcpy(str,s.str);
    }
    String& operator=(const String& s)
    {
        if(this != &s)
        {
            char *temp = new char[strlen(s.str)+1];
            strcpy(temp,s.str);
            delete[] str;
            str=NULL;
            str=temp;
        }
        return *this;
    }
    ~String()
    {
        if(NULL != str)
        {
            delete[] str;
            str=NULL;
        }
    }
};

int main()
{
    String str1 = String("hello");
    cout<<str1<<endl;
    String str2(str1);
    cout<<str2<<endl;
    
}

