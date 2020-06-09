#include<iostream>
#include<string>
using namespace std;

int main()
{
    string surrString,perString;
    bool b1=true;
    cout<<"请输入一组字符串："<<endl;
    while(cin>>surrString)
    {
        if(surrString==perString)
        {
            b1=false;
            cout<<"连续出现的字符串是："<<surrString<<endl;
            break;
        }
        perString=surrString;
    }
    if(b1)
        cout<<"没有出现"<<endl;
    return 0;
}

