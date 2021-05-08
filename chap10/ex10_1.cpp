#include <iostream>
#include <algorithm>
#include <numeric>
#include <forward_list>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <functional>

using namespace std;
using namespace std::placeholders;

// helper function
template <typename Sequence>
void print(const Sequence& seq, const typename Sequence::iterator& iter_end=typename Sequence::iterator(nullptr))
{
    if (iter_end == typename Sequence::iterator(nullptr))
    {
        for (const auto& item : seq)
            cout << item << " ";
        cout << endl;
    }
    else
    {
        for (auto it=seq.begin(); it != iter_end; ++it)
            cout << *it << " ";
        cout << endl;
    }
}

void test_find()
{
    // forward_list of int
    forward_list<int> vec{3, 15, 99, 45, 42, 55};
    int val = 42;
    auto result = find(vec.cbegin(), vec.cend(), val);
    cout << "The value " << val
         << (result == vec.cend() ? " can't be find." : " has been found!") << endl;

    // built-in array
    int arr[] = {3, 15, 99, 45, 42, 55};
    int val_2 = 42;
    int* result_2 = find(begin(arr), end(arr), val_2);
    cout << "The value " << val_2
         << (result_2 == end(arr) ? " can't be find." : " has been found!") << endl;
    
    // string
    deque<string> deq{"What", "Needs", "To", "Be", "Done?"};
    string str{"Be"};
    auto result_3 = find(deq.cbegin(), --deq.cend(), str);
    cout << "The value " << str
         << (result_3 == --deq.cend() ? " can't be find!" : " has been found!") << endl;    
}


void test_count()
{
    cout << "测试count函数\n";
    cout << " = = = = = = = = = = \n";
    vector<int> vec;
    int i;
    while(cin >> i)
        vec.push_back(i);
    for (auto el : vec)
        cout << el << " ";
    cout << "\n";

    int to_match{5}, counter{0};
    counter = count(vec.cbegin(), vec.cend(), i);
    cout << "In this vector, count(" << to_match
         << ") = " << counter << endl;

    int accum{0};
    accum = accumulate(vec.cbegin(), vec.cend(), accum);
    cout << "The sum = " << accum << endl;

}

void test_equal()
{
    vector<string> vec_1{"Nice", "to", "meet", "you"};
    list<string> list_1;
    list_1.assign(vec_1.cbegin(), vec_1.cend());
    list_1.push_back("!");
    for (auto item : list_1)
        cout << item << " ";
    cout << endl;

    bool isEqual;
    isEqual = equal(list_1.cbegin(), list_1.cend(), vec_1.cbegin());

    cout << (isEqual ? "vec_1 和 list_1 元素一样\n" : "vec_1 和 list_1 元素不同\n");
}

void test_fill()
{
    vector<int> vec;
    for (auto i{0}; i < 10; ++i)
        vec.push_back(i);
    for (auto item : vec)
        cout << item << " ";
    cout << endl;

    fill(vec.begin(), vec.begin() + vec.size() / 2, 100);

    cout << "使用fill()函数，将前一半数据填充为100之后\n";
    for (auto item : vec)
        cout << item << " ";
    cout << endl;
    
    fill_n(vec.begin() + vec.size() / 2, vec.size() / 2, -999);
    cout << "再使用fill_n()函数将后面一半数据修改为-999之后\n";
    for (auto item : vec)
        cout << item << " ";
    cout << endl;
    
    // 一个错误示例，不能对一个空的容器，使用fill_n
    vector<float> vec_2;
    //fill_n(vec_2.begin(), 5, 3);
    // 可以修改成使用back_inserter的插入迭代器来填充数据
    //auto it = back_inserter(vec_2);
    fill_n(back_inserter(vec_2), 5, 3);

    cout << "使用插入迭代器来fill_n一个空的容器\n";
    for (auto item : vec_2)
        cout << item << " ";
    cout << endl;
}

void test_copy()
{
    int a_1[] = {0, 1, 2, 3};
    int a_2[sizeof(a_1) / sizeof(*a_1)]; // a_2与a_1大小一样
    // ret 指向拷贝到a_2的尾元素之后的位置
    auto ret = copy(begin(a_1), end(a_1), a_2);
    for (auto item : a_2)
        cout << item << " ";
    cout << endl;
    cout << ret << endl;
    cout << a_2 << " " << begin(a_2) << " "<< &a_2[1] << " " << end(a_2) << endl;
    cout << (ret == end(a_2)) << endl;

    // 2. 调用replace
    replace(begin(a_1), end(a_1), 0, 37);
    cout << "使用replace\n";
    for (auto item : a_1)
        cout << item << " ";
    cout << endl;

    // 3. 调用replace_copy，不会改变原序列，replace后保存到一个新的容器里
    deque<int> deq_1{100, 101, 102, 103, 104};
    auto it = back_inserter(deq_1);
    *it = 99;
    
    // 从后往前替换deq_1中的数据
    replace_copy(begin(a_1), end(a_1), deq_1.rbegin(), 1, 999);
    cout << "使用replace_copy\n";
    cout << "a_1的数据应该不会改变：\n";
    for (const auto &item : a_1)
        cout << item << " ";
    cout << endl;

    cout << "deq_1的数据如下：\n";
    for (const auto &item : deq_1)
        cout << item << " ";
    cout << endl;
}

