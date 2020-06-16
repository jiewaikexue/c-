#include<iostream>
void print(const int ia[10])
{
    for (size_t i=0;i!=10;i++)
        cout<<ia[i]<<endl;
}

数组维度和边界问题：
    最好还是传一个数组元素个数，这样不会越界
    
