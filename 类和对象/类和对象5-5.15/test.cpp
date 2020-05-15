#include <iostream>
using namespace std;

//定义全局变量
int cnt = 0;
class A
{
public:
	/* explicit: 禁止单参构造函数的隐式类型转换 */
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
	//非静态成员函数可以调用、访问静态成员
	void fun1()
	{
		cout << this->_a << endl;
		cout << _cnt << endl;
		fun2();
		displayA();
	}

	//静态成员函数:  没有this指针, 只能调用/访问静态成员，不能访问非静态成员
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
	static int _cnt; // 静态成员, 类成员，所有对象共享， 存放在数据段， 并不是存放在对象中
};

int A::_cnt = 0;  //静态成员在类外初始化

void fun1()
{
	int a = 1;
	float b = 2.0;
	a = b;  //隐式类型转换

	A a1(10);  

	A a2 = 20;  //隐式类型转换: 20传参，调用构造函数，创建一个匿名对象， 拷贝构造, 编译器优化，直接调用构造函数

	a2 = 30;  // 构造， 赋值运算符

	//A a3 = 20, 30;  //自定义类型的隐式类型转换： 只支持单参构造函数
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
	//静态成员访问形式： 1： 对象访问  2 类名 + 作用域限定符
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

	//<<运算符重载函数为Date类的友元， 访问Date类的私有成员
	friend ostream& operator<<(ostream& _cout, Date& d);
	Date();

	Date(int y, int m, int d);
	//输出运算符重载函数
	/*void operator<<(ostream& _cout)
	{
	_cout << _year << "-" << _month << "-" << _day << endl;
	}*/
	void Date::display();
	void displayB(const B& b);

	void displayB2(const B& b);
private:
	//友元的声明不受访问限定符的限制，可以在类的任意位置声明
	friend istream& operator>>(istream& _cin, Date& d);

	int _year = 2020;
	int _month = 5;
	int _day = 15;
};

class B
{
public:
	//友元类的所有成员函数变成当前类的友元函数
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
	int _b = 0; //C++11 初始化方式： 声明成员变量时，定义一个默认值/缺省值
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
//输出运算符重载函数
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
	cout << "简写" << endl;
	cout << d2 << d3 << d;
	cout << "输入" << endl;
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
	//D是内部类, D是C的友元类
	class D
	{
	public:
		void displayC(const C& c)
		{
			cout << c._c << endl;
			cout << c._sc << endl;
			cout << C::_sc << endl;
			//内部类可以直接访问外部类的static成员
			cout << _sc << endl;
		}
	private:
		int _d = 20;
	};
private:
	//E是内部类
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
	//test1();  //创建多少对象
	//cnt += 100;
	//cout << cnt << endl;
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	return 0;
}

