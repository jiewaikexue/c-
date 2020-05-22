#include <string>
#include <iostream>
using namespace std;
void test()
{
	string str = "12345";
	//size/length:��Ч�ַ��ĸ���
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
	//capacity: ��ǰ������Դ�ŵ�����ַ���
	int capacity = str.capacity();
	int size = str.size();
	str.push_back('a');  //12345a
	for (int i = 0; i < 10; ++i)
		str.push_back('b');
	capacity = str.capacity();
	//resize: �޸���Ч�ַ��ĸ���
	// 1. ��С��Ч�ַ��ĸ���
	str.resize(10);
	size = str.size();
	capacity = str.capacity();
	// 2.������Ч�ַ��ĸ�����������λ�ø�ֵΪ�ڶ�����������
	str.resize(30, 'c');
	size = str.size();
	capacity = str.capacity();
	// 3. ��С��Ч�ַ�������û���µĿ��е�λ�ã����Եڶ�����������
	str.resize(15, 'd');
	size = str.size();
	capacity = str.capacity();
	//resize: Ĭ�ϸ�ֵΪ\0��
	// 4. ������Ч�ַ�������������λ��Ϊ�ڶ���������ȱʡ���ݣ� \0 
	str.resize(30); 
	size = str.size();
	capacity = str.capacity();
	// 5. ������Ч�ַ��ĸ�����������������������
	str.resize(60);
	size = str.size();
	capacity = str.capacity();
}

void test3()
{
	string s = "123";
	int capacity = s.capacity();
	//reserve: ��������, ֻ���������������С����
	s.reserve(100);
	capacity = s.capacity();
	//��С����ʧ��
	s.reserve(20);
	capacity = s.capacity();

	//PJ�棬string �����߼��� ��һ�ν���2�������ݣ������������֮ǰ������1.5��
	//SGI�棬 string �����߼��� 2������
	string s2;
	//ͨ��reserve�ӿڣ���ǰ���ÿռ䣬������ߴ���Ч��
	s2.reserve(100);
	capacity = s2.capacity();
	cout << "��ʼ����: " << capacity << endl;
	for (int i = 0; i < 100; ++i)
	{
		s2.push_back(i);
		if (capacity != s2.capacity())
		{
			capacity = s2.capacity();
			cout << capacity << endl;
		}
	}

	//�������ݵĳ�����
	// 1. resize�� ��size > capacity
	// 2. reserve: �µ����� > ԭ������
	// 3. �����ַ�
}

void test4()
{
	string s = "1231234567897878787776456435342341242312312312312";
	int size = s.size();
	int capacity = s.capacity();
	//shrink_to_fit: ��������size��ͬһ�������������κ�����
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
	//shrink_to_fit: ��������size����ͬһ�������ǣ�������м�С�������߼������ջ���������size��ͬһ������
	s.shrink_to_fit();
	size = s.size();
	capacity = s.capacity();


}

void test5()
{
	//operator[]
	// 1. �ɶ���д
	// 2. ���size, ���Ա���string
	string s = "12345";
	for (int i = 0; i < s.size(); ++i)
	{
		cout << s.operator[](i) << " ";
		//�޸ĵ�ǰλ�õ�����
		s[i] = '0';
	}
	cout << endl;

	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << " ";  // �ȼ���s.operator[](i)
	}
	cout << endl;

	string str2 = "45678";
	//����������
	string::iterator it = str2.begin();
	while (it != str2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//��Χfor����: ͨ��������ʵ�ֵ�
	for (char c : str2)
	{
		cout << c << " ";
	}
	cout << endl;
}

void test6()
{
	string s;
	//push_back: β���ַ�
	s.push_back('1');
	s.push_back('2');
	s.push_back('3');
	s.push_back('4');
	s.push_back('5');
	//append: β���ַ���
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
	string s3;  //s��ͬ
	s3.append(s2, 5, 3);  //abc
	string s4;
	s4.append("12345", 2); // 12
	string s5;
	s5.append(5, 'a');  // aaaaa

	string s6;
	/*
	template <class InputIterator>
	string& append(InputIterator first, InputIterator last);
	InputIterator:   ���͵������� ���������ĵ�����
	�ɴ���ĵ��������ͣ�ֻҪʵ�ʴ���ĵ�����������֮���������char����
	
	*/
	s6.append(s3.begin() + 2, s3.end());  // c
	char strArr[] = { '1', '2', '3', '4', '5', '6' };
	string s7;
	s7.append(strArr, strArr + sizeof(strArr) / sizeof(strArr[0]));  //123456
	
}

void test7()
{
	string s;
	s += '1';  //�ȼ���push_back
	s += "2345"; //�ȼ���append(char*)
	string s2;
	s2 += s;  //������append(string)
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
	//ɾ��������������ҿ��� [first, end)
	iterator erase (iterator first, iterator last);
	*/
	string s = "123456789";
	string s2;
	s2.append(s);
	s.erase(0, 2); //3456789
	s.erase(0); //""
	s2.erase(s2.begin() + 3); //ɾ����������ָ����ַ� 12356789
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
	//string�ĳ�Ա����
	s.swap(s2);
	//��������ַ������͵�ȫ�ֺ���
	swap(s, s2);  //�߼��ȼ��� s.swap(s2)

	int a = 1;
	int b = 2;
	//������ַ�����ȫ�ֺ���
	swap(a, b);
}

void  test12()
{
	string s = "123";
	//c_str, data�ȼ�
	cout << s.c_str() << endl;
	cout << s.data() << endl;
	//string֧�����������������غ���
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
	//�ַ����Ƚϣ�����ASCII��ֵ�Ƚϣ���������
	bool ret = s > s2;
	ret = s > s3;
	ret = s == s2;
	ret = s == s3;
}

void test15()
{
	string s;
	cin >> s;  //�����ո����
	getline(cin, s); //�������л���ָ���ķָ�������
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