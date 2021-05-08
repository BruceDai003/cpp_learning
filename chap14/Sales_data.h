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

    // 重载运算符
    friend std::istream& operator>>(std::istream&, Sales_data&); // read
    friend std::ostream& operator<<(std::ostream&, const Sales_data&); // print
    friend Sales_data operator+(const Sales_data&, const Sales_data&); // add
    friend Sales_data operator-(const Sales_data&, const Sales_data&); // subtraction

    // 4个构造函数
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) {};
    Sales_data(const std::string &s, unsigned u, double p):
        bookNo(s), units_sold(u), revenue(u * p) {};
    Sales_data(std::istream &in); // 只有该构造函数没有直接给出定义

    // 其他成员函数
    std::string isbn() const { return bookNo;}
    Sales_data& combine(const Sales_data&);
    // 重载复合赋值运算符，等价于上面的combine
    Sales_data& operator+=(const Sales_data&); // combine( compound-assignment)
    Sales_data& operator-=(const Sales_data&); // subtrction( compound-assignment)
    Sales_data& operator=(const std::string&); // assignment from std::string

    private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    inline double avg_price() const;
};

// non-member APIs declaration
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

// 重载运算符声明
std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
Sales_data operator-(const Sales_data&, const Sales_data&); 

// 内联函数的定义
inline double Sales_data::avg_price() const
{
    return (units_sold ? revenue / units_sold : 0);
}
#endif
