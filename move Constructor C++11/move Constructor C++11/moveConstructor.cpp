#include<iostream>
using namespace std;


class B
{

public:
	//Ĭ�Ϲ��캯��
	B() :m_bm(0) 
	{
		cout << "B���Ĭ�Ϲ��캯��ִ��" << endl;
	}

	//�������캯��
	B(const B &temp):m_bm(temp.m_bm)
	{
		//this->m_bm = temp.m_bm;
		cout << "B��Ŀ������캯��ִ��" << endl;
	}
	int m_bm;

	virtual ~B()
	{
		cout << "��B����������ִ��" << endl;
	}
};

class A
{
	
public:
	//Ĭ�Ϲ��캯��
	A():m_pb(new B())
	{
	
	}

	A(const A & temp):m_pb(new B (*(temp.m_pb)))
	{
		this->m_pb = new B(*(temp.m_pb));
		cout << "��A�Ŀ������캯��ִ��" << endl;
	}
	virtual ~A()
	{
		delete m_pb;
		cout << "��A����������ִ��" << endl;
	}
private:

	B* m_pb;
};

static A getA() //static д�ں���ǰ�����˼�����������ֻ���ڵ�ǰmoveConstructor.cpp��ʹ�á�
{
	A a;
	return a;
}


int main()
{
	A a = getA();


	//B *pb = new B(); //new�������B�Ĺ��캯��
	//pb->m_bm = 19;
	//B* pb2 = new B(*pb);//���ָ�������new���������B�Ŀ������캯��

	//delete pb;
	//delete pb2;
}