#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <deque>
#include <forward_list>

using namespace std;


void ex_9_26()
{
    cout << "Exercise 9.26\n";
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vec_2(ia, end(ia));
    auto it = vec_2.begin();
    while( it != vec_2.end())
    {
        //if (*it % 2)
        if (*it & 0x1)
            ++it;
        else
            it = vec_2.erase(it);
    }
    cout << "Print vec_2 items" << endl;
    for (auto const& item: vec_2)
        cout << item << endl;

    
}

void ex_9_27()
{
    // 查找并删除forward_list<int>中的奇数元素
    cout << "Exercise 9.27\n";
    forward_list<int> flst_1{0, 1, 1, 3, 4, 7, 8, 12, 34, 75, 94};
    cout << "Before algo, print forward list elements\n";
    for (auto el : flst_1)
        cout << el << " ";
    cout << "\n";
    auto prev = flst_1.before_begin();
    auto curr = flst_1.begin();
    while (curr != flst_1.end())
    {
        if (*curr % 2) // 如果是奇数元素
            curr = flst_1.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }

    }
    cout << "After algo, print forward list elements\n";
    for (auto el : flst_1)
        cout << el << " ";
    cout << "\n";


}



void find_and_insert(forward_list<string> &fl, string s1, string s2)
{
    auto prev = fl.before_begin();
    forward_list<string>::iterator it = fl.begin();
    while ( it != fl.end())
    {
        if ( *it == s1)
        {
            // 在it之后插入s2
            it = fl.insert_after(it, s2);
            return;
        }
        else
        {
            ++it;
            ++prev; // 因为如果找不到s1，需要用prev在最后插入s2
        }
    }
    cout << "Didn't find the string " << "\"" << s2 << "\""
         << ", so insert at the end.\n";
    fl.insert_after(prev, s2);

}

void ex_9_28()
{
    cout << "Exercise 9.28: forward list: find and insert after\n";
    forward_list<string> flst{"This", "is", "not", "what", "I", "want"};
    string look_up = "not";
    string to_insert = "like";
    find_and_insert(flst, look_up, to_insert);
    for (auto el : flst)
        cout << el << " ";
    cout << "\n";
    cout << " = = = = = = = = = =\n";

    // 另一个例子
    look_up = "yes";
    find_and_insert(flst, look_up, to_insert);
    for (auto el : flst)
        cout << el << " ";
    cout << "\n";
    cout << " = = = = = = = = = =\n";
    

}

void rm_even_cp_odd()
{
    // 删除偶数元素，复制奇数元素
    cout << "删除偶数元素，复制奇数元素( 0 - 9)\n";
    vector<int> vi;
    for (int i = 0; i < 10; ++i)
        vi.push_back(i);

    auto it = vi.begin();
    while( it != vi.end())
    {
        if( *it % 2)
        {
            it = vi.insert(it, *it);
            it += 2;
        }
        else
            it = vi.erase(it);
    }

    // 打印看看结果
    for (auto it = vi.cbegin(); it != vi.cend(); ++it)
        cout << *it << " ";
    cout << "\n = = = = = = = = = \n";
}
    
void bad_end()
{
    cout << "不要保存容器的end()迭代器，否则会core dumped\n";
    vector<int> vi{0, 1, 2};
    auto begin = vi.begin(), end = vi.end();
    while (begin != end)
    {
        ++begin;
        begin = vi.insert(begin, 42);
        ++begin;
    }
}


void test_list_insert()
{
    list<int> my_list;
    list<int>::const_iterator it;

    // Set some initial values
    for (int i = 1; i <= 5; ++i) my_list.push_back(i); // 1, 2, 3, 4, 5

    it = my_list.begin();
    ++it; // it points to number 2

    my_list.insert(it, 10); // 1 10 2 3 4 5
    my_list.insert(it, 2, 20); // 1 10 20 20 2 3 4 5
    --it;

    vector<int> my_vector(2, 30);
    my_list.insert(it, my_vector.cbegin(), my_vector.cend()); // 1 10 20 30 30 20 2 3 4 5

    cout << "Now my_list contains\n";
    for (it = my_list.cbegin(); it != my_list.cend(); ++it)
        cout << *it << " ";
    cout << "\n = = = = = = = \n";
    

}

void ex_9_33()
{
    // list是一个循环链表，当迭代器到达v.end()之后，再++会从v.begin()位置开始
    list<int> v{1, 2, 3, 4, 5};
    auto begin = v.begin();
    while (begin != v.end())
    {
        ++begin;
        /*begin = */v.insert(begin, 42);
        ++begin;
        cout << v.size() << endl;
    }

    for (auto i : v)
        cout << i << " ";
}

void test_size_capacity()
{
    vector<int> ivec;
    cout << "ivec size = " << ivec.size()
         << ", capacity = " << ivec.capacity() << endl;

    for (auto ix = 0; ix != 48; ++ix)
    {
        ivec.push_back(ix);

        cout << "ivec size = " << ivec.size()
             << ", capacity = " << ivec.capacity() << endl;
        if (ix == 18)
            ivec.reserve(43);
        if (ix == 30)
            ivec.shrink_to_fit();
    }
}

int main()
{
    test_size_capacity();
/*    ex_9_33();
    test_list_insert();
    bad_end();
    ex_9_26();
    ex_9_27();
    ex_9_28();
    rm_even_cp_odd();

    vector<int> vec_1{1, 5, 9};
    cout << vec_1.at(0) << endl
         << vec_1[0] << endl
         << vec_1.front() << endl
         << *vec_1.begin() << endl
         << *vec_1.cbegin() << endl
         << vec_1.size() << endl
         << vec_1.capacity() << endl;

    vec_1.clear();
    cout << "Now vec_1 has been cleared" << endl;
    
    // 使用at()运算符是最安全的做法，因为会刨除一个out_of_range异常，此时其他的根本不会报错！！！
    //cout << vec_1.at(0) << endl
    cout << vec_1[0] << endl
         << vec_1.front() << endl
         << *vec_1.begin() << endl
         << *vec_1.cbegin() << endl
         << vec_1.size() << endl
         << vec_1.capacity() << endl;

    // Case 2. 如果是一个空的容器，也会是同样情况
    deque<string> deq_1;
    //cout << deq_1.at(0) << endl
        cout << deq_1[0] << endl
         << deq_1.front() << endl
         << *deq_1.begin() << endl
         << *deq_1.cbegin() << endl
         << deq_1.size() << endl;


    list<int> li_1;
    for (int i = 0; i < 10; ++i)
        li_1.push_back(i);

    auto it = li_1.begin();
    while (it != li_1.end())
    {
        if(*it % 2)
            it = li_1.erase(it);
        else
            ++it;
    }

    for (auto item : li_1)
        cout << item << "\t";
    */
}
