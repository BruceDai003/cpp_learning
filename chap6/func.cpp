#include <iostream>
#include <vector>
using namespace std;

using arrT = int[10]; // arrT是一个类型别名，它表示的类型是含有10个整数的数组

arrT* func(int i)
{
    static arrT x;
    for (auto &c:x)
        c = i;
    return &x;
}

int odd[] = {1, 3, 5};
int even[] = {2, 4, 6};

decltype(odd) *arrPtr(int i)
{
    return (i % 2) ? &odd : &even;
}


vector<string> error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
    string expected{"expected"};
    return {"This", "is", expected};
}


int main()
{
    //int (*(*pf)(int))[3] = arrPtr;
    //decltype(odd) *(*pf)(int) = arrPtr;
    typedef decltype(arrPtr) *PointerFunc;
    PointerFunc pf = arrPtr;
    //int (*)(*pf)(int)[3];
    cout << "Function pointers\n";
    for (auto j : *pf(3))
        cout << j << " ";
    cout << " done\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "For i = " << i << endl;
        for (auto j : *arrPtr(i))
            cout << j << " ";
        cout << endl << string(20, '=') << endl;
    }
    cout << endl;
    //for (auto s : error_msg({"SumOfFloat", "3.95", to_string(3)}))
    //    cout << s << endl;
    //auto a = func(5);
    //cout << **a << endl;
    return 0;
}
