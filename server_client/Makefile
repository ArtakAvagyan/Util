CC		= g++ -std=c++17
THREADFLAG	= -lpthread
USER	= ./src/user.cpp
CONTROLER = ./src/controler.cpp
GET_EXE_NAME    	= -o
SERVER_MAIN_NAME  	= ./src/main-server.cpp 
CLIENT_MAIN_NAME  	= ./src/main-client.cpp
SERVER_NAME  	= ./src/server.cpp 
CLIENT_NAME  	= ./src/client.cpp
EXE_C_N		= ./bin/client
EXE_S_N		= ./bin/server

all :
	${CC} ${SERVER_MAIN_NAME}  ${SERVER_NAME} ${CONTROLER} ${USER} ${GET_EXE_NAME} ${EXE_S_N} ${THREADFLAG} 
	${CC} ${CLIENT_MAIN_NAME} ${CLIENT_NAME} ${CONTROLER} ${USER} ${GET_EXE_NAME} ${EXE_C_N} 
