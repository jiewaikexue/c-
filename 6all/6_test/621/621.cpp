#include<iostream>
#include<string>
#include<ctime>
#include<cstdio>
using namespace std;
int myCompare(const int j,int * a)
{
return j>*a?j:*a;
}
int main()
{
    srand((unsigned)time(NULL));
    int a[10];
    for(auto&x:a)
        x=rand()%33;
    cout<<"请输入一个数：";
    int j=0;
    cin>>j;
    cout<<"你输入的数字与数组中max的结果是"<<myCompare(j,a)<<endl;
    cout<<"数组一览：" ;
    for(auto y :a)
        cout<<y<<' ';
    cout<<endl;
    return 0;
}
