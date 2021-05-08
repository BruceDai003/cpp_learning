#include <iostream>
#include <vector>
#include <memory>
#include <exception>
#include <string>
#include <initializer_list>

using namespace std;

class StrBlob
{
    public:
        typedef vector<string>::size_type size_type;
        StrBlob();
        StrBlob(initializer_list<string> il);
        size_type size() const { return data->size();}
        bool empty() const { return data->empty();}
        // 添加和删除元素
        void push_back(const string &t) { data->push_back(t);}
        void pop_back();
        // 元素访问
        string &front();
        string &back();
        const string &front() const 
        { 
            check(0, "front on empty StrBlob");
            return data->front();
        }
        
        const string &back() const
        {
            check(0, "back on empty StrBlob");
            return data->back();
        }

    private:
        shared_ptr<vector<string>> data;
        // 如果data[i]不合法，抛出一个异常
        void check(size_type i, const string &msg) const;
};

// 构造函数
StrBlob::StrBlob(): data(make_shared<vector<string>>()){ }
StrBlob::StrBlob(initializer_list<string> il):
    data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

string &StrBlob::front()
{
    // 如果vector为空，check会抛出一个异常
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

void ex_12_2()
{
    const StrBlob csb{"hello", "world", "bruce"};
    StrBlob sb{"hello", "Liwei", "Dai"};

    cout << csb.front() << " " << csb.back() << endl;
    sb.back() = "!";
    cout << sb.front() << " " << sb.back() << endl;
}

void book_init()
{
    shared_ptr<string> p1;
    shared_ptr<vector<int>> p2;

    if (p1 && p1 -> empty())
    {    
        *p1 = "bravo";
        cout << *p1 << endl;
    }
    else
        cout << "empty" << endl;
    string s= "cheeta";
    *p1 = s;
    //cout << *p1 << endl;
}

void book_init2()
{
    shared_ptr<int> p3 = make_shared<int>(42);
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    shared_ptr<int> p5 = make_shared<int>(); // 默认初始化int，即0
    
    cout << *p3 << endl
         << *p4 << endl
         << *p5 << endl;

    // 我们通常用auto定义对象保存make_shared的结果，这种方式较为简单
    auto p6 = make_shared<vector<string>>(10, "Bruce");
    for (const auto &item : *p6)
        cout << item << endl;
}

void book_shared_ptr_copy()
{
    auto p = make_shared<int>(42);
    auto q(p);

}

void book_new_delete()
{
    // pi指向一个动态分配的、未初始化的无名对象
    int *pi = new int;
    string *ps = new string; // 初始化为空string
    int *pi_2 = new int(1024); // 直接初始化，传统的构造方式
    string *ps_2 = new string(10, '8'); // 直接初始化，列表初始化方式*ps_2为"8888888888"

    vector<int> *pv = new vector<int>{0, 1, 2, 3, 4}; // 列表初始化
    
    // 也可以使用值初始化的方式
    string *ps_3 = new string; // 默认初始化为空string
    string *ps_4 = new string(); // 值初始化为空string

    // 因为int是一种内置类型，在函数内，默认初始化时，值是未定义的，危险的
    int *pi_3 = new int; // 默认初始化，*pi_3的值未定义
    int *pi_4 = new int(); // 值初始化为0；*pi_4为0

    // 可以使用auto，但是只有括号中仅有单一初始化器时才可以使用auto
    auto p1 = new auto(obj);
    auto p2 = new auto{a, b, c};


}

int main()
{
    book_new_delete();
    //ex_12_2();
    //book_shared_ptr_copy();
    //book_init2();
    //book_init();

}
