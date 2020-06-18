#include<iostream>
using namespace std;
class Person
{
    private:
        string Str_Name_;//姓名
        string Str_Address_;//地址
    public:
    string GetName()const 
    {return Str_Name_;}
    string GetAddress()const 
    {return Str_Address_;}
};
