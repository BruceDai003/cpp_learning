/*
 * @Description: 
 * @Author: Liwei Dai
 * @Date: 2021-05-08 11:43:53
 * @LastEditors: VSCode
 * @LastEditTime: 2021-05-08 11:47:56
 */

#include <iostream>
#include <vector>
#include "compare.h"

int main()
{
    int result1, result2, result3, result4;
    result1 = compare(1, 5);
    result2 = compare(3.5, 2.0);
    result3 = compare("Liwei", "LeBron");
    result4 = compare(vector<int>(1, 2, 3), vector<int>(1, 6, 0));

    std::cout << "Comparing ints\t" << result1 << std::endl;
    std::cout << "Comparing doubles\t" << result2 << std::endl;
    std::cout << "Comparing strings\t" << result3 << std::endl;
    std::cout << "Comparing vectors\t" << result4 << std::endl;
    
}