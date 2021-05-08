#include <iostream>
#include "Sales_data.h"

Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream& operator>>(std::istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    if (is)
        // 如果输入流的状态是合法的
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " 
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum -= rhs;
    return sum;
}

Sales_data& Sales_data::operator-=(const Sales_data &rhs)
{
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}

Sales_data& Sales_data::operator=(const std::string &isbn)
{
    *this = Sales_data(isbn);
    return *this;
}

std::istream& read(std::istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream& print(std::ostream &os, const Sales_data &item)
{
    os << "编号为" << item.isbn() << "的书售出" << item.units_sold << "件，总收入"
       << item.revenue << "，均价" << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}


