/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

template <class T>
class myContainer
{
    private:
        T element;
    public:
        myContainer(T arg){element = arg;}
        T increase()
        {
            return ++element;
        }
};

template<>
class myContainer<char>
{
    private:
        char element;
    public:
    myContainer(char arg){element = arg;}
    char increase()
    {
        return ++element;
    }
    char uppercase()
    {
        if (element >= 'a' && element <= 'z')
            element += 'A' - 'a';
        return element;
        
    }
};

int main()
{
    int i = 5;
    myContainer<int> cont1 (i);
    cout << "i = " << i << ", increased to " << cont1.increase() << endl;
    
    char c = 'k';
    myContainer<char> cont2 (c);
    cout << c << ", increased to " << cont2.increase()
         <<", upper case is " << cont2.uppercase() << endl;
    return 0;
}


