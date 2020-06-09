#include <iostream>
#include<stdexcept>
using namespace std;
int main()
{
    int a=0;
    int b=0;
    cout<<"请输入两个整数"<<endl;
    cout<<"a:"<<endl;
    cin>>a;
    cout<<"b:"<<endl;
    cin>>b;
    if(!b)
    {
    throw runtime_error("除数为0");
    }

    cout<<"a/b="<<a/b<<endl;
    return 0;
}
