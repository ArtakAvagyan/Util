#include "server.h"

#include <string>

extern std::pair<std::string, int> connection();

int main(int argc,char* argv[])
{
	if(argc < 2)
	{
		std::cout<< "Invalid Arguments" << std::endl;
		return 1;
	}
    Server socket (argv[1], std::stoi(argv[2]));
    socket.acceptClients();
    
    return 0;
}