#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

void test_word_count()
{
    // 统计每个单词在输入中出现的次数
    map<string, size_t> word_count;
    string word;
    cout << "进入统计单词出现次数的程序\n";
    while (cin >> word)
    {
        char c = getchar();
        if (c == '\n')
            break;
        ++word_count[word];
    }
    for (const auto &w: word_count)
    {
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
    }

}


void test_word_count(const set<string> &exclude)
{
    // 统计每个单词在输入中出现的次数
    map<string, size_t> word_count;
    string word;
    cout << "进入统计单词出现次数的程序（会排除一些常用词）\n";
    while (cin >> word)
        // 只统计不在exclude中的单词
        if (exclude.find(word) == exclude.end())
            ++word_count[word];

    for (const auto &w: word_count)
    {
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
    }

}

void book_multiset()
{
    // 定义一个有20个元素的vector, 保存0-9每个整数的2个拷贝
    vector<int> ivec;
    for (auto i = 0; i != 10; ++i)
    {
        ivec.push_back(i);
        ivec.push_back(i);
    }

    // 初始化set和multiset两种关联容器
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> multiset(ivec.cbegin(), ivec.cend());
    cout << ivec.size() << endl;
    cout << iset.size() << endl;
    cout << ivec.size() << endl;
    
    cout << "Print iset element\n";
    for (const auto &e : iset)
        cout << e << " ";
    cout << endl;

    cout << "Print multiset element\n";
    for (const auto &e : multiset)
        cout << e << " ";
    cout << endl;



}

using Families = map<string, vector<string>>;

auto make_families()
{
    Families families;
    for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
        for (string cn; cout << "|-Children's names:\n", cin >> cn && cn != "@q";)
            families[ln].push_back(cn);
    return families;
}

auto print(const Families &families)
{
    for (const auto &family : families)
    {
        cout << family.first << ":\n";
        for (const auto &child : family.second)
            cout << child << " ";
        cout << "\n";
    }
}

void ex_11_10()
{
    map<vector<int>::iterator, int> mv;
    map<list<int>::iterator, int> ml;

    vector<int> vi;
    vi.push_back(50);
    mv.insert(pair<vector<int>::iterator, int>(vi.begin(), 1));
    for (const auto &item : mv)
        cout << *item.first << ": " << item.second << ", ";
        //cout << item.second << ", ";
    cout << endl;

    //list<int> li;
    //ml.insert(pair<list<int>::iterator, int>(li.begin(), 3));
    //for (const auto &item : mv)
    //    cout << *item.first << ": " << item.second << ", ";
    //cout << endl;

}

void ex_11_13()
{
    vector<pair<string, int>> vec;
    string str;
    int i;

    while (cin >> str >> i)
        vec.emplace_back(str, i); // 最方便的方式
        //vec.push_back(pair<string, int>(str, i));
        //vec.push_back({str, i});
        //vcc.push_back(make_pair(str, i));

    for (const auto &p : vec)
        cout << p.first << ": " << p.second << endl;
}

void book_types()
{
    set<string>::value_type v1;
    set<string>::key_type v2;
    map<string, int>::value_type v3;
    map<string, int>::key_type v4;
    map<string, int>::mapped_type v5; // 只有map类型才有mapped_type类型
    cout << typeid(v1).name() << endl
         << typeid(v2).name() << endl
         << typeid(v3).name() << endl
         << typeid(v4).name() << endl
         << typeid(v5).name() << endl;
}

void book_find()
{
    multimap<string, string> writings{{"Bruce", "C++ tutorial"}, 
                                      {"Bruce", "python code samples"},
                                      {"Bruce", "CUDA Bible"},
                                      {"Lewis", "Java starters"},
                                      {"Bruce", "Gymnastics Workout"}};
    string search_item{"Bruce"};
    auto entries = writings.count(search_item);
    auto iter = writings.find(search_item);
    
    cout << "Bruce has written " << entries << ((entries > 1) ? " books.\n" : " book.\n");
    cout << "Searching for Bruce's writings\n";
    while (entries)
    {
        cout << iter -> second << endl;
        ++iter;
        --entries;
    }

    // 方法2， 用lower_bound()和upper_bound()方法
    cout << "使用第二种方法\n";
    for (auto beg = writings.lower_bound(search_item), end = writings.upper_bound(search_item);
         beg != end; ++beg)
        cout << beg->second << endl;

}

