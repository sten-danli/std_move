#include<iostream>
using namespace std;


class B
{

public:
	//Ĭ�Ϲ��캯��
	B() :m_bm(598) 
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
	//�������캯��
	A(const A & temp):m_pb(new B (*(temp.m_pb)))
	{
		//this->m_pb = new B(*(temp.m_pb));
		cout << "��A�Ŀ������캯��ִ��" << endl;
	}
	virtual ~A()
	{
		delete m_pb;
		cout << "��A����������ִ��" << endl;
	}

	//�ƶ��������캯��
	A (A &&temp)noexcept:m_pb(temp.m_pb)
	{
		temp.m_pb = nullptr;
		cout << "��A���ƶ��������캯��ִ��" << endl;
	}

	//������ֵ���㺯��
	A& operator =(const A& temp) noexcept
	{
		if (this == &temp)
		{
			return *this;

			delete this->m_pb;//�Ȱ��Լ����ڴ�ɵ�
			m_pb = new B(*temp.m_pb);//���·���һ���ڴ�
			cout << "��A�ĸ�ֵ����ִ��" << endl;
			return *this;
		}
	}
	//�ƶ���ֵ���㺯��
	A& operator =(A &&temp)
	{
		if (this == &temp)
			return *this;
			
		delete m_pb;//���Լ����ڴ��ȸɵ�
		m_pb = temp.m_pb;//�Է����ڴ�ֱ���ù�����m_pb���棬ֱ��ָ����
		temp.m_pb = nullptr;//Ȼ��ѶԷ����ڴ�ȥ������Ϊ���Ѿ��ѶԷ��ڴ��ù����ˡ�
		cout << "��A���ƶ���ֵ����ִ��" << endl;
		return *this;
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
	A a = getA();//1�����캯����1���ƶ����캯����1����������

	A a1;//1�����캯��
	a1 = std::move(a);//�����ƶ���ֵ���㺯���ķ���������ֵת������ֵ��
	


}