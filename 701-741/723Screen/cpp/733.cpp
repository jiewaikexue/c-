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
    public:
        Screen()=default;
        Screen(unsigned hight,unsigned width):height_(hight),width_(width),contents_(hight*width,' '){}

        Screen(unsigned hight,unsigned width,char a):height_(hight),width_(width),contents_(hight*width,a){}
        Screen& move(unsigned r,unsigned c)
        {
            //等宽移动 
            cursor_=r*width_+c;
            return *this;
        }
        Screen& set(char ch)
        {
            contents_[cursor_]=ch;
            return *this;
        }
        Screen& set(unsigned r,unsigned c,char ch)
        {
            cursor_=r*width_+c;
            contents_[cursor_]=ch;
            return *this;
        }
        Screen& Display()
        {
            cout<<contents_;
            return *this;
        }
        unsigned GetContents()
        {
            return cursor_;
        }
unsigned Size();
};
unsigned Size()
{
    return static_cast<unsigned>(1)  ;
}
