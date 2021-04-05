#include<iostream>
using namespace std;

//懒汉式单例模式  缺点：以时间换空间  多线程下不够安全
class Single{
private:
	Single() {}
	static Single* singleinstance;
public:
	static Single* get_instance(void)
	{
		if(singleinstance == NULL)
			singleinstance =  new Single();
		return singleinstance;
	}
	//在析构函数中析构对象是一种错误的做法,会调用,是一个死递归,正确做法是创建一个嵌套的析构类
	/*~CSingleton()
	{
		if( m_pInstance != NULL)
		{
			delete  m_pInstance;
			 m_pInstance = NULL;
		}

		cout << "~CSingleton()" << endl;
	}
    */
};
Single* Single::singleinstance=NULL;

//
//懒汉式线程安全双检锁  
class Single1{
public:
	static Single1* get_instance()
	{
		if(singleinstance==NULL)
		{
			pthread_mutex_lock(&mutex);
			if(singleinstance == NULL)
			{
				singleinstance =  new Single1();
			}
			pthread_mutex_unlock(&mutex);
		}
		return singleinstance;
	}
private:
	Single1()
	{
		pthread_mutex_init(&mutex,NULL);
	}
	static Single1* singleinstance;
	static pthread_mutex_t mutex;
};

Single1* Single1::singleinstance=NULL;
pthread_mutex_t Single1::mutex;

//////
//饿汉式 以空间换时间 静态实例初始化在程序进入主函数前就由主线程以单线程的方式
//完成了初始化，不必担心多线程的问题
class Single2{
public:
	static Single2* get_instance() {return singleinstance;}
private:
	Single2() {}
	static Single2* singleinstance;
};
Single2* Single2::singleinstance = new Single2();


//meyers singlton 
class Csingle{
private:
	Csingle() {}
public:
	static Csingle& get_instace()
	{
		static Csingle singleinstance;
		return singleinstance;
	}
};






void test01()
{
	Single2* s2_ins=Single2::get_instance();
	cout<<"single :"<<s2_ins<<endl;
}


//
class Dsingle{
private:
	Dsingle() {}
	static Dsingle* singleinstance;
	class Garbage{ //唯一作用就是在析构函数中删除single的实例
		public:
			~Garbage()
			{
				if(Dsingle::singleinstance)
				{
					delete Dsingle::singleinstance;
					Dsingle::singleinstance=NULL;
				}
			}
	};
	static Garbage garbage;//定义一个静态成员，在程序结束时，系统会调用它的析构函数  
public:
	static Dsingle* get_instance()
	{
		if(singleinstance == NULL)
			return new Dsingle();
		return singleinstance;
	}
};
Dsingle* Dsingle::singleinstance = NULL;
Dsingle::Garbage Dsingle::garbage;



int main()
{
	test01();
	return 0;
}









