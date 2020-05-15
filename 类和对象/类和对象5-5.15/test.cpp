#include <iostream>
using namespace std;

//����ȫ�ֱ���
int cnt = 0;
class A
{
public:
	/* explicit: ��ֹ���ι��캯������ʽ����ת�� */
	/*explicit*/ A(int a)
		:_a(a)
	{
		++_cnt;
		cout << "A(Int)" << endl;
	}

	A(int a, int b)
		:_a(a)
	{
		++_cnt;
	}

	A(const A& a)
		:_a(a._a)
	{
		++_cnt;
		cout << "A(const A&)" << endl;
	}
	A& operator=(const A& a)
	{
		if (this != &a)
		{
			_a = a._a;
		}
		cout << "A& operator=" << endl;
		return *this;
	}
	//�Ǿ�̬��Ա�������Ե��á����ʾ�̬��Ա
	void fun1()
	{
		cout << this->_a << endl;
		cout << _cnt << endl;
		fun2();
		displayA();
	}

	//��̬��Ա����:  û��thisָ��, ֻ�ܵ���/���ʾ�̬��Ա�����ܷ��ʷǾ�̬��Ա
	static void displayA()
	{
		cout << "displayA" << endl;
		//cout << this->_a << endl;
		cout << _cnt << endl;
		fun2();
		//fun1();
	}

	static void fun2()
	{

	}

//private:
	int _a;
	static int _cnt; // ��̬��Ա, ���Ա�����ж����� ��������ݶΣ� �����Ǵ���ڶ�����
};

int A::_cnt = 0;  //��̬��Ա�������ʼ��

void fun1()
{
	int a = 1;
	float b = 2.0;
	a = b;  //��ʽ����ת��

	A a1(10);  

	A a2 = 20;  //��ʽ����ת��: 20���Σ����ù��캯��������һ���������� ��������, �������Ż���ֱ�ӵ��ù��캯��

	a2 = 30;  // ���죬 ��ֵ�����

	//A a3 = 20, 30;  //�Զ������͵���ʽ����ת���� ֻ֧�ֵ��ι��캯��
}

A fun(A a)
{
	A b = a;
	return b;
}

void test1()
{
	A a(20);
	fun(a);
	cout << a._cnt << endl;
}

void test2()
{
	A a1 = 1;
	A a2 = 2;
	A a3 = 3;
	A a4 = 4;
	//��̬��Ա������ʽ�� 1�� �������  2 ���� + �������޶���
	cout << &a1._cnt << endl;
	cout << &a2._cnt << endl;
	cout << &a3._cnt << endl;
	cout << &a4._cnt << endl;

	cout << &A::_cnt << endl;

	cout << sizeof(A) << endl;

	a1.displayA();
	A::displayA();
}

class B;

class Date
{
public:
	friend class B;

	//<<��������غ���ΪDate�����Ԫ�� ����Date���˽�г�Ա
	friend ostream& operator<<(ostream& _cout, Date& d);
	Date();

	Date(int y, int m, int d);
	//�����������غ���
	/*void operator<<(ostream& _cout)
	{
	_cout << _year << "-" << _month << "-" << _day << endl;
	}*/
	void Date::display();
	void displayB(const B& b);

	void displayB2(const B& b);
private:
	//��Ԫ���������ܷ����޶��������ƣ��������������λ������
	friend istream& operator>>(istream& _cin, Date& d);

	int _year = 2020;
	int _month = 5;
	int _day = 15;
};

class B
{
public:
	//��Ԫ������г�Ա������ɵ�ǰ�����Ԫ����
	friend class Date;
	B()
	{}
	B(int b)
		:_b(b)
	{}

	void display(const Date& d)
	{
		cout << d._year << d._month << d._day << endl;
	}
private:
	int _b = 0; //C++11 ��ʼ����ʽ�� ������Ա����ʱ������һ��Ĭ��ֵ/ȱʡֵ
};

Date::Date()
{}

Date::Date(int y, int m, int d)
:_year(y)
, _month(m)
, _day(d)
{}
void Date::display()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
//�����������غ���
/*void operator<<(ostream& _cout)
{
_cout << _year << "-" << _month << "-" << _day << endl;
}*/

void Date::displayB(const B& b)
{
	cout << b._b << endl;
}

void Date::displayB2(const B& b)
{
	cout << b._b << endl;
}


void test3()
{
	B b;
	B a = b;
	B c(20);
}





ostream& operator<<(ostream& _cout, Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}



//void fun3(Date& d)
//{
//	cout << d._year << "-" << d._month << "-" << d._day << endl;
//}

void test4()
{
	Date d;
	d.display();
	/*d.operator<<(cout);
	d << cout;*/

	//cout << d;
	Date d2(2020, 5, 13);
	Date d3(2020, 5, 14);
	operator<<(operator<<(operator<<(cout, d2), d3), d);
	cout << "��д" << endl;
	cout << d2 << d3 << d;
	cout << "����" << endl;
	cin >> d >> d2 >> d3;
	cout << d2 << d3 << d;
}

void test5()
{
	B b(100);
	Date d;
	d.displayB(b);
	b.display(d);
}

class C
{
public:
	//D���ڲ���, D��C����Ԫ��
	class D
	{
	public:
		void displayC(const C& c)
		{
			cout << c._c << endl;
			cout << c._sc << endl;
			cout << C::_sc << endl;
			//�ڲ������ֱ�ӷ����ⲿ���static��Ա
			cout << _sc << endl;
		}
	private:
		int _d = 20;
	};
private:
	//E���ڲ���
	class E
	{
		private:
		int _e = 30;
	};
	int _c = 10;
	static int _sc;

};

int C::_sc = 100;


void test6()
{
	C c;
	C::D d;
	//D d;
	//C::E e;
	cout << sizeof(C) << endl;
	cout << sizeof(C::D) << endl;
}

int main()
{
	//fun1();
	//test1();  //�������ٶ���
	//cnt += 100;
	//cout << cnt << endl;
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	return 0;
}

