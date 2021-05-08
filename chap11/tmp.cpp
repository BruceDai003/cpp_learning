#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int &d=a;
    int &e=b;
    int &f=c;
    int t;
    if(d>e)t=d;d=e;e=t;
    if(d>f)t=d;d=f;f=e;
//    cout<<a<<b<<c<<endl<<d<<e<<f<<endl;
    if(e>f)
        {t=e;e=f;f=t;}
    cout<<a<<b<<c<<endl<<d<<e<<f<<endl;
    return 0;
}
