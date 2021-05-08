#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>


std::string repeat(const std::string& input, size_t num)
{
    std::ostringstream os;
    std::fill_n(std::ostream_iterator<std::string>(os), num, input);
    return os.str();
}


struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;

    void print()
    {
        std::cout << "Name is " << name << std::endl;
        std::cout << "Phone numbers are:\t";
        for (auto phone : phones)
            std::cout << phone << " ";
        std::cout << "\n";
    }
};

void read_person_info()
{
    std::string line, word;
    std::vector<PersonInfo> people;
    while (getline(std::cin, line))
    {
        PersonInfo info;
        std::istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    for (auto person : people)
        person.print();

}


int main(int argc, char *argv[])
{
    // 对每个传递给程序的文件执行循环操作
    for (auto p = argv + 1; p != argv + argc; ++p)
    {
        std::ifstream input(*p); // 创建输出流并打开文件
        std::string str;
        if (input) 
        {
            std::cout << "Now openning file " << *p << std::endl;
            //std::cout << std::string(10, '=') << std::endl;
            std::cout << repeat("- ", 20) << std::endl;
            while(getline(input, str))
                std::cout << str << std::endl;
            std::cout << "Done printing file content!\n";
            std::cout << repeat("= ", 20) << std::endl;
            input.close();
        }
        else
            std::cerr << "Couldn't open: " << std::string(*p) << std::endl;

    }
    std::cout << "Print person info\n";
    read_person_info();

}
