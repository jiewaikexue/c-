#include<iostream>
using namespace std;

template <class T>
T icount(initializer_list<T>x)
{
    T i;
    for(auto a :x)
    {
        T y=a;
        i= i+y;
    }return i;
}
int main()
{

    initializer_list<int> a{1,2,3,4,5,6};
    initializer_list<int> a1{1,2,3,4,5};
    initializer_list<int> a2{1,2,3,4};
    initializer_list<int> a3{1,2,3};
    initializer_list<int> a4{1,2};

    cout<<icount<int>(a)<<endl; 
    cout<<icount<int>(a1)<<endl; 
    cout<<icount<int>(a2 )<<endl; 
    cout<<icount<int>(a3 )<<endl; 
    cout<<icount<int>(a4 )<<endl; 
    cout<<icount<string>({"str","str"," ","str"} )<<endl; 
}
