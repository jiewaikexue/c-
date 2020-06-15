#include<iostream>
#include<cmath>
using namespace std;


double myAbs(double a);
int main()
{
    double a=0;
    cout<<"1请输入一个数"<<endl;
    cin>>a;
    cout<<"这个数的绝对值是："<<myAbs(a)<<endl;
}

double myAbs(double a)
{
    if(a<0)
    {
        return  a*(-1);
    }
    else return a;
}
