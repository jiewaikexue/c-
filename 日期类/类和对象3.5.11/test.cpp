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
	// ��������غ���Ϊ��Ա�����ǣ���Ҫ��ʾ����Ĳ��������Ȳ�����Ҫ��ĸ�����һ����
	// ���������Զ�����һ�������� this, ��ռ�ݲ����б�ĵ�һ��λ��
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
int operator+(int a, int b)   // a + b �����޸Ļ������͵������߼�
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

	//�������ͣ�
	// ֵ�� ���η��������� �Ҳ����Ż��Ը�ֵ���߼�
	// ���ã������������� �����Ż��Ը�ֵ���߼�
	// ����ֵ���ͣ� 
	//     void: ���ܽ���������ֵ
	//     ����/ֵ�� ���Խ���������ֵ�� ��������ã�Ч�ʸ���
	//   return *this;
	Date& operator=(const Date& d)
	{
		//����Ƿ���Լ���ֵ
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
	Date d2 = d1; // Date d2(d1) //�������죺��һ���Ѿ����ڵĶ��󴴽�һ����ȫһ�����¶���
	d1 = d2;  //��ֵ��������غ�������һ���Ѿ����ڵĶ�������ݸ�ֵ����һ������
	Date d3(2020, 1, 1);
	d3 = d2;  //��ֵ��������غ���
	d3 = d3;
	int a = 1, b = 2, c = 3;
	//������ֵ
	a = b = c = 10;
	//������ֵ�Ǵ�������ֵ
	d1.operator=(d2.operator=(d3));
	d1 = d2 = d3;  // d1.operator=(d2.operator=(d3));

}

void test3()
{
	seqList sl;
	seqList s2;
	//������Ĭ�����ɵĸ�ֵ�����Ҳ��һ��ǳ����
	s2 = sl;  //��ֵ�����

}

//int main()
//{
//	//test();
//	//test2();
//	test3();
//	return 0;
//}