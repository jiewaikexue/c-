#include <iostream>
#include<stdexcept>
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

    try{
        if(!b)
        {
            throw runtime_error("");
        }
    }  catch(runtime_error){
            cout<<"除数为0"<<endl;
        }
   

    cout<<"a/b="<<a/b<<endl;
    return 0;
    
}
