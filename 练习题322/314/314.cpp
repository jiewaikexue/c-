#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
	vector<int>vInt;
	int i;
	cout << "输入Q退出" << endl;
	while (cin >> i)
	{
		
		
		if (i == 'q')
		{
			break;
		}
		vInt.push_back(i);
	}
	for (auto a : vInt)
		cout << a;
	return 0;
}

