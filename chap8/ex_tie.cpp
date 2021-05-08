// Redefine tied object
#include <iostream>
#include <fstream>

int main()
{
    std::ostream *prevstr;
    std::ofstream ofs;

    //std::cout << prevstr->rdstate() << std::endl;
    std::cout << ofs.rdstate() << std::endl;

    //ofs.open("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    ofs.open("test.txt", std::fstream::out);

    //std::cout << prevstr->rdstate() << std::endl;
    std::cout << ofs.rdstate() << std::endl;
    std::cout << "tie example\n";

    *std::cin.tie() << "This is inserted into cout\n";
    prevstr = std::cin.tie(&ofs);
    *std::cin.tie() << "This is inserted into the file\n";
    std::cin.tie(prevstr);
    *prevstr << " Another sentence printed from cout\n";
    ofs << "Direct output to file\n";
    std::cout << prevstr->rdstate() << std::endl;
    std::cout << ofs.rdstate() << std::endl;
    return 0;
}
