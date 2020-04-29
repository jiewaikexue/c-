#include "a.h"
#include <time.h>
#include <iostream>
using namespace std;

void test()
{
	int a = 10;
	int b = -1;
	//ra���ã� �Ǳ���a�ı���
	int& ra = a;
	int& rra = a;
	ra = 20;
	rra = 30;
	//�����ڶ����ʱ������ʼ��
	int& ra3 = a;
	//�޸���a��ֵ
	//���ö������֮�󣬲�����ָ���µ�ʵ��
	ra3 = b;

	const  int  c = 20;
	//�����ã�  const������ ��������ʱ����
	const int& rc = c;
	//rc = 100;
	const int& r1 = 10;

	double d = 2.3;
	ra = d;
	double& rd = d;
	//int& rd2 = d;  ��֧�֣����Ͳ�һ��
	const int& rd2 = d;  //��ʽ����ת��  double  -->  int

	int* pa = &a;
	//const int& rpa = pa;  //���ܽ�����ʽ����ת��
}

void Swap3(int* array, int i, int j)   //Swap3(array, 2,3)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void  Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//����������
void Swap2(int& ra, int& rb)
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}

void test2()
{
	int a = 10;
	int b = 20;
	Swap(&a, &b);
	Swap2(a, b);
}

//����������ֵ
int& Add(int& ra)
{
	return ++ra;
}
//����������ֵ�� ���÷�����������С�ڵ��ú����������ڵı���
int& Add(int a, int b)
{
	int c = a + b;
	return c;
}

void test3()
{
	int a = 10;
	int& ra = Add(a);
	ra += 10;
}

void test4()
{
	int a = 1;
	int b = 2;
	int& ret = Add(a, b);
	Add(10, 20);
	cout << "test4()" << endl;
}

struct A
{
	int array[100000];
};

A globalA;

void funVal(A a)
{}

void funRef(A& ra)
{}

void test5()
{
	// ���������ñȴ�ֵЧ�ʸߣ� ������û�п�������
	size_t begin = clock();
	for (int i = 0; i < 100000; ++i)
		funVal(globalA);
	size_t end = clock();
	cout << "funVal: " << end - begin << endl;
	begin = clock();
	for (int i = 0; i < 100000; ++i)
		funRef(globalA);
	end = clock();
	cout << "funRef: " << end - begin << endl;

}

A funVal2()
{
	return globalA;
}

A& funRef2()
{
	return globalA;
}
void test6()
{
	// �������ñȷ���ֵЧ�ʸߣ� ��������û�п�������
	size_t begin = clock();
	for (int i = 0; i < 100000; ++i)
		funVal2();
	size_t end = clock();
	cout << "funVal2: " << end - begin << endl;
	begin = clock();
	for (int i = 0; i < 100000; ++i)
		funRef2();
	end = clock();
	cout << "funRef2: " << end - begin << endl;
}

void test7()
{
	int a = 10;
	int* pa = &a;
	*pa = 20;

	int b = 1;
	int& rb = b;
	rb = 2;
}

struct B
{
	int _a;
	int _b;
	int _c;
};

void test8()
{
	B b;
	B& rb = b;
	B* pb = &b;
	B copy = b;
	b._a = 10;
	rb._a = 20;   //�������ײ㷭���ָ��Ĳ�����rb->_a = 20;
	pb->_a = 40;

	copy._a = 30;
	//rb->_a = 10;

}

void test9()
{
	//ָ������õ�����
	// 1. �����ڶ���ʱ�����ʼ���� ָ����Բ��ó�ʼ��
	int a = 10;
	int& ra = a;
	int* pa;
	// 2. ֻ��һ�����ã�û�ж༶���ã� ָ������ж༶ָ��
	int& ra2 = a;
	int** pa2;
	int*** pa3;
	// 3. �����Լ���ʵ�������Լӣ� ��ָ���Լ��ǵ�ַ��ƫ��
	ra++;  // a�������Լ�1
	pa++;  //���ƫ��4���ֽڵĿռ�
	// 4. sizeof(����)��ʾʵ���С��sizeof(ָ��)��ʾָ��Ĵ�С
	B b;
	B& rb = b;
	B* pb = &b;
	sizeof(rb);  //��b�Ĵ�С
	sizeof(pb);  //��ָ��Ĵ�С
	// 5. û�п����ã������п�ָ��
	//int& ra3 = NULL;
	int* pc = NULL;
	// 6. ���ø��Ӱ�ȫ�� �����п��쳣
}

#define F(X, Y)  (X) / (Y)   //�꺯��  ----> Ԥ���� ���滻

void  test99()
{
	int ret = F(9, 3); //����ʱ���滻�� int ret = 9 / 3
	int a = 2;
	int b = 4;
	int c = 2;
	ret = F(a + b, c);  // ���滻�� ret = 2 + 4 / 2
}

inline int dev(int x, int y)
{
	return x / y;
}

inline int Fab(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	return Fab(n - 1) + Fab(n - 2);
}

void test10()
{
	int a = 9;
	int b = 3;
	int ret = a / b;
	ret = dev(a, b);  // ret =  a / b;   ��������ָ��ԭ��չ���� û�к���ջ֡����

	ret = Fab(40);
}

void test11()
{
	int a = 4;
	int b = 2;
	int ret = sub(4, 2);   // sub  ?     
}

int main()
{
	//test();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test10();
	test11();
	return 0;
}