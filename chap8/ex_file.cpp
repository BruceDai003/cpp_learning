#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // 从标准流读取字符串，写入文件
    std::ofstream my_file("output.txt");
    std::string my_string;
    if (my_file.is_open())
    {
        while(getline(std::cin, my_string))
         {
             my_file << my_string << std::endl;
         }
         std::cout << "Done!\n";
    }
    else
        std::cout << "Failed to open the file!" << std::endl;
    my_file.close();
    std::cout << my_file.is_open() << std::endl;

}