void ex_10_6()
{
    // 10.6 编写程序，使用fill_n将一个序列中的int值都设置为0。
    vector<int> vec{1, 2, 3, 4, 5};
    fill_n(vec.begin(), vec.size(), 0);
    print(vec);

    // 10.7 第二个片段
    vector<int> vec_2;
    vec_2.resize(10);
    fill_n(vec_2.begin(), 10, 0);
    print(vec_2);
}

void elimDups(vector<string> &words)
{
    // 1. sort
    sort(words.begin(), words.end());
    // 2. unique去重
    auto end_unique = unique(words.begin(), words.end());
    // 3. 使用向量操作erase删除重复单词
    words.erase(end_unique, words.end());

}

bool hasMoreElements(const string &word)
{
    return word.size() >= 5;
}

void test_elimDups()
{
    vector<string> story = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    cout << "调用去重程序前, story序列中存储的数据为:\n";
    print(story);
    elimDups(story);
    cout << "调用后, story序列中存储的数据为:\n";
    print(story);

    // 调用partition算法
    //auto it = partition(story.begin(), story.end(), hasMoreElements); 
    // 使用lambda表达式
    vector<string>::size_type sz = 5;
    auto it = partition(story.begin(), story.end(), [sz](const string& s)->bool{return s.size() >= sz;}); 

    cout << "调用partition后:\n";
    print(story, it);

}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words); // 按字典序排序，删除重复单词
    // 按长度排序，长度相同的维持字典序
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b)->bool{return a.size() < b.size();});
    // 获取一个迭代器，指向第一个满足size() >= sz的元素
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a){return a.size() >= sz;});
    // 计算满足size >= sz的元素数目
    //auto count = words.end() - wc;

    // 采用count_if来统计有多少单词长度超过sz的
    auto count = count_if(words.begin(), words.end(), [sz](const string &a)->bool{return a.size() >= sz;});
    cout << count << " " << (count > 1 ? "words" : "word") << " of length " << sz << " or longer" << endl;

    // 打印长度大于等于sz的单词
    for_each(wc, words.end(), [](const string &a){cout << a << " ";});
    cout << endl;

}

void test_biggies()
{
    vector<string> story = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    cout << "调用去重程序前, story序列中存储的数据为:\n";
    print(story);
    
    decltype(story.size()) sz = 5;
    cout << "调用自定义函数，找出其中单词长度大于等于" << sz << "的单词" << endl;
    biggies(story, sz); 

}

void ex_10_14()
{
    int a = 10, b = 5;
    auto f = [](const int &x, const int &y)->int{return x+y;};
    cout << a << " + " << b << " = " << f(a, b) << endl;
}

bool check_size(const int &item, const size_t &sz)
{
    return item > sz;
}

void ex_10_24()
{
    // 给定一个string, 使用bind和check_size在一个int的vector中查找第一个大于string长度的值。
    string s{"Antektokunpo"};
    vector<int> vec{3, 6, 1, 3, 8, 5, 12, 9, 16, 5};
    auto pivot = find_if(vec.begin(), vec.end(), bind(check_size, _1, s.size()));
    if (pivot != vec.end())
        cout << "第一个超过" << s << "长度的数字是" << *pivot << endl;
    else
        cout << "找不到满足条件的数字\n";


}

void test_iostream()
{
    cout << "输入一组整型数据\n";
    istream_iterator<int> in(cin), eof;
    cout << "它们的和 = ";
    cout << accumulate(in, eof, 0) << endl;

    // 2. 测试ostream
    vector<string> vec{"what", "a", "bitch"};
    ostream_iterator<string> out_iter(cout, " ");
    for (auto e: vec)
        *out_iter++ = e; // 赋值语句实际上将元素写到cout
    cout << endl;
    
    // 3. 也可以用如下的形式来写，因为*out_iter, out_iter++, ++out_iter实际上不对out做任何事情
    ostream_iterator<string> out_iter_2(cout, " ");
    for (auto e: vec)
        out_iter_2 = e; // 赋值语句实际上将元素写到cout
    cout << endl;

    // 4. 用copy算法
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;

}

void test_reverse_iterator()
{
    string line = "nice, to, meet, you. Do, you, think, this, is, good?";
    // 1. 查找第一个元素
    auto comma = find(line.cbegin(), line.cend(), ',');
    cout << string(line.cbegin(), comma) << endl;

    // 2. 查找最后一个元素
    auto rcomma = find(line.crbegin(), line.crend(), ',');
    cout << string(rcomma.base(), line.cend()) << endl;
}

void ex_10_36()
{
    // 使用find在一个int的list中查找最后一个值为0的元素
    list<int> rate{2, 0, 4, 3, 1, 0, 0, 2, 5, 0, 1, 3};
    auto index = find(rate.crbegin(), rate.crend(), 0);
    if (index != rate.rbegin())
        cout << "We found the last 0 at index = " << distance(index, rate.crend()) << endl;
    else
        cout << "No zero at all" << endl;
}

void ex_10_37()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> ret_lst(5);

    copy(vec.cbegin()+3, vec.cbegin()+8, ret_lst.rbegin());
    print(ret_lst);

}


int main()
{
    ex_10_37();
    //ex_10_36();
    //test_reverse_iterator();
    //test_iostream();
    //ex_10_24();
    //ex_10_14();
    //test_biggies();
    //test_elimDups();
    //ex_10_6();
    //test_copy();
    //test_fill();
    //test_equal();
    //test_count();
    //test_find();
}
