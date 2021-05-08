#include <iostream>
using namespace std;

int main()
{
    int ival1 = 123;
    int &ref1 = ival1;
    // error:  declaration of reference variable 'ref2' requires an initializer 
    //int &ref2;

    int ival2 = 45;
    ref1 = ival2; // 实际也修改了ival1的值
    cout << ival1 << "\t" << ref1 << "\t" << ival2 << endl;
    cout << &ival1 << "\t" << &ref1 << "\t" << &ival2 << endl; 

    float fval1 = 3.14;
    cout << fval1  << "\t" << &fval1 << endl;

    ref1 = fval1;
    cout << ref1 << endl;

    // error: 不能定义引用的引用
    float fval2 = 2.78;
    float&& reff2 = fval2;
}
