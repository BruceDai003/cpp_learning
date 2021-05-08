#include <iostream>
#include "my_header.h"

extern int global_x;

void func()
{
    std::cout << global_x << std::endl;
    global_x = 1001;
    std::cout << global_x << std::endl;
}


int main()
{
    func();
}
