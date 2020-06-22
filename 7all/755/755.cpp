#include<iostream>
#include<vector>
using namespace std;
//class Example 
//{
//    public:
//        static double rate_=6.5;
//        static const int vec_size_=20;
//        static vector<double> vec_(vec_size_);
//
//};
//
//
//double Example::rate_;
//vector<double> Example::vec_;
class Example 
{
    public:
    //Example():vec_size_(10){};
    public:
        static double rate_;
         static const int vec_size_;
        static vector<double> vec_;

};

const int Example::vec_size_=10;
double Example::rate_=0;
vector<double> Example::vec_;
int main()
{
 Example a;   
cout<< a.vec_size_;
return 1;
}
//静态成员，只能定义在类外，函数外，准确说是全局区
//能在类内部直接初始化的，有且仅有静态常量
