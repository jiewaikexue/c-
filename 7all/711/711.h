#ifndef SALES_DATA
#define SALES_DATA
#include<string>
#include <iostream>
using namespace std;
class SalesData 
{
    private:
        string book_note_;
        unsigned units_sold_=0;
        double selling_price_=0.0;
        double sale_price_=0.0;
        double discount_=0.0;
    public:
        string Isbn()const {
            return book_note_;
        }
        SalesData& Combine(const SalesData& rhs)
        {
            units_sold_+=rhs.units_sold_;
            sale_price_=(rhs.sale_price_*rhs.units_sold_+sale_price_*units_sold_)/(rhs.units_sold_+units_sold_);

            if(selling_price_!=0)
                discount_=sale_price_/selling_price_;
            return *this;
        }
        istream& Read(istream & is,SalesData& item)
        {
            is>>item.book_note_;
            is>>item.units_sold_;
            is>>item.selling_price_>>item.sale_price_;
            return is;
        }
        ostream& Print(ostream &os,const SalesData &item)
        {
            os<<item.book_note_<<" "<<item.units_sold_<<' '<<item.selling_price_<<' '<<item.sale_price_<<endl;
            return os;
        }
        SalesData Add(const SalesData &lhs,const SalesData &rhs)
        {
            SalesData sum=lhs;
            sum.Combine(rhs);
        return sum;
        }
        //默认初始化---default必须在声明的时候就要写出来，不然就是自定义初始化
        SalesData()=default;//要求生成一个默认的最简单的构造函数
        // 这里用的是初始值列表
        // 在调用的时候，这里是直接初始化，，因为他没有缺省参数
        SalesData(const string &book_note):book_note_(book_note){}
        SalesData(const string &book,const unsigned num,const double sellp,const double salep)
        {
            book_note_=book;
            units_sold_=num;
            selling_price_=sellp;
            sale_price_-=salep;
            if(selling_price_!=0)
            discount_=sale_price_/selling_price_;
        }
        SalesData(istream &is)
        {
            is>>*this;
        }
        friend ostream& operator<<(ostream& os,const SalesData& sada);
        friend istream& operator>>(istream& is, SalesData& sada);
};
        ostream& operator<<(ostream& os,const SalesData& sada)
{
 os<<sada.book_note_<<' '<<sada.units_sold_<<' '<<sada.sale_price_<<' '<<sada.selling_price_<<' '<<sada.discount_<<endl;
 return os;
}
        istream& operator>>(istream& is, SalesData& sada)
{
 is>>sada.book_note_>>sada.units_sold_>>sada.sale_price_>>sada.selling_price_>>sada.discount_;
 return is;
}
#endif
