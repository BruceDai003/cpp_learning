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

void test_operator()
{
    Sales_data s1;
    std::cout << "输入一个Sales_data\n";
    std::cin >> s1;
    std::cout << "输入的是\n" <<  s1 << std::endl;

    Sales_data s2;
    std::cout << "再输入第二个Sales_data\n";
    std::cin >> s2;
    std:: cout << "输入的是\n" << s2 << std::endl;
    
    std::cout << "执行加法后的结果是\n";
    s2 += s1;
    std::cout << s2 << std::endl;

    std::cout << "我再来减一次\n";
    s2 = s2 - s1;
    std::cout << s2 << std::endl;

    std::string isbn("n50");
    s1 = isbn;
    std::cout <<"使用重载的赋值运算符修改s1的ISBN号\n";
    std::cout << s1 << std::endl;
}

int main()
{
    test_operator();
    //test_aggregator();
    //test_constructor();
    //sales_management();
    return 0;
}
