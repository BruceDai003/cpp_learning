#include <iostream>
using namespace std;

int main()
{
    string nums[] = {"I", "am", "coding", "CPP"};
    string *p = nums;
    //std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*
    // p是一个指针
    cout << typeid(p).name() << endl;

    auto sa(nums);
    //std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*
    // sa是一个指针
    cout << typeid(sa).name() << endl; 

    // ex.cpp:15:10: error: assigning to 'std::__cxx11::basic_string<char> *' from incompatible type 'const char [6]'
    //sa = "Error";

    // But decltype does return an array
    decltype(nums) s1{"I", "love", "coding"};
    // std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > [4]
    // s1是一个数组
    cout << typeid(s1).name() << endl;
    s1[3] = "Python";
    for(auto s: s1)
        cout << s << endl;
}
