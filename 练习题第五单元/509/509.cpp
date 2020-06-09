#include<iostream>
#include<string>
using namespace std;

int main()
{
    unsigned int vel=0;
    char ch;
    while(cin>>ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            ++vel;
    }
    cout<<vel<<endl;
    return 0;
}
