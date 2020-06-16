#include<iostream>
#include<string>
using namespace std;
int main(int argc,char *argv[])
{
    if(argc<3)
        return -1;
    string str;
    for(int i=0;i!=argc;i++)
        str+=argv[i];
    cout<<str<<endl;
    return 0;

}
