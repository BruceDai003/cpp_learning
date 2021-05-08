/*
 * @Author: Liwei Dai
 * @Date: 2021-05-08 11:23:28
 * @LastEditTime: 2021-05-08 11:43:40
 * @LastEditors: VSCode
 * @Description: 
 * @FilePath: \cpp_learning\chap16\compare.h
 */
template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}