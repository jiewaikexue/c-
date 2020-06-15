#include<iostream>
#include<ctime>
using namespace std;


int mycnt()
{
    static int cnt=0;
    cnt++;
    return cnt;
}
int main()
{
    srand((unsigned)time(NULL));
    for(int i=rand()%30;i>0;i--)
        mycnt(); 
    cout<<"调用次数为："<<mycnt()<<endl;
    return 0;
}
