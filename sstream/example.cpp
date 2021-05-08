#include <iostream>
#include <sstream>
#include <string>

int main()
{
// istringstream的作用的是以空格为分隔符的str对象分隔开来
	std::string str = "I am coding CPP ...";
	std::istringstream is(str);
	do
	{
		std::string substr;
		is >> substr;
		std::cout << substr << std::endl;
	} while (is);
	return 0;
}
