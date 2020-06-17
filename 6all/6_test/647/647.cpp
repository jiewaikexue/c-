#include<iostream>
#include<vector>

using namespace std;
    template<class T>
void myprint(vector<T>&a,int size)
{
    unsigned sz=static_cast<unsigned>(a.size());
#ifndef NDEBUG
cout<<"vector对象的大小是："<<sz<<endl;
#endif //NDEBUG 
    if(size<0)return ;
    myprint(a,size-1);    
    cout<<a[size]<<' ';
    return ;
}
int main()
{
    vector<int> a{1,2,3,4,5,6,7,8,9,10};
    myprint(a,a.size()-1);
    return 0;
}
