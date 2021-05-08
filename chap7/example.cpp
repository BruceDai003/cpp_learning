#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

void sales_management()
{
    Sales_data total;
    if (read(cin, total))
    {
        Sales_data trans; // 保存下一笔交易
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl; // 打印当前总的交易
                total = trans; // 更新当前记录的交易
            }
        }
        print(cout, total) << endl; // 打印最后一笔交易
    }
    else
        cerr << "No data input!" << endl;
}


void test_constructor()
{
    Sales_data s1("001", 5, 10);
    std::string null_book = "009";
    // 构造一个临时的Sales_data对象
    // 该对象的units_sold和revenue等于0，bookNo等于null_book
    print(cout, s1.combine(null_book)) << endl;
    // 2. 利用Sales_data(std::istream &in)的构造函数进行类类型转换
    print(cout, s1.combine(cin)) << endl;

    // 只允许一步类类型转换。
    // s1.combine(string("9-999")); // Correct
    // s1.combine(Sales_data("9-999")); // Correct
    // error: reference to type 'const Sales_data' could not bind to an lvalue of type 'const char [6]'
    // s1.combine("9-999"); // Wrong

}

struct Person
{
    std::string name;
    int age;
};

void test_aggregator()
{
    Person a{"Liwei Dai", 32};
    Person b{"Kun Guo", 32};
    //Person c{1, "Yaocan Dai"};
}

int main()
{
    test_aggregator();
    //test_constructor();
    //sales_management();
    return 0;
}
