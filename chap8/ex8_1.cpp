#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


istream& print(istream& input)
{
    string word;
    while ( input >> word)
    {
        cout << word << endl;    
    }
    input.clear();
    return input;
}

int main(int argc, char *argv[])
{
    istream& is = print(cin); 
    cout << is.rdstate() << endl;
    cout << "Finished, bro!" << endl;
    return 0;
}
