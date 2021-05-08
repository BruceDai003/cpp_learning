#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <array>
#include <deque>
#include <forward_list>

using namespace std;

int main()
{
    // 定义一个元素是list<int>类型的vector
    vector<list<int>> vec;
    // 写入一组数据，并打印出来
    for (int i = 0; i < 5; ++i)
    {
        list<int> li(3, i);
        vec.push_back(li);
    }
    cout << "vector size = " << vec.size() << endl;
    for (vector<list<int>>::const_reference item : vec)
    {
        cout << "Item size:\t" << item.size() << endl;
        if (item.size() > 0)
        {
            for (list<int>::value_type elem : item)
                cout << "\t\t" << elem << endl;
        }
        cout << " = = = = = = = = = " << endl;
    }

    // 尝试使用迭代器
    deque<string> q{"we", "are", "not", "done"};
    string look_up{"are"};
    deque<string>::const_iterator q_beg = q.begin(), q_end = q.end();
    for (; q_beg != q_end; ++q_beg)
    {
        if (look_up == *q_beg)
        {
            cout << "We found \"" << *q_beg << "\"" << endl;
            break;
        }
    }
    if(q_beg == q_end)
        cout << "We can't find " << look_up << endl;
    // 给deque双端队列添加和删除元素，并打印
    q.pop_back();
    q.pop_back();
    q.pop_front();
    for (auto item : q)
        cout << "item:\t" << item << endl;
    q.push_front("citizens");
    q.push_front("The");
    q.push_back("happy");
    for (auto item : q)
        cout << "item:\t" << item << endl;
    
    // 测试标准库的array和内置的array是否支持拷贝或赋值
    //int digs[10] = {0, 1, 2, 3, 4, 5};
    //int cpy[10] = digs; // error: array initializer must be an initializer list
    //cpy = digs; // error: array type 'int [10]' is not assignable

    array<int, 10> digits{0, 1, 2, 3};
    array<int, 10> copy(digits);

    // 练习9.13
    list<int> li_1{1, 2, 3};
    vector<double> vec_1(li_1.cbegin(), li_1.cend());
    for (auto item : vec_1)
        cout << item << endl;

    // 测试swap和赋值之后，容器内部的迭代器，引用，指针是否会失效
    // 对于赋值，应该是新的；对于swap，迭代器是指向了旧的，不太合理，所以最好是重新定义。
    vector<int> vec_2{5, 6, 7};
    auto v_beg_2 = vec_2.begin(), v_end_2 = vec_2.end();

    vec_2 = {10, 9, 8};
    auto *p = &vec_2;
    vector<int> vec_3 = {3, 6, 9};
    swap(vec_2, vec_3);
    for(; v_beg_2 != v_end_2; ++v_beg_2)
        cout << *v_beg_2 << endl;
    cout << *(p->begin()) << endl;
    for(auto v_beg_3 = vec_2.begin(); v_beg_3 != vec_2.end(); ++v_beg_3)
        cout << *v_beg_3 << endl; 

    // string可能不同
    vector<string> svec_1(5, "Nope!");
    vector<string> svec_2(3, "Yep!");

    auto iter = ++svec_1.begin();
    cout << *iter << endl;

    swap(svec_1, svec_2);
    cout << *iter << endl;

    forward_list<int> f_list_1{1, 2, 3};
    for (auto elem : f_list_1)
        cout << elem << endl;
    cout << f_list_1.size() << endl;

}

