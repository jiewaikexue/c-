#include<iostream>
using namespace std;

void Swao(int *a,int *b)
{
    int tmp=0;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
int main()
{
    int  a=1;
    int b=2;
    Swao(&a,&b);
    cout<<a<<' '<<b<<endl;
    return 0;
}
