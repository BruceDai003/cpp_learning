#include <iostream>

void test_char_const()
{
    const char* const c1 = "what";
    std::cout << c1 << std::endl;
    std::cout << c1[2] << std::endl;

    //c1 = "hey"; // error: cannot assign
    //std::cout << c1 << std::endl;
    //std::cout << c1[2] << std::endl;
}

void test_char()
{
    const char* c1 = "what";
    std::cout << c1 << std::endl;
    std::cout << c1[2] << std::endl;

    c1 = "hey";
    std::cout << c1 << std::endl;
    std::cout << c1[2] << std::endl;
}


int main()
{
    test_char();
    test_char_const();
}
