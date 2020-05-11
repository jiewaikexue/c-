#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		//判断参数是否有效
		if (year <= 0
			|| month <= 0 || month > 12
			|| day > getMonthDay(year, month))
		{
			cout << "非法日期!" << endl;
			_year = _month = _day = 1;
			cout << "日期重置为：1-1-1" << endl;
		}
		else
		{
			_year = year;
			_month = month;
			_day = day;
		}
		
	}
	/*
	Date(const Date& date);

	Date& operator=(const Date& date);

	~Date();
	*/
	// 2020-5-1 + 10 ----> 2020-5-21
	// 5-101 --> - 31  --> 6-70 --> -30 --> 7-40 --> -31 --> 8-9
	// d.operator+=(day)   d += day
	Date& operator+=(int day)
	{
		//判断是否为负值
		if (day < 0)
			return *this -= -day;

		_day += day;
		//判断天数是否超出当前月份的天数
		while(_day > getMonthDay(_year, _month))
		{
			//进位： 减去当前月的天数，向月份进位
			_day -= getMonthDay(_year, _month);
			++_month;

			//判断年份是否需要进位
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}

		return *this;
	}
	//2020-5-1  - 100
	//2020-5-(-99) --> +30 --> 4-(-69) --> + 31 --> 3-(-38) --> + 29 --> 2-(-9) --> + 31 --> 1-22
	Date& operator-=(int day)
	{
		if (day < 0)
			return *this += -day;

		_day -= day;

		//判断是否需要退位
		while (_day <= 0)
		{
			//退位
			--_month;
			//判断是否需要进行年份的退位
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}

			_day += getMonthDay(_year, _month);
		}
		return *this;
	}

	int getMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		//二月特殊处理
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			++day;

		return day;
	}

	//前置自加  ++date --> 首先自加，再返回自加之后的值
	Date& operator++()
	{
		return *this += 1;
	}

	//后置自加 date++ --> 返回自加之前的值，再进行自加运算
	Date operator++(int);

	//前置自减
	Date& operator--();

	//后置自减
	Date operator--(int);

	Date operator+(int day);

	Date operator-(int day);

	//比较
	bool operator>(const Date& date);

	bool operator<(const Date& date);

	bool operator==(const Date& date)
	{
		return _year == date._year
			&& _month == date._month
			&& _day == date._day;
	}

	bool operator>=(const Date& date);

	bool operator<=(const Date& date);

	bool operator!=(const Date& date);

	int operator-(Date& date);

	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void test1()
{
	Date d1(2020, 5, 1);
	d1.print();
	Date d2(2020, 5, 32);
	d2.print();
	Date d3(2020, 13, 2);
	d3.print();
	d1 += -100;
	d1.print();
	d1 += 100;
	d1.print();
	d1 += 150;
	d1.print();
	d1 += 3650;
	d1.print();
	d1 += -365;
	d1.print();
	d1 -= 3650;
	d1.print();

	++d1;
	d1.print();
	++d1;
	d1.print();
	++d1;
	d1.print();
	++d1;
	d1.print();
	++d1;
	d1.print();
	for (int i = 0; i < 100; ++i)
	{
		++d1;
		d1.print();
	}

	cout << (d1 == d2) << endl;

}

int main()
{
	test1();
	return 0;
}