void ex_11_20()
{
    map<string, size_t> counts;
    for(string word; cin >> word; )
    {
        // 以下两种方式是一样的，前者比较难懂一些，后者简明一些。
        // 前者的意思是，尝试对key = word的值插入0。如果map里本来就有，就不会改变，然后在通过之后的语句+1;
        // 如果map里本来没有，插入的是0，然后通过后面的语句+1。
        ++counts.insert({word, 0}).first->second;
        //auto results = counts.insert({word, 1});
        //if (!results.second)
        //    ++results.first->second;
    }

    for(auto const &count : counts)
        cout << count.first << ": " << count.second << ((count.second > 1) ? " times\n" : " time\n");
    cout << counts["bruce"]; // 如果bruce关键字不在count中，会被插入进去，值为默认的0.
    
    cout << "now\n";
    for(auto const &count : counts)
        cout << count.first << ": " << count.second << ((count.second > 1) ? " times\n" : " time\n");
    cout << counts.at("steve"); // 使用.at()方法，如果不存在，不会直接插入，而是会跑出out of range的错误。
}

void ex_11_26()
{
    map<int, string> m{{1, "Bryant"}, {2, "Wade"}};
    using KeyType = map<int, string>::key_type;
    using MappedType = map<int, string>::mapped_type;

    cout << "Type to subscript: " << typeid(KeyType).name() << endl;
    cout << "Returned from the subscript operator: " << typeid(decltype(m[1])).name() << endl;
    cout << "Mapped type is: " << typeid(MappedType).name() << endl;
}

void book_const_map_get()
{
    const map<string, int> m{{"bruce", 3}, {"LeBron", 23}};

    // 这两种访问元素的方法都是错误的，编译都不会通过，因为不能对const map对象使用[]和at方法
    //cout << m["bruce"] << endl;
    cout << m.at("LeBron") << endl;

}

void ex_11_28()
{
    map<string, vector<int>> m{{"bruce", {1, 2, 3}}, {"lebron", {6, 23}}, {"allen", {1, 3}}};
    map<string, vector<int>>::iterator result;
    string search{"lebron"};
    result = m.find(search);
    for (const auto &item : result->second)
        cout << item << endl;

}

map<string, string> build_map(ifstream &map_file)
{
    map<string, string> trans_map;
    string key, value;
    while (map_file >> key && getline(map_file, value))
    {
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("No rule for " + key);
    }
    return trans_map;
}

const string &transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if (map_it != m.cend())
        return map_it -> second;
    else
        return s;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = build_map(map_file);
    string text;
    while (getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool first_word = true;
        while (stream >> word)
        {
            if (first_word)
                first_word = false;
            else
                cout << " ";
            cout << transform(word, trans_map);

        }
        cout << "\n";
    }
    cout << "Print trans_map\n";
    for (auto it = trans_map.cbegin(); it != trans_map.cend(); ++it)
        cout << it->first << ": " << it->second << endl;
}

void book_word_transform()
{
    ifstream map_file("map_file.txt");
    ifstream input("input.txt");
    word_transform(map_file, input);

}

int main()
{
    book_word_transform();
    //ex_11_28();
    //book_const_map_get();
    //ex_11_26();
    //ex_11_20();
    //book_find();
    //book_types();
    //ex_11_13();
    //ex_11_10();
    //print(make_families());
    //book_multiset();
    //test_word_count();
    //set<string> exclude = {"The", "the", "and", "And", "a", "A", "an", "An"};
    //test_word_count(exclude);

}
