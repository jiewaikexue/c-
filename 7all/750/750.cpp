#include<iostream>
#include<string>
using namespace std;
class Person
{
    private:
        string Str_Name_;//姓名
        string Str_Address_;//地址
    public:
        Person()=default;
        Person(const string &name,const string &address)
        {
            Str_Name_=name;
            Str_Address_=address;
        }
        explicit Person(istream &is)
        {
            is>>*this;
        }
        string GetName()const 
        {return Str_Name_;}
        string GetAddress()const 
        {return Str_Address_;}
        istream& Read();
        friend istream& operator>>(istream&is,Person &per);
        friend ostream &operator<<(ostream&os,const Person &per);
};
istream& operator>>(istream &is,Person& per)
{
    is>>per.Str_Name_>>per.Str_Address_;
    return is;
}
ostream &operator<<(ostream&os,const Person &per)
{
    os<<per.Str_Name_<<' '<<per.Str_Address_<<endl;
    return os;
}
