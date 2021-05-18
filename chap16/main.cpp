/*
 * @Description: 
 * @Author: Liwei Dai
 * @Date: 2021-05-08 14:54:27
 * @LastEditors: VSCode
 * @LastEditTime: 2021-05-18 15:10:27
 */
#include <iostream>
#include <vector>
#include "compare.h"
#include "nontype.h"

using std::vector;
using std::string;

void test_compare()
{
    std::cout << "Now testing function template compare" << std::endl;
    int result1, result2, result3, result4;
    result1 = compare(1, 5);
    result2 = compare(3.5, 2.0);
    string s1{"Liwei"}, s2{"LeBron"};
    result3 = compare(s1, s2);
    vector<int> vec1{1, 2, 3};
    vector<int> vec2{1, 6, 0};
    result4 = compare(vec1, vec2);

    std::cout << "Comparing ints\t" << result1 << std::endl;
    std::cout << "Comparing doubles\t" << result2 << std::endl;
    std::cout << "Comparing strings\t" << result3 << std::endl;
    std::cout << "Comparing vectors\t" << result4 << std::endl;
    std::cout << std::string(20, '=') << std::endl;
}

void test_nontype()
{
    std::cout << "Now testing none-type template parameters" << std::endl;  
    std::string s{"can assign values locally"};
    f<&s>();
    g<s>();
    std::cout << s << std::endl;
    std::cout << std::string(20, '=') << std::endl;
}

int main()
{
    test_compare();
    test_nontype();
    
    
}