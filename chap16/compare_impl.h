/*
 * @Description: 
 * @Author: Liwei Dai
 * @Date: 2021-05-08 11:43:53
 * @LastEditors: VSCode
 * @LastEditTime: 2021-05-08 15:06:45
 */

#include "compare.h"

template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
