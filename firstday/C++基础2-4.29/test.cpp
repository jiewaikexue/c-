#include "a.h"
#include <time.h>
#include <iostream>
using namespace std;

void test()
{
	int a = 10;
	int b = -1;
	//ra引用， 是变量a的别名
	int& ra = a;
	int& rra = a;
	ra = 20;
	rra = 30;
	//引用在定义的时候必须初始化
	int& ra3 = a;
	//修改了a的值
	//引用定义完成之后，不会再指向新的实体
	ra3 = b;

	const  int  c = 20;
	//常引用：  const变量， 常量，临时变量
	const int& rc = c;
	//rc = 100;
	const int& r1 = 10;

	double d = 2.3;
	ra = d;
	double& rd = d;
	//int& rd2 = d;  不支持，类型不一致
	const int& rd2 = d;  //隐式类型转换  double  -->  int

	int* pa = &a;
	//const int& rpa = pa;  //不能进行隐式类型转换
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
//引用做参数
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

//引用做返回值
int& Add(int& ra)
{
	return ++ra;
}
//引用做返回值： 不用返回生命周期小于调用函数生命周期的变量
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
	// 参数传引用比传值效率高： 传引用没有拷贝发生
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
	// 返回引用比返回值效率高： 返回引用没有拷贝发生
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
	rb._a = 20;   //编译器底层翻译成指针的操作：rb->_a = 20;
	pb->_a = 40;

	copy._a = 30;
	//rb->_a = 10;

}

void test9()
{
	//指针和引用的区别
	// 1. 引用在定义时必须初始化， 指针可以不用初始化
	int a = 10;
	int& ra = a;
	int* pa;
	// 2. 只有一级引用，没有多级引用， 指针可以有多级指针
	int& ra2 = a;
	int** pa2;
	int*** pa3;
	// 3. 引用自加是实体内容自加， 而指针自加是地址的偏移
	ra++;  // a的内容自加1
	pa++;  //向后偏移4个字节的空间
	// 4. sizeof(引用)表示实体大小，sizeof(指针)表示指针的大小
	B b;
	B& rb = b;
	B* pb = &b;
	sizeof(rb);  //求b的大小
	sizeof(pb);  //求指针的大小
	// 5. 没有空引用，但是有空指针
	//int& ra3 = NULL;
	int* pc = NULL;
	// 6. 引用更加安全， 不会有空异常
}

#define F(X, Y)  (X) / (Y)   //宏函数  ----> 预处理： 宏替换

void  test99()
{
	int ret = F(9, 3); //编译时宏替换： int ret = 9 / 3
	int a = 2;
	int b = 4;
	int c = 2;
	ret = F(a + b, c);  // 宏替换： ret = 2 + 4 / 2
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
	ret = dev(a, b);  // ret =  a / b;   内联函数指令原地展开， 没有函数栈帧开销

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