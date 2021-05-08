#include <vector>
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string str("I am coding CPP ...");
    std::string buf;
    std::stringstream ss(str);
    std::vector<std::string> vec;
    while (ss >> buf)
        vec.push_back(buf);
    for (std::vector<std::string>::iterator iter = vec.begin();
    iter != vec.end(); ++iter)
    {
        std::cout << *iter << std::endl;
    }
    
}

