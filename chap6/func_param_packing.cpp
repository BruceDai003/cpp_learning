#include <iostream>
#include <cstdarg>

void function(...)
{
    std::cout << 1 << std::endl;
}

void function(int num, ...)
{
    std::cout << 2 << std::endl;
}

void test_1()
{
    // 简单测试上面的function函数，在传入不同类型的参数时，实际调用的是哪个

    int x{5};
    std::string name{"Josh"};

    function(x);
    //function(name); // error if using clang: cannot pass object of non-trivial type 'std::string' through variadic function
}

int add_nums(int count, ...)
{
    int result = 0;

    va_list args; // args相当于char* args

    va_start(args, count); // 调用后，args此时指向参数列表中的第一个25

    //std::cout << typeid(args).name() << std::endl;

    //result += va_arg(args, int);
    std::cout << count << std::endl;
    for (int i = 1; i < count; ++i)
        result += va_arg(args, int);

    va_end(args);
    return result;
}

void test_2()
{
    // 使用cstdarg头文件
    std::cout << add_nums(4, 25, 25, 10, 20) << std::endl;    

}

//void test_3()
//{
//    int i = 10;
//    int a = i;
//    printf("i = %d\n", a);
//    // 下面的汇编语句的作用就是改变内存中i的值，但是又不让编译器知道
//    __asm {
//        mov dword ptr [ebp-4], 20h
//    }
//    int b = i;
//    printf("i = %d\n", b);
//
//}

int main()
{
    //test_3();
    // test_1();
    test_2();
}
