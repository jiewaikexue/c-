#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<vector>
using std::vector;
int main()
{vector<char>v;

    int grades=0;
    cout<<"请输入你的成绩"<<endl;
    cin>>grades;
    if(grades>100||grades<0)
        cout<<"成绩无效"<<endl;
    else {
        int tmp=grades;
        while(tmp)
        {
         int c=tmp%10;
          v.push_back(c+'A'); 
          tmp/=10;
        }

    }
    for(auto beg=v.rbegin();beg!=v.rend();beg++)
    {
        cout<<*beg;
    
    }
   cout<<endl;
    return 0;
}
