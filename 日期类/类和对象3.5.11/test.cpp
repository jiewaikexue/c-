#include <iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
	{
		_a = a;
		_b = 0;
	}
	// 运算符重载函数为成员函数是，需要显示定义的参数个数比操作符要求的个数少一个，
	// 编译器会自动加入一个参数： this, 其占据参数列表的第一个位置
	A operator+(A& a1) // A operator(A* this, A& a1)
	{
		//return A(a1._a + a1._b + a2._a + a2._b);
		int a = this->_a + this->_b + a1._a + a1._b;
		A aobj(a);
		return aobj;
	}

	int _a;
	int _b;
};

/*
A operator+(A& a1, A& a2) // a1  +   a2
{
	//return A(a1._a + a1._b + a2._a + a2._b);
	int a = a1._a + a1._b + a2._a + a2._b;
	A aobj(a);
	return aobj;
}
*/
/*
int operator+(int a, int b)   // a + b 不能修改基本类型的运算逻辑
{
	return a - b;
}
*/
A add(A& a1, A& a2);

void test()
{
	A a1;
	A a2;
	A a3;
	a1._a = 1;
	a1._b = 2;

	a2._a = 3;
	a2._b = 4;
	a3 = a1.operator+(a2);
	a3 = a1 + a2;  // ---> a1.operator+(a2);
}


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int, int)" << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date&)" << endl;
	}

	//参数类型：
	// 值： 传参发生拷贝， 且不能优化自赋值的逻辑
	// 引用：不发生拷贝， 可以优化自赋值的逻辑
	// 返回值类型： 
	//     void: 不能进行连续赋值
	//     引用/值： 可以进行连续赋值， 如果是引用，效率更高
	//   return *this;
	Date& operator=(const Date& d)
	{
		//检查是否给自己赋值
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
			cout << "operator=" << endl;
		}

		return *this;
		
	}
private:
	int _year;
	int _month;
	int _day;
};

class seqList
{
public:
	seqList(int n = 10)
	{
		_array = (int*)malloc(sizeof(int)* n);
	}
	~seqList()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
		}
	}
private:
	int* _array;
};

void test2()
{
	Date d1(2020, 5, 11);
	Date d2 = d1; // Date d2(d1) //拷贝构造：用一个已经存在的对象创建一个完全一样的新对象
	d1 = d2;  //赋值运算符重载函数：把一个已经存在的对象的内容赋值给另一个对象
	Date d3(2020, 1, 1);
	d3 = d2;  //赋值运算符重载函数
	d3 = d3;
	int a = 1, b = 2, c = 3;
	//连续赋值
	a = b = c = 10;
	//连续赋值是从右向左赋值
	d1.operator=(d2.operator=(d3));
	d1 = d2 = d3;  // d1.operator=(d2.operator=(d3));

}

void test3()
{
	seqList sl;
	seqList s2;
	//编译器默认生成的赋值运算符也是一个浅拷贝
	s2 = sl;  //赋值运算符

}

//int main()
//{
//	//test();
//	//test2();
//	test3();
//	return 0;
//}