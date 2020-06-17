#include<iostream>
 
using namespace std;
int calc(int a,int b)
{
    return 1;
}
/*int calc(const int a,const int b)
{
  return 2;
}*/
int get()
{
    return 1;
}
/*double get()
{

}*/
int *reset(int *);
double *reset(double *);
 int main()
{
    
int a,b;
const int a1=1;
const int b1=1;
int  *a2=&a;
double *b2=nullptr;
}


//顶层const的形参会被忽略顶层const
//返回值类型和重载无所谓
