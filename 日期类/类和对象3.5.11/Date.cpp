#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		//�жϲ����Ƿ���Ч
		if (year <= 0
			|| month <= 0 || month > 12
			|| day > getMonthDay(year, month))
		{
			cout << "�Ƿ�����!" << endl;
			_year = _month = _day = 1;
			cout << "��������Ϊ��1-1-1" << endl;
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
		//�ж��Ƿ�Ϊ��ֵ
		if (day < 0)
			return *this -= -day;

		_day += day;
		//�ж������Ƿ񳬳���ǰ�·ݵ�����
		while(_day > getMonthDay(_year, _month))
		{
			//��λ�� ��ȥ��ǰ�µ����������·ݽ�λ
			_day -= getMonthDay(_year, _month);
			++_month;

			//�ж�����Ƿ���Ҫ��λ
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

		//�ж��Ƿ���Ҫ��λ
		while (_day <= 0)
		{
			//��λ
			--_month;
			//�ж��Ƿ���Ҫ������ݵ���λ
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
		//�������⴦��
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			++day;

		return day;
	}

	//ǰ���Լ�  ++date --> �����Լӣ��ٷ����Լ�֮���ֵ
	Date& operator++()
	{
		return *this += 1;
	}

	//�����Լ� date++ --> �����Լ�֮ǰ��ֵ���ٽ����Լ�����
	Date operator++(int);

	//ǰ���Լ�
	Date& operator--();

	//�����Լ�
	Date operator--(int);

	Date operator+(int day);

	Date operator-(int day);

	//�Ƚ�
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