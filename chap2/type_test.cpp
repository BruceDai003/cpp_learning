#include <typeinfo>
#include <iostream>
using namespace std;

#include <string>
using std::string;
#include <cctype>

#include <vector>
using std::vector;

#include <iterator>

double sum(double a, double b)
{
    return a + b;
}

int main()
{
    // 数组
    int ia[] = {100, 110, 120, 130};
    auto ia2(ia);
    cout << *ia2+3 << endl;

    decltype(ia) ia3 = {0, 5};
    for (auto i : ia3)
        cout << i << endl;
    cout << sizeof(ia3) / sizeof(ia3[0]) << endl;

    int *beg = begin(ia);
    int *last = end(ia);
    cout << *beg << ", " << *--last << endl;
    // 迭代器
    //string s("what do you");
    //if (s.begin() != s.end())
    //{
    //    auto it = s.begin();
    //    *it = std::toupper(*it);
    //}
    //cout << s << endl;

    ////for (auto it = s.begin(); it != s.end() && !isspace(*it); it++)
    //for (string::iterator it = s.begin(); it != s.end() && !isspace(*it); it++)
    //{
    //   *it = toupper(*it); 
    //}
    //cout << s << endl;

    // 容器
    //vector<unsigned> scores(11, 0);
    //unsigned grade;
    //while (cin >> grade)
    //{
    //    if (grade <= 100)
    //        ++scores[grade / 10];
    //}
    //for (auto s:scores)
    //    cout << s << " ";

    //vector<string> v2;
    //for (int i = 0; i < 10; ++i)
    //    v2.push_back(std::to_string(i));
    ////for (decltype(v2.size()) index = 0; index != v2.size(); ++index)
    //for (vector<string>::size_type index = 0; index != v2.size(); ++index)
    //    cout << std::stoi(v2[index]) << endl;
    //for (auto i: v2)
    //    cout << i << ",";

    //vector<string> svec(10, "Hello!");
    //for (auto s: svec)
    //{
    //    cout << s << endl;
    //}

    //const string s= "Keep out!";
    //for (auto &c : s) { cout << c << typeid(c).name() << endl;}

    //string s;
    //getline(cin, s);

    //for(auto &c: s)
    //{
    //    if (ispunct(c))
    //        c = ' ';
    //}

    //string s;
    //getline(cin, s);
    //cout << "Original s = " << s << endl;

    //// while循环
    //auto index = s.size();
    //while(index != 0)
    //{
    //    s[--index] = 'X';
    //}

    // 传统的for循环
    //for(decltype(s.size()) index = 0; index != s.size(); ++index)
    //    s[index] = 'X';

    //for(char &c: s)
    //    c = 'X';
    //cout << s << endl;
    //const string hexdigits = "0123456789ABCDEF";
    //cout << "Enter a series of numbers between 0 and 15"
    //     << " seperated by spaces. Hit ENTER when finished."
    //     << endl;

    //string result;
    //decltype(hexdigits.size()) n;
    ////string::size_type n;

    //while (cin >> n)
    //    if (n < hexdigits.size())
    //        result += hexdigits[n];

    //cout << "Your hex number is " << result << endl;
    //string s1;
    //getline(cin, s1);

    //for (decltype(s1.size()) index = 0; index != s1.size() && !isspace(s1[index]); ++index)
    //    s1[index] = toupper(s1[index]);

    //cout << s1 << endl; 



    //typedef char *pstring;
    //char x = '5';
    //pstring y = &x;
    //*y = 'm';
    //cout << "x = " << x << endl;
    //const pstring cstr = 0;
    //cstr = &x;

    //char x;
    //const char *p = &x;
    //x = '5';
    //*const_cast<char *>(p) = 'm';
    //cout << *p << endl;
    //const int *p = nullptr;
    //constexpr int *q = nullptr;
    //cout << typeid(p).name() << endl;
    //cout << typeid(q).name() << endl;
    //int y = 5;
    //p = &y;
    //q = &y;

    //const int v2 = 55;
    //int v1 = v2;
    //int *p1 = &v1, &r1 = v1;
    //const int *p2 = &v2, *const p3 = &v1, &r2 = v2;

    //r1 = v2;
    //cout << r1 << endl;
    ////p1 = p2;
    ////p2 = p1;

    ////p1 = p3;
    ////p2 = p3;
    //cout << v1 << endl;
    //r1 = 99;
    //cout << v1 << *p2 << *p3 << endl;
    
    //const int *p;
    //cout << p << "\t" << *p << endl;
    //float pi = 3.14;
    //float *const ptr = &pi;
    //const float e = 2.78;
    //*ptr = 9.99;
    //cout << *ptr << endl;
    //cout << pi << endl;
    //cout << "Address:\t" << &pi << "\t" << &ptr << "\t" << &e << endl;
    //cout << "size:\t" << sizeof(float) << "\t" << sizeof(int) << "\t" << sizeof(double) << endl;

    //const int i = -1, &r = , &r = 0;



    //const int bufsize = 512;
    //cout << "bufsize = " << bufsize << endl;
    //cout << "type(bufsize) = " << typeid(bufsize).name() << endl;

    //int i = 42;
    //const int &r1 = i;
    //i = 50;
    //cout << "r1 = " << r1 << endl;

    //int &r4 = i * 2; // Illegal, the rhs will generate a tmp const variable, can't bind a non-const to it.

	//typedef double wages;
	//using salary = double;
	//salary *monthly = nullptr;
	//wages hourly = 3.0, daily = hourly * 8, weekly = daily * 5;
	//monthly = &weekly; 
	//cout << "type(hourly) = " << typeid(hourly).name() << endl;
	////cout << wages << endl;
	//cout << "wages: hourly = " << hourly << ", daily = " << daily
	//     << ", weekly = " << weekly << endl;
	//cout << "wages: monthly = " << *monthly << endl;
    //cout << "Address checking:\t" << monthly << "\t" << &weekly << endl;
	return 0;
}
