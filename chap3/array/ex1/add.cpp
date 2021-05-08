#include <iostream>
using namespace std;

int add(int, int);

int add(int x, int y)
{
    return x + y;
}

int main1()
{
    int x = 10, &y = x, z = add(x, y);
    cout << "10 + 10 = " << z << endl;
}
