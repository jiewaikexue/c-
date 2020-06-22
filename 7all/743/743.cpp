#include<iostream>
#include<string>
using namespace std;

class NoDefault
{
    private:
        int ival_;
    public:
        NoDefault(int a):ival_(a){}
//        NoDefault()=default;
};
class C
{
    public:
        //NoDefault nd_;
        NoDefault yd_;
        string a_;
    public:
        C()=default;
};
int main()
{
    C c;
    cout<<c.a_<<endl;
    return 0;
}
