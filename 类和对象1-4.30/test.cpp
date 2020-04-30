#include <iostream>
using namespace std;
struct A
{};

void test()
{
	//C++: auto: 编译时自动类型推导
	//用auto定义的变量，必须要有初始化表达式
	auto a = 10;
	auto b = 3 + 4;
	auto c = 1.2;
	auto d = 'a';
	A sa;
	auto e = sa;

	int& ra = a;
	auto& ra2 = a;  // ra2推导成引用类型
	auto ra3 = a;  // ra3推导成和a一样的类型

	auto pa = &a;  // pa: 指针类型
	auto* pa2 = &a;  // pa2: 指针类型

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(e).name() << endl;

	//std::unordered_set<std::string>::const_iterator it = 表达式;
	//auto it = 表达式;
	int array[] = { 1, 2, 3 };
	//数组不能声明成auto
	//auto array2[] = { 1, 2, 3 };
	auto f = 2, g = 3;
	//定义多个变量，如果表达式的类型不一致，不能用auto声明
	//auto h = 3, k = 'a';
}

//函数参数不能声明为auto
/*
void  funa(auto a)
{

}
*/

//基于范围的for循环：只能遍历范围确定的集合
// for:  元素类型  当前需要遍历的元素值  ：  需要遍历的集合
void test2()
{
	int array[] = { 1, 2, 3, 4, 5, 6 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	//基于范围for循环： 使用简单，安全（不会越界）
	for (int a : array)
	{
		// continue , break 可以正常使用
		cout << a << " ";
	}
	cout << endl;

	for (int& a : array)
	{
		// continue , break 可以正常使用
		cout << a << " ";
	}
	cout << endl;

	/*
	范围不确定，不能使用范围for
	int* pa = array;
	for (int a : pa)
	{

	}
	*/

	//对于自定义的集合，如果集合中提供了 begin, end方法，以及解引用操作，==， 可以使用范围for
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
	int* pi = NULL;  //等价于： int* pi = 0;
	// NULL: 二义性， 整数0， 指针空值
	// 编译器默认NULL为整数0
	fun1(NULL);

	//nullptr: 指针空值， 建议指针空值用nullptr, 可以进行任意指针类型的隐式类型转换
	// nullptr类型为： std::nullptr_t
	int* pi2 = nullptr;
	fun1(nullptr);
	cout << typeid(nullptr).name() << endl;
}

//定义一个C++类： class / struct  类名  {};

//用struct 定义一个类： 成员的默认权限是共有的
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
//访问限定符： public, private, protected只是限制成员在类外的访问权限，类内部，成员之间不受访问限定符的限制
//用class 定义一个类, 默认访问权限是pirvate(私有的)
class Person2
{
public:  // public: 声明为public的成员，在类外都是可以访问，类外可见
	//成员函数
	int getAge()
	{
		return age;
	}

	void print()
	{
		cout << name << " " << age << " " << gender << " " << number << endl;
	}

	void driveCar();
private:  //声明为private的成员在类外不能访问，类外不可见

	//成员变量， 属性
	int age;
	char* name;
	char* gender;
	Person b;
protected:  //声明为protected的成员在类外不能访问，类外不可见
	int number;
};

//类的作用域：类名 + ::  + 成员
// Person2::driverCar: 属于Person2类的作用域
void Person2::driveCar()
{
	cout << "Person2::driveCar()" << endl;
}

//driveCar：属于全局作用域
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

//类本身不占内存  类： 相当于一个图纸
//类的实例化： 创建一个类类型的变量 ---> 对象  ： 相当于通过图纸建造的房子
// 自定义类型的变量一般称为对象，但是变量和对象没有区别，只是叫法不同

//类的对象模型：对象在内存中的存储方式
//类的大小： 只和成员变量有关，和成员函数无关。空类的大小为1 byte, 
//类的大小： 遵循内存对齐的原则
//成员变量存在对象中，成员函数存放在公共的代码段

class B
{
public:
	void fun(int a)
	{
		// a: 非成员变量
		// _a: 成员变量
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

//空类: 大小是1
class E
{

};

B  globalB;  //数据段

void test5()
{
	int num = sizeof(B);  // 4
	num = sizeof(C);  // 4
	num = sizeof(D); // 1
	num = sizeof(E);  //  1

	int  a = 10;  //栈
	int* pa = (int*)malloc(sizeof(int));
	// *pa: 堆上

	B b;  //栈
	B* pb = (B*)malloc(sizeof(B));
	// *pb: 堆上
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