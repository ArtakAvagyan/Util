#include "server.h"
#include "helper.h"
#include "user.h"
#include "controler.h"

#include <string>
#include <cstring>
#include <regex>

int Server::ID = 1110;
static void* serverThreadRoutine(void *arg)
    {
        int number = ++Server::ID;
        int _connfd;
        int n;
        char getLine[MAXLINE];
        int pid;
        int recvLine_len;
        std::stringstream tokenayzing;
        Control_user db;

        _connfd = *(int*)arg;
        pthread_detach(pthread_self());

        if (_connfd < 0)
        {
            std::cerr <<  "ERROR on listen";
            exit(1);
        }
        while (1)
        {
            bzero(getLine, MAXLINE);
            n = recv(_connfd, getLine, MAXLINE, 0);
            if (n < 0)
            {
                std::cerr <<  "ERROR on read";
                break;
            }

            std::string recvLine(getLine);
            tokenayzing << recvLine;
            std::string str ;
            tokenayzing >> str ;
            std::cout<< str << std::endl;
            if (str == "set")
            {
                User_t tmp;
                tokenayzing >> tmp;
                recvLine = db.addUser(tmp);
            }
            else if(str == "get")
            {
                tokenayzing >> str;
                recvLine = db.getUset(std::stoul(str)).to_string();
            }
            else if(str == "save")
            {
                recvLine = db.loadFile();
            } else {
                recvLine = "Comand not faund";
            }
            /* SERVER EKAC NAMAK  */
            recvLine += "\n\r";
            send(_connfd, recvLine.c_str(), recvLine.size(), 0);
            tokenayzing.clear();
        }

        close(_connfd);
        free(arg);
        return 0;
    }

Server::Server(std::string IP_addres , int port)
{
    static const int SERVER_PORT = port;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0)
    {
        std::cerr << "Error opening socket\n";
        std::exit(1);
    }

    bzero((char *) &servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(IP_addres.c_str()); // IPv4 address
    servAddr.sin_port = htons(SERVER_PORT);

    if (bind(listenfd, (sockaddr *) &servAddr, sizeof(servAddr)) < 0)
    {
        std::cerr << "ERROR on binding\n";
        exit(1);
    }

    std::cout << "server ip : " << inet_ntoa(servAddr.sin_addr) << std::endl;
    if (listen(listenfd, 5) < 0)
        {
            std::cerr << "ERROR on listen\n";
            exit(1);
        }
}

void Server::acceptClients()
{
    while (1)
    {
        socklen_t client_len = sizeof(cliAddr);
        connfd = (int*)malloc(sizeof(int));
        *connfd = accept(listenfd, (sockaddr *)&cliAddr, &client_len);
        if (listen(listenfd, 5) < 0)
        {
            std::cerr << "ERROR on listen\n";
            exit(1);
        }
        pthread_create(&tid, NULL, serverThreadRoutine, (void*)connfd);
    }
}
