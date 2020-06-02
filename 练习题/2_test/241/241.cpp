#include<iostream>
#include<string>

using namespace std;

class Sales_data{

    friend std::istream& operator>>(std::istream &,Sales_data&);

    friend std::istream& operator<<(std::istream &,Sales_data&);
    friend bool operator<(const Sales_data&,const Sales_data&);
    friend bool operator==(const Sales_data&,const Sales_data&);
    public:
    Sales_data()=default;
    Sales_data(const std::string &book):bookNo(book){
    }
    Sales_data(std::istream& is){is>>*this;}
    public:
    Sales_data &operator
}
