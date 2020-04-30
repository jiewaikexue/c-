#pragma  once
class Person3
{
public:  // public: 声明为public的成员，在类外都是可以访问，类外可见
	//成员函数
	int getAge();

	void print();

	void driveCar();
private:  //声明为private的成员在类外不能访问，类外不可见

	//成员变量， 属性
	int age;
	char* name;
	char* gender;
protected:  //声明为protected的成员在类外不能访问，类外不可见
	int number;
};