#include "../../libs/args.hpp"
#include <iostream>

int main()
{
	Arguments args;
	args.push(Argument(100));
	args.push(Argument("George"));
	args.push(Argument(5.01f));
	
	std::cout << "Param[1]: " << args[0].Int() << std::endl;
	std::cout << "Param[2]: " << args[1].Str() << std::endl;
	std::cout << "Param[3]: " << args[2].Float() << std::endl;
	args.clear();

	system("pause");
	return 1;
}