#include<iostream>
using namespace std;
void print1(const int *p)
{

    cout<<*p<<endl;
}
void print2(const int *p,const int sz)
{
    for(int i=0;i!=sz;i++)
        cout<<*p++;
}

void print3(const int *b,const int *e)
{
    for(const int * q=b;q!=e;++q)
        cout<<*q<<endl;

}
int main()
{
    int i=0;
    int j[2]={0,1};
    print1(&i);
    print1(j);
    print2(j,sizeof(j)/sizeof(j[1]));
    
    print3(begin(j),end(j));
}
