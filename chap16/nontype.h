/*
 * @Description: 
 * @Author: Liwei Dai
 * @Date: 2021-05-18 14:54:24
 * @LastEditors: VSCode
 * @LastEditTime: 2021-05-18 14:56:47
 */
#pragma once
#include <string>

template <std::string *temp> // pointer to object
void f()
{
    std::cout << *temp << std::endl;    
}

template <std::string &temp> // reference to obejct
void g()
{
    std::cout << temp << endl;
    temp += "... appended some string."
}
