#include <iostream>
using namespace std;
struct A
{};

void test()
{
	//C++: auto: ����ʱ�Զ������Ƶ�
	//��auto����ı���������Ҫ�г�ʼ�����ʽ
	auto a = 10;
	auto b = 3 + 4;
	auto c = 1.2;
	auto d = 'a';
	A sa;
	auto e = sa;

	int& ra = a;
	auto& ra2 = a;  // ra2�Ƶ�����������
	auto ra3 = a;  // ra3�Ƶ��ɺ�aһ��������

	auto pa = &a;  // pa: ָ������
	auto* pa2 = &a;  // pa2: ָ������

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(e).name() << endl;

	//std::unordered_set<std::string>::const_iterator it = ���ʽ;
	//auto it = ���ʽ;
	int array[] = { 1, 2, 3 };
	//���鲻��������auto
	//auto array2[] = { 1, 2, 3 };
	auto f = 2, g = 3;
	//������������������ʽ�����Ͳ�һ�£�������auto����
	//auto h = 3, k = 'a';
}

//����������������Ϊauto
/*
void  funa(auto a)
{

}
*/

//���ڷ�Χ��forѭ����ֻ�ܱ�����Χȷ���ļ���
// for:  Ԫ������  ��ǰ��Ҫ������Ԫ��ֵ  ��  ��Ҫ�����ļ���
void test2()
{
	int array[] = { 1, 2, 3, 4, 5, 6 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	//���ڷ�Χforѭ���� ʹ�ü򵥣���ȫ������Խ�磩
	for (int a : array)
	{
		// continue , break ��������ʹ��
		cout << a << " ";
	}
	cout << endl;

	for (int& a : array)
	{
		// continue , break ��������ʹ��
		cout << a << " ";
	}
	cout << endl;

	/*
	��Χ��ȷ��������ʹ�÷�Χfor
	int* pa = array;
	for (int a : pa)
	{

	}
	*/

	//�����Զ���ļ��ϣ�����������ṩ�� begin, end�������Լ������ò�����==�� ����ʹ�÷�Χfor
}

void fun1(int a)
{
	cout <<"fun1(int)"<< endl;
}

void fun1(int* a)
{
	cout << "fun2(int*)" << endl;
}

void test3()
{
	int* pi = NULL;  //�ȼ��ڣ� int* pi = 0;
	// NULL: �����ԣ� ����0�� ָ���ֵ
	// ������Ĭ��NULLΪ����0
	fun1(NULL);

	//nullptr: ָ���ֵ�� ����ָ���ֵ��nullptr, ���Խ�������ָ�����͵���ʽ����ת��
	// nullptr����Ϊ�� std::nullptr_t
	int* pi2 = nullptr;
	fun1(nullptr);
	cout << typeid(nullptr).name() << endl;
}

//����һ��C++�ࣺ class / struct  ����  {};

//��struct ����һ���ࣺ ��Ա��Ĭ��Ȩ���ǹ��е�
struct Person
{
	int getAge()
	{
		return age;
	}

	void print()
	{
		cout << name << " " << age << " " << gender << " " << number << endl;
	}

	void driveCar()
	{
		cout << "driveCar()" << endl;
	}

	int age;
	char* name;
	char* gender;
	int number;
};
//�����޶����� public, private, protectedֻ�����Ƴ�Ա������ķ���Ȩ�ޣ����ڲ�����Ա֮�䲻�ܷ����޶���������
//��class ����һ����, Ĭ�Ϸ���Ȩ����pirvate(˽�е�)
class Person2
{
public:  // public: ����Ϊpublic�ĳ�Ա�������ⶼ�ǿ��Է��ʣ�����ɼ�
	//��Ա����
	int getAge()
	{
		return age;
	}

	void print()
	{
		cout << name << " " << age << " " << gender << " " << number << endl;
	}

	void driveCar();
private:  //����Ϊprivate�ĳ�Ա�����ⲻ�ܷ��ʣ����ⲻ�ɼ�

	//��Ա������ ����
	int age;
	char* name;
	char* gender;
	Person b;
protected:  //����Ϊprotected�ĳ�Ա�����ⲻ�ܷ��ʣ����ⲻ�ɼ�
	int number;
};

//������������� + ::  + ��Ա
// Person2::driverCar: ����Person2���������
void Person2::driveCar()
{
	cout << "Person2::driveCar()" << endl;
}

//driveCar������ȫ��������
void driveCar()
{
	cout << "::driveCar()" << endl;
}


void test4()
{
	Person2 p;
	//p.print();
	////p.age = 18;
	//p.number = 2013;

	p.driveCar();
	driveCar();

	Person p2;
	//p2.print();
	p2.age = 20;
	p2.number = 10;
}

//�౾��ռ�ڴ�  �ࣺ �൱��һ��ͼֽ
//���ʵ������ ����һ�������͵ı��� ---> ����  �� �൱��ͨ��ͼֽ����ķ���
// �Զ������͵ı���һ���Ϊ���󣬵��Ǳ����Ͷ���û������ֻ�ǽз���ͬ

//��Ķ���ģ�ͣ��������ڴ��еĴ洢��ʽ
//��Ĵ�С�� ֻ�ͳ�Ա�����йأ��ͳ�Ա�����޹ء�����Ĵ�СΪ1 byte, 
//��Ĵ�С�� ��ѭ�ڴ�����ԭ��
//��Ա�������ڶ����У���Ա��������ڹ����Ĵ����

class B
{
public:
	void fun(int a)
	{
		// a: �ǳ�Ա����
		// _a: ��Ա����
		cout << _a << a << endl;
	}
private:
	int _a;
};

class C
{
public:
	void func(int a)
	{
		++a;
		cout << a << endl;
	}
private:
	int _c;
};

class D
{
public:
	void func(int a)
	{
		++a;
		cout << a << endl;
	}
};

//����: ��С��1
class E
{

};

B  globalB;  //���ݶ�

void test5()
{
	int num = sizeof(B);  // 4
	num = sizeof(C);  // 4
	num = sizeof(D); // 1
	num = sizeof(E);  //  1

	int  a = 10;  //ջ
	int* pa = (int*)malloc(sizeof(int));
	// *pa: ����

	B b;  //ջ
	B* pb = (B*)malloc(sizeof(B));
	// *pb: ����
}

int main()
{
	//test();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}