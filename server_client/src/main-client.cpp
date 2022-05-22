#include "client.h"

#include <string>
#include <iostream>

int main(int argc,char*argv[])
{
	if(argc < 2)
	{
		std::cout<< "Invalid Arguments" << std::endl;
		return 1;
	}
	Client socket(argv[1], std::stoi(argv[2]));
	std::string str;
	while (str != "disconnect")
	{
		std::cout << "$ ";
		std::getline(std::cin, str);
		if(str == "")
		{
			continue;
		}
		else if (str == "clear")
		{
			std::system("clear");
			continue;
		}
        socket.sendAndRecv(str);
	}

	return 0;
}