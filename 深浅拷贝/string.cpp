#include <string.h>
class String
{
public:
	String(const char* str)
		:_data(new char[strlen(str) + 1])
	{
		strcpy(_data, str);
	}

	//����� ��������
	String(const String& str)
		:_data(new char[strlen(str._data) + 1])
	{
		strcpy(_data, str._data);
	}

	//�������ֵ���������
	String& operator=(const String& str)
	{
		if (this != &str)
		{
			//�ж��Ƿ���Ҫ�ͷ�������Դ
			if (_data)
				delete[] _data;
			//���µĿռ�
			_data = new char[strlen(str._data) + 1];
			strcpy(_data, str._data);
		}
		return *this;
	}

	~String()
	{
		//�ͷ���Դ
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
		}
	}
private:
	char* _data;
	/*int _size;
	int _capacity;*/
};

void test()
{
	String str1("123");
	String str2(str1); //��������
	String str3("456");
	str3 = str2;  //��ֵ��������غ���
}

int main()
{
	test();
	return 0;
}