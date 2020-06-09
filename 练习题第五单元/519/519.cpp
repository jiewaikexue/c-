#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a1;
    string a2;
    char cont='k';
    do{

        cout<<"输入连个字符串对象"<<endl;
        cout<<"a1:";
        cin>>a1;
        cout<<endl;
        cout<<"a2";
        cin>>a2;

        cout<<(a1.size()>a2.size()?a2:a1)<<endl;
        cout<<"输入q退出。k继续"<<endl;
        cin.sync();
        cin.ignore(1024,'\n');
        cin>>cont;
    }while(cont!='q');
    return 0;
}

