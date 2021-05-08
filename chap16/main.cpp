/*
 * @Description: 
 * @Author: Liwei Dai
 * @Date: 2021-05-08 14:54:27
 * @LastEditors: VSCode
 * @LastEditTime: 2021-05-08 14:55:46
 */
#include <iostream>
#include <vector>
#include "compare.h"

using std::vector;
using std::string;
int main()
{
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
    
}