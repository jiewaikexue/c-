#include <stdlib.h>
#include <iostream>
using namespace std;
class A
{
public:
	A()
	{}
	A(int a, int b, int c)
		:_a(a)
		, _b(b)
		, _c(c)
	{
		cout << "A(int, int, int)" << endl;
	}

	A(const A& A)
	{
		cout << "A(const A&)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
	int _b;
	int _c;
};

void test()
{
	int* pi = (int*)malloc(sizeof(int));
	int* pi2 = (int*)realloc(pi, sizeof(int)* 4); //原地扩容
	int* pi3 = (int*)realloc(pi2, sizeof(int)* 1000);  //非原地扩容：会释放原有空间
	int* pi4 = (int*)realloc(pi3, sizeof(int)); //减小容量
	//int* pi5 = (int*)realloc(NULL, sizeof(int)); //相当于malloc
	//释放空间 : A 正常释放   B 编译错误  C 崩溃
	//realloc: 不需要显示释放传入ralloc的指针参数所指向的空间
	//free(pi);
	//free(pi2);
	//free(pi3);
	free(pi4);
	//free(pi5);
	//calloc: 申请空间 + 空间的零初始化
	int* pi5 = (int*)calloc(4, sizeof(int));


}

void test2()
{
	//自定义类型： malloc --> 申请空间，不会调用构造函数
	A* pa = (A*)malloc(sizeof(A));  //堆
	A aobj(1,2,3);  //栈

	//C++申请内存的方式： new + 数据类型(初始值)
	//                  new + 数据类型[元素个数]
	int* p = new int;  //创建了1个整形空间
	int* p2 = new int(2); //创建了1个整形空间，且值为2
	int* p3 = new int[10];  //创建10个连续的整形空间

	// 自定义类型： new --> 申请空间 + 调用构造函数初始化
	A* pa2 = new A(4, 5, 6);
	//new <---> delete     new [] <---> delete[]
	delete p;
	delete p2;
	delete[] p3;
	//自定义类型： delete --->  调用析构函数资源清理 + 释放空间
	delete pa2;

}

void test3()
{
	//A array[10];

	cout << "heap creat: " << endl;
	//申请自定义类型的连续空间，需要有默认构造函数
	A* array2 = new A[10];

	//delete array2;
	delete[] array2;

	A* pa = new A(10, 20, 30); //带参构造
	A* pa2 = new A;  //默认构造

	A* pcopy = new A(*pa);
}

//void* operator new(size_t n): 全局函数，不是new的运算符重载函数， 功能类似于malloc
// void* operator new(size_t n): malloc + 异常
//operator++(A a)  operator++(a), ++a;
void test4()
{
	void* ptr1 = operator new(10);
	//void* ptr = new 10;
	int* p1 = (int*) malloc(sizeof(int));
	int* p2 = (int*) operator new(sizeof(int));
	//malloc申请失败：返回空指针
	char* p3 = (char*)malloc(sizeof(char)* (0x7fffffff));
	//operator申请失败： 抛异常
	char* p4 = (char*)operator new(sizeof(char)* (0x7fffffff));
}

//operator delete : 封装free
void test5()
{
	int* pi = (int*) operator new(sizeof(int));
	operator delete(pi);
}

struct ListNode
{
	int _data;
	ListNode* _next;

	//operator new定制
	void* operator new(size_t n)
	{
		void* ptr = allocator<ListNode>().allocate(1);
		cout << "memory poll allocate" << endl;
		return ptr;
	}
	//operator delete定制
	void operator delete(void* ptr)
	{
		allocator<ListNode>().deallocate((ListNode*)ptr, 1);
		cout << "memory poll deallocate" << endl;
	}
};

struct ListNode2
{
	int _data;
	ListNode* _next;
};

void test6()
{
	ListNode* lst = new ListNode;

	ListNode2* lst2 = new ListNode2;

	delete lst; 
	delete lst2;
}

void test7()
{
	A* pa = (A*)malloc(sizeof(A));

	//显式调用构造函数: new定位表达式： 在已经申请好的空间上进行初始化
	// new (空间指针) 类型（参数列表）
	new (pa)A(1, 2, 3); //带参构造

	A* pa2 = (A*)malloc(sizeof(A));
	new (pa2) A; //无参构造


}

int main()
{
	//test();
	//test2();
	//test3();
	//test4();
	//test6();
	test7();
	return 0;
}