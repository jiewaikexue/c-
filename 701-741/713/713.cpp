#include "706.h"
int main()
{

    cout<<"请输入交易记录（ISBN，销售量，原价，实际售价）："<<endl;
    SalesData total;
    if(cin>>total)
//    if(total.Read(cin,total))
    { SalesData trans;
        while(cin>>trans)
 //      while(trans.Read(cin,trans))
        {
            if(total.Isbn()==trans.Isbn())
         //total.Combine(trans);
               total=total.Add(total,trans);
            else{
       cout<<total<<endl;
   //             total.Print(cout,total);
                total=trans;
            }
        }
       cout<<total<<endl;
    }
    else{
        //没有输入
        cerr<<" NO data ?!"<<endl;
        return -1;
    }
    return 0;
}
