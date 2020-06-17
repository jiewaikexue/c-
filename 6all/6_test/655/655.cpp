#include<iostream>
#include<vector>

using namespace std;
auto func(int a,int b)->int
{
return a+b; 
}
auto func2(int a,int b)->int
{
return a-b; 
}
auto func3(int a,int b)->int
{
return a*b; 
}
auto func4(int a,int b)->int
{
return a/b; 
}
int main ()
{
    vector<decltype(func)*>v;
    v.push_back(func);
    v.push_back(func2);
    v.push_back(func3);
    v.push_back(func4);
    for(auto a:v)
        cout<<a(8,4)<<' ';
    return 0;
}
