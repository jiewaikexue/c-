


#include <iostream>
using namespace std;
//这是一个类的前向声明，只是告知了编译器，有这种类型
//但是这种类型的大小编译器是不知道的
//必须找到后面的实现，先走一遍
//计算出大小
//才能定义变量
class X;

class Y
{
    //不能这样写
   // X x_;
   X *x_;
};
class X
{
    Y  y_;
};
