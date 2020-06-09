#include <iostream>
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
        cout<<"被除数为0，不合理"<<endl;
        return -1;
    }
    cout<<"a/b="<<a/b<<endl;
    return 0;
}
