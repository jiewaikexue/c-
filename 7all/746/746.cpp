#include<iostream>
#include<vector>
#include<string>
using namespace std;
class A
{

    public:
        string a_;
        int b_;
        double c_;
        char d_;
        bool e_=true;
        A()=default;
};
class B
{

    public:
        string a_;
        int b_;
        double c_;
        char d_;
        bool e_=false;
        B()=default;
};
class C
{

    public:
        string a_="qwe";
        int b_;
        double c_;
        char d_;
        bool e_;
        C(){};
};
int main()
{
    A a;
    B b;
    C c;
    cout<<a.a_<<' '<<endl;cout<<a.b_<<' '<<endl;cout<<a.c_<<' '<<endl;cout<<a.d_<<' '<<endl;cout<<a.e_<<endl;
    cout<<endl;
    cout<<b.a_<<' '<<endl;cout<<b.b_<<' '<<endl;cout<<b.c_<<' '<<endl;cout<<b.d_<<' '<<endl;cout<<b.e_<<endl;
    cout<<endl;
    cout<<c.a_<<' '<<endl;cout<<c.b_<<' '<<endl;cout<<c.c_<<' '<<endl;cout<<c.d_<<' '<<endl;cout<<c.e_<<endl;
    return 0;
}
