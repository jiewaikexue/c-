#include<iostream>
#include<string>
using namespace std;
int main()
{
    string currString,preString;
    bool b=true;
    cout<<"请输入一组字符串"<<endl;
    while(cin>>currString)
    {
        if(!isupper(currString[0]))
            continue;
        else if(currString==preString)
        {
            b=false;
            cout<<"连续出现的字符串是："<<currString<<endl;
            break;
        }
        preString=currString;
    }
    if(b)
        cout<<"没有连续出现的字符串"<<endl;
    return 0;
}
