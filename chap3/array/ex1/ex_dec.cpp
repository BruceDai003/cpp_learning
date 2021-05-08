#include <iostream>
using namespace std;

int add(int, int);
int main(){

    int i = 3, j = 5;
    cout << "i = " << i << ", j = " << j << endl;
    int k = add(i, j);
    cout << "i + j = " << k << endl;
}
