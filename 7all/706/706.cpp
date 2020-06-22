#include<string>
#include<iostream>
using namespace std;
class SalesData 
{
    public:
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
};
int main()
{
    SalesData a;
    a.Read(cin,a);
    cout<<a.book_note_<<' '<<a.units_sold_<<' '<<a.selling_price_<<' '<<a.sale_price_<<' '<<a.discount_<<endl;
    return 1;
}
