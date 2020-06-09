#include<iostream>
#include<string>
using namespace std;

int main()
{
    unsigned int vel=0;
    char ch;
    while(cin.get(ch))
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            ++vel;
        if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
            ++vel;
    
        if(ch=='\t'||ch=='\r'||ch==' ' )
            ++vel;
    }
    cout<<vel<<endl;
    return 0;
}
