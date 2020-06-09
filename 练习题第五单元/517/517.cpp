#include<iostream>

#include<vector>
using namespace std;
int main()
{
    vector<int >v1={0,1,1,2};
    vector<int>v2={0,1,1,2,3,5,8};
    vector<int>v3={3,5,6};
    vector<int>v4={3,5,0,9,2,7};
    //定义迭代器
    auto a1=v1.cbegin();
    auto a2=v2.cbegin();
    auto a3=v3.cbegin();
    auto a4=v4.cbegin();
    //设定循环条件：v1和v2都尚未检查完
    
    while(a1!=v1.cend()&&a2!=v2.end())
    {
        //如果当前位置的两个元素不相等，则肯定没有前缀关系
        if(*a1!=*a2)
        {
            cout<<"v1和v2之间不存在前缀关系" <<endl;
        break;
        }
    ++a1;
    ++a2;
    if(a1==v1.cend())
    {
        cout<<"v1 是v2的前缀"<<endl;
    }
    if(a2==v2.cend())
    {

        cout<<"v2 是v1的前缀"<<endl;
    }

    }
    return 0;
}

