#include<iostream>
#include<string>

using namespace std;
int main()
{
    //定义3个字符串变量，分别表示；
    //当前操作符。当前一个字符串，当前出现穿刺术最多的操作符
    string currString,preString="",maxString;

    //定义俩整型变量，分别表示
    //当前连续出现的字符串数量，当前出现最多的字符串数量
    int currCnt=1,maxCnt=0;
    while(cin>>currString)
    {
        //如果当前字符串与前一个字符串一致，更新状态
        if(currString==preString) 
        {
            ++currCnt;

            if(currCnt>maxCnt)
            {
                maxCnt=currCnt;
                maxString=currString;
            }
        }
        //如果当前字符串与前一个字符串不一致，重置currCnt
        else{
            currCnt=1;
        }
        //更新preString以便于下一次循环使用
        preString=currString;
    }
    if(maxCnt>1)
    {
        cout<<"出现最多的字符串是："<<maxString<<"次数是："<<maxCnt<<endl;

    }
    else{
        cout<<"每个字符串都只出现了一次"<<endl;

    }
    return 0;
}
