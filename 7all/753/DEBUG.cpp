#include<iostream>


class DEBUG
{
    public:
        //constepr DEBUG()=default;
        DEBUG()=default;
        //double b;
        int b;
};
class DEBUG2
{
    public:
        //constepr DEBUG()=default;
        DEBUG2(){};
        int b;
        //double  c;
};
int main()
{
    DEBUG a;
    DEBUG2 xa;
    using namespace std;
    printf("%d",a.b);
    printf("%s","   ");
    //printf("%d",a.c);
    cout<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<endl;
    printf("%d",xa.b);
    printf("%s","   ");
    //printf("%lf",xa.c);

    return 0;
}

// 构造函数有两个阶段
// 1.初始化阶段，所有类类型提前初始化
// 2.计算阶段
// 注意：阶段1，有且只有类类型进行初始化，常量是不会进行初始化的
//
// 类中的所有成员变量，都是声明
// 1.具体验证，在任何成员变量之前+extern关键字会报错
//
// 类中的所有成员方法都是隐士内联的。
// ===>这样在调用的时候回直接原地展开/逻辑复杂的话，就会转换成函数。（有必要研究一下c++对象模型）

