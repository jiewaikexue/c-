#include <string>
#include <iostream>
using namespace std;
void test()
{
	string str = "12345";
	//size/length:有效字符的个数
	cout << str.size() << endl;  //5
	cout << str.length() << endl;
	string str2 = "123    45";
	cout << str2.size() << endl;
	cout << str2.max_size() << endl;
	cout << str.max_size() << endl;
	str2.clear();
	cout << str2.size() << endl;
	cout << str2.empty() << endl;
}

void test2()
{
	string str = "12345";
	//capacity: 当前对象可以存放的最大字符数
	int capacity = str.capacity();
	int size = str.size();
	str.push_back('a');  //12345a
	for (int i = 0; i < 10; ++i)
		str.push_back('b');
	capacity = str.capacity();
	//resize: 修改有效字符的个数
	// 1. 减小有效字符的个数
	str.resize(10);
	size = str.size();
	capacity = str.capacity();
	// 2.增加有效字符的个数，新增的位置赋值为第二个参数内容
	str.resize(30, 'c');
	size = str.size();
	capacity = str.capacity();
	// 3. 减小有效字符个数，没有新的空闲的位置，所以第二个参数无用
	str.resize(15, 'd');
	size = str.size();
	capacity = str.capacity();
	//resize: 默认赋值为\0，
	// 4. 增加有效字符个数，新增的位置为第二个参数的缺省内容， \0 
	str.resize(30); 
	size = str.size();
	capacity = str.capacity();
	// 5. 增加有效字符的个数，容量不够，进行增容
	str.resize(60);
	size = str.size();
	capacity = str.capacity();
}

void test3()
{
	string s = "123";
	int capacity = s.capacity();
	//reserve: 增加容量, 只增加容量，不会减小容量
	s.reserve(100);
	capacity = s.capacity();
	//减小容量失败
	s.reserve(20);
	capacity = s.capacity();

	//PJ版，string 增容逻辑： 第一次进行2倍的增容，后面的增容是之前容量的1.5倍
	//SGI版， string 增容逻辑： 2倍增容
	string s2;
	//通过reserve接口，提前开好空间，可以提高代码效率
	s2.reserve(100);
	capacity = s2.capacity();
	cout << "初始容量: " << capacity << endl;
	for (int i = 0; i < 100; ++i)
	{
		s2.push_back(i);
		if (capacity != s2.capacity())
		{
			capacity = s2.capacity();
			cout << capacity << endl;
		}
	}

	//产生增容的场景：
	// 1. resize： 当size > capacity
	// 2. reserve: 新的容量 > 原有容量
	// 3. 插入字符
}

void test4()
{
	string s = "1231234567897878787776456435342341242312312312312";
	int size = s.size();
	int capacity = s.capacity();
	//shrink_to_fit: 当容量与size在同一个量级，不起任何作用
	s.shrink_to_fit();
	size = s.size();
	capacity = s.capacity();

	s.reserve(50);
	size = s.size();
	capacity = s.capacity();

	s.shrink_to_fit();
	size = s.size();
	capacity = s.capacity();

	s.reserve(50000);
	size = s.size();
	capacity = s.capacity();
	//shrink_to_fit: 当容量与size不在同一个量级是，它会进行减小容量的逻辑，最终会让容量和size在同一个量级
	s.shrink_to_fit();
	size = s.size();
	capacity = s.capacity();


}

void test5()
{
	//operator[]
	// 1. 可读可写
	// 2. 结合size, 可以遍历string
	string s = "12345";
	for (int i = 0; i < s.size(); ++i)
	{
		cout << s.operator[](i) << " ";
		//修改当前位置的内容
		s[i] = '0';
	}
	cout << endl;

	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << " ";  // 等价于s.operator[](i)
	}
	cout << endl;

	string str2 = "45678";
	//迭代器遍历
	string::iterator it = str2.begin();
	while (it != str2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//范围for遍历: 通过迭代器实现的
	for (char c : str2)
	{
		cout << c << " ";
	}
	cout << endl;
}

