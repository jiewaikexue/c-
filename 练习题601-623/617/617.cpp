#include <iostream>
#include<cctype>
#include<string>
using namespace std;
int isUP(const string &str)
{
    
    for(auto &a:str)
        if(isupper(a))
            return 1;
    return 0;
}
int toLw(string& str)
{
    
    for(auto &a:str)
    {
        a=tolower(a);
        cout<<a<<' ';
    }
    cout<<"toLw:"<<str<<endl;
    return 1;
}
int main()
{
    string str;

    getline(cin,str); 
    isUP(str)?cout<<"up"<<endl:cout<<"low"<<endl;
    toLw(str);
    cout<<str<<endl;


}
