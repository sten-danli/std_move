#include<iostream>
using namespace std;


class B
{

public:
	//默认构造函数
	B() :m_bm(598) 
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
	//拷贝构造函数
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

	//移动拷贝构造函数
	A (A &&temp):m_pb(temp.m_pb)
	{
		temp.m_pb = nullptr;
		cout << "类A的移动拷贝构造函数执行" << endl;
	}

	//拷贝赋值运算函数
	A& operator =(const A& temp)
	{
		if (this == &temp)
		{
			return *this;

			delete this->m_pb;
			m_pb = new B(*temp.m_pb);//重新分配了一块内存
			cout << "类A的赋值运算执行" << endl;
			return *this;
		}
	}
	//移动赋值运算函数
	A& operator =(A&& temp)
	{
		if (this == &temp)
			return *this;
			
		delete temp.m_pb;//把自己的内存先干掉
		m_pb = temp.m_pb;//对方的内存直接拿过来，直接指过来
		cout << "类A的移动赋值运算执行" << endl;
		return *this;
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

	A a1;
	a1 = std::move(a);//调用移动赋值运算函数的方法
	


}