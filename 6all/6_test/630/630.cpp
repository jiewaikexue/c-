#include<iostream>
#include<string>
using namespace std;
 
bool str_subrange(const string &str1 ,const string &str2)
{
//大小相同，此时用普通的相等性来判断结果作为返回值
    if(str1.size()==str2.size())
        return  str1==str2;
    //得到较短的str对象的大小，
    auto size=(str1.size()>str2.size()?str2.size():str1.size());
    //检查两个string对象的对应字符是否相等，以较短字符为限
    for(decltype(size)i=0;i!=size;i++)
    {
        if(str1[i]!=str2[i])
            return  false;//这里报错
    }
    //控制流肯能尚未返回任何值就结束了函数的执行
    //这个错误编译器可能检查不出来
    /*#################################################*/
    //这里也应该有一个人return 
    //不然逻辑是有点问题的
    return true;
}
int main()
{
    string str1;
    string str2;
    cout<<str_subrange(str1,str2);
}
