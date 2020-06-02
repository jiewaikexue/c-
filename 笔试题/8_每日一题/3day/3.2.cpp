#include<iostream>
#include<vector>


using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(){
	vector<int>v;
	int size = 0;
	cin >> size;
	int max = 0;
	int min = 0;
	if (size>0)

	{
		int ctl = size;
		while (ctl)
		{
			//ctl--;
			int tmp = 0;
			cin >> tmp;
			if (ctl == size)
			{
				min = tmp;
				max = tmp;

			}
			else{
				if (tmp>max)
				{
					max = tmp;
				}
				else if (tmp<min)
				{
					min = tmp;
				}
			}
			v.push_back(tmp);
			ctl--;
		}

		int sort_size = max - min+1;
		vector<int>vect(sort_size, 0);
		for (auto it : v)
		{
			vect[(it) + 0 - min] += 1;
		}
		int tru = 0;
		int tru_t = 0;
		int i = 0;
		for (auto it : vect){
			
			if ((it)>size / 2 && (it)>tru)
			{
				tru = it;
				tru_t =i;
			}
i++;
		}
		if (tru != 0)
			cout <<tru_t+min;
	}
	cout << 0;
	return 0;
}

