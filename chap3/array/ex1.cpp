#include <iostream>
using namespace std;

int main()
{
    int ia[3][4];
    using int_array = int[4]; // 新标准下类型别名的声明
    typedef int int_array[4]; // 等价的typedef声明

    for (int_array *p = ia; p != ia + 3; ++p)
    {
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << " ";
        cout << endl;
    }

    // 2. 指针，常量和类型别名
    typedef char *pstring;
    const pstring cstr = 0;
    const pstring *ps;
    const char *ccstr = 0;
    cout << typeid(cstr).name() << endl;
    cout << typeid(ps).name() << endl;
    cout << typeid(ccstr).name() << endl;

    cout << ps << endl;
    cout << *ps << endl;
}

