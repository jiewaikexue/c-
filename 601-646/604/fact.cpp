#include<iostream>
using namespace std;

int fact(int num)
{
    int number=1;
    if(num>0)
    {
        for(int i=num;i>0;i--)
            number*=i;       
    }
    else return -1;

    return number;
}
int main()
{
    cout<<"请输入一个数字"<<endl;
    int number=0;
    cin>>number;
    
    cout<<fact(number);
    return 0;

}
