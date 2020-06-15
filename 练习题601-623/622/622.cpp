#include<iostream>
using namespace std;

int main()
{
    int a=11;
    int b=22;
    int * _a=&a;
    int* _b=&b;
    int *tmp=nullptr;
    tmp=_a;
    _a=_b;
    _b=tmp;

    
}
    