void test6()
{
	string s;
	//push_back: 尾插字符
	s.push_back('1');
	s.push_back('2');
	s.push_back('3');
	s.push_back('4');
	s.push_back('5');
	//append: 尾插字符串
	s.append("abcde");
	/*
	string (1)
	string& append (const string& str);
	substring (2)
	string& append (const string& str, size_t subpos, size_t sublen);
	c-string (3)
	string& append (const char* s);
	buffer (4)
	string& append (const char* s, size_t n);
	fill (5)
	string& append (size_t n, char c);
	range (6)
	template <class InputIterator>
	string& append (InputIterator first, InputIterator last);
	*/
	string s2;
	s2.append(s);
	string s3;  //s相同
	s3.append(s2, 5, 3);  //abc
	string s4;
	s4.append("12345", 2); // 12
	string s5;
	s5.append(5, 'a');  // aaaaa

	string s6;
	/*
	template <class InputIterator>
	string& append(InputIterator first, InputIterator last);
	InputIterator:   泛型迭代器， 不代表具体的迭代器
	可传入的迭代器类型：只要实际传入的迭代器解引用之后的类型是char即可
	
	*/
	s6.append(s3.begin() + 2, s3.end());  // c
	char strArr[] = { '1', '2', '3', '4', '5', '6' };
	string s7;
	s7.append(strArr, strArr + sizeof(strArr) / sizeof(strArr[0]));  //123456
	
}

void test7()
{
	string s;
	s += '1';  //等价于push_back
	s += "2345"; //等价于append(char*)
	string s2;
	s2 += s;  //等于与append(string)
}

void test8()
{
	/*
	string (1)
	string& insert (size_t pos, const string& str);
	substring (2)
	string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);
	c-string (3)
	string& insert (size_t pos, const char* s);
	buffer (4)
	string& insert (size_t pos, const char* s, size_t n);
	fill (5)
	string& insert (size_t pos, size_t n, char c);
	void insert (iterator p, size_t n, char c);
	single character (6)
	iterator insert (iterator p, char c);
	range (7)
	template <class InputIterator>
	void insert (iterator p, InputIterator first, InputIterator last);
	*/
	string s;
	s.insert(0, 2, '0');  //00
	s.insert(1, "abcde"); //0abcde0
	s.insert(3, "12345", 2); // 0ab12cde0
	s.insert(s.begin(), 3, 'k'); //kkk0ab12cde0

	string s2 = "abc";
	s2.insert(1, s);  //akkk0ab12cde0bc;
	char strArr[] = { 'z', 'z', 'z' };
	s2.insert(s2.end(), strArr, strArr + sizeof(strArr) / sizeof(strArr[0])); //akkk0ab12cde0bczzz
}

void test9()
{
	/*
	sequence (1)
	string& erase (size_t pos = 0, size_t len = npos);
	character (2)
	iterator erase (iterator p);
	range (3)
	//删除的区间是左闭右开： [first, end)
	iterator erase (iterator first, iterator last);
	*/
	string s = "123456789";
	string s2;
	s2.append(s);
	s.erase(0, 2); //3456789
	s.erase(0); //""
	s2.erase(s2.begin() + 3); //删除迭代器所指向的字符 12356789
	s2.erase(s2.begin() + 1, s2.end() - 1); //19
	s2.erase(s2.begin(), s2.end()); // ""
}

void test10()
{
	string s = "123456789";
	//string& replace (size_t pos,  size_t len,  const char* s);
	s.replace(3, 2, "abcdefg"); //
}

void test11()
{
	string s = "123";
	string s2 = "abc";
	//string的成员函数
	s.swap(s2);
	//处理各种字符串类型的全局函数
	swap(s, s2);  //逻辑等价于 s.swap(s2)

	int a = 1;
	int b = 2;
	//处理非字符串的全局函数
	swap(a, b);
}

void  test12()
{
	string s = "123";
	//c_str, data等价
	cout << s.c_str() << endl;
	cout << s.data() << endl;
	//string支持输出输入运算符重载函数
	cout << s << endl;
	cin >> s;
	cout << s << endl;
}

void test13()
{
	string s = "123";
	char str[10];
	s.copy(str, 2, 0);

	string s2 = "http://www.cplusplus.com/reference/string/string/substr/";
	size_t pos = s2.find("://");
	size_t pos2 = s2.find("/", pos + 3);
	string s3 = s2.substr(pos + 3, pos2 - pos - 3);
	pos2 = s2.find("string");
	pos2 = s2.rfind("string");

	pos2 = s2.find("123");
	
}



void test14()
{
	string s = "123";
	string s2 = "9";
	string s3 = "124";
	//字符串比较：按照ASCII码值比较，不看长度
	bool ret = s > s2;
	ret = s > s3;
	ret = s == s2;
	ret = s == s3;
}

void test15()
{
	string s;
	cin >> s;  //遇到空格结束
	getline(cin, s); //遇到换行或者指定的分隔符结束
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
	//test9();
	//test10();
	//test11();
	//test12();
	//test13();
	//test14();
	test15();
	return 0;
}