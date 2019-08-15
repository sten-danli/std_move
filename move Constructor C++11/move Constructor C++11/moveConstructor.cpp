#include<iostream>
using namespace std;


class B
{

public:
	//默认构造函数
	B() :m_bm(0) 
	{
		cout << "B类的默认构造函数执行" << endl;
	}

	//拷贝构造函数
	B(const B &temp):m_bm(temp.m_bm)
	{
		//this->m_bm = temp.m_bm;
		cout << "B类的拷贝构造函数执行" << endl;
	}
	int m_bm;

	virtual ~B()
	{
		cout << "类B的析构函数执行" << endl;
	}
};

class A
{
	
public:
	//默认构造函数
	A():m_pb(new B())
	{
	
	}

	A(const A & temp):m_pb(new B (*(temp.m_pb)))
	{
		this->m_pb = new B(*(temp.m_pb));
		cout << "类A的拷贝构造函数执行" << endl;
	}
	virtual ~A()
	{
		delete m_pb;
		cout << "类A的析构函数执行" << endl;
	}
private:

	B* m_pb;
};

static A getA() //static 写在函数前面的意思就是这个函数只能在当前moveConstructor.cpp中使用。
{
	A a;
	return a;
}


int main()
{
	A a = getA();


	//B *pb = new B(); //new调用类的B的构造函数
	//pb->m_bm = 19;
	//B* pb2 = new B(*pb);//这种给参数的new方法会调用B的拷贝构造函数

	//delete pb;
	//delete pb2;
}