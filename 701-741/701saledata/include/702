#ifndef SALES_DATA
#define SALES_DATA
#include<string>
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
};
#endif
