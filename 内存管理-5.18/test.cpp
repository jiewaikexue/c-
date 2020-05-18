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
	int* pi2 = (int*)realloc(pi, sizeof(int)* 4); //ԭ������
	int* pi3 = (int*)realloc(pi2, sizeof(int)* 1000);  //��ԭ�����ݣ����ͷ�ԭ�пռ�
	int* pi4 = (int*)realloc(pi3, sizeof(int)); //��С����
	//int* pi5 = (int*)realloc(NULL, sizeof(int)); //�൱��malloc
	//�ͷſռ� : A �����ͷ�   B �������  C ����
	//realloc: ����Ҫ��ʾ�ͷŴ���ralloc��ָ�������ָ��Ŀռ�
	//free(pi);
	//free(pi2);
	//free(pi3);
	free(pi4);
	//free(pi5);
	//calloc: ����ռ� + �ռ�����ʼ��
	int* pi5 = (int*)calloc(4, sizeof(int));


}

void test2()
{
	//�Զ������ͣ� malloc --> ����ռ䣬������ù��캯��
	A* pa = (A*)malloc(sizeof(A));  //��
	A aobj(1,2,3);  //ջ

	//C++�����ڴ�ķ�ʽ�� new + ��������(��ʼֵ)
	//                  new + ��������[Ԫ�ظ���]
	int* p = new int;  //������1�����οռ�
	int* p2 = new int(2); //������1�����οռ䣬��ֵΪ2
	int* p3 = new int[10];  //����10�����������οռ�

	// �Զ������ͣ� new --> ����ռ� + ���ù��캯����ʼ��
	A* pa2 = new A(4, 5, 6);
	//new <---> delete     new [] <---> delete[]
	delete p;
	delete p2;
	delete[] p3;
	//�Զ������ͣ� delete --->  ��������������Դ���� + �ͷſռ�
	delete pa2;

}

void test3()
{
	//A array[10];

	cout << "heap creat: " << endl;
	//�����Զ������͵������ռ䣬��Ҫ��Ĭ�Ϲ��캯��
	A* array2 = new A[10];

	//delete array2;
	delete[] array2;

	A* pa = new A(10, 20, 30); //���ι���
	A* pa2 = new A;  //Ĭ�Ϲ���

	A* pcopy = new A(*pa);
}

//void* operator new(size_t n): ȫ�ֺ���������new����������غ����� ����������malloc
// void* operator new(size_t n): malloc + �쳣
//operator++(A a)  operator++(a), ++a;
void test4()
{
	void* ptr1 = operator new(10);
	//void* ptr = new 10;
	int* p1 = (int*) malloc(sizeof(int));
	int* p2 = (int*) operator new(sizeof(int));
	//malloc����ʧ�ܣ����ؿ�ָ��
	char* p3 = (char*)malloc(sizeof(char)* (0x7fffffff));
	//operator����ʧ�ܣ� ���쳣
	char* p4 = (char*)operator new(sizeof(char)* (0x7fffffff));
}

//operator delete : ��װfree
void test5()
{
	int* pi = (int*) operator new(sizeof(int));
	operator delete(pi);
}

struct ListNode
{
	int _data;
	ListNode* _next;

	//operator new����
	void* operator new(size_t n)
	{
		void* ptr = allocator<ListNode>().allocate(1);
		cout << "memory poll allocate" << endl;
		return ptr;
	}
	//operator delete����
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

	//��ʽ���ù��캯��: new��λ���ʽ�� ���Ѿ�����õĿռ��Ͻ��г�ʼ��
	// new (�ռ�ָ��) ���ͣ������б�
	new (pa)A(1, 2, 3); //���ι���

	A* pa2 = (A*)malloc(sizeof(A));
	new (pa2) A; //�޲ι���


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