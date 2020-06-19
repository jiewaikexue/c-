#include<iostream>
#include<string>
using namespace  std;
class Screen
{
    private:
        //屏幕的高度和宽度
        unsigned height_=0,width_=0;
        // 光标的当前位置
        unsigned cursor_=0;
        //屏幕的内容
        string contents_;
};
