#include"Chapter6.h"
using namespace std;

int fact(int num)
{
    if(num<0)
        return -1;
    int ret=1;
    for(int i=num;i>0;i--)
        ret*=i;
    return ret;
}
