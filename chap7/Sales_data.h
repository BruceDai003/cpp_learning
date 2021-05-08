#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>

class Sales_data
{
    public:
    // 声明3个友元函数
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    // 4个构造函数
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) {};
    Sales_data(const std::string &s, unsigned u, double p):
        bookNo(s), units_sold(u), revenue(u * p) {};
    Sales_data(std::istream &in);
    std::string isbn() const { return bookNo;}
    Sales_data& combine(const Sales_data&);

    private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double avg_price() const;
};

// non-member APIs declaration
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
#endif
