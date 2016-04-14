#ifndef __SERVER_HPP__
#define __SERVER_HPP__

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <thread>
#include <vector>
#include <mutex>
 
using namespace std;

class Server{
	private:
		int _socketServer;
		int _port;
		vector<int> _clients;
		mutex _mutex;
		//bool isExit = false;
		//int bufsize = 1024;
		//char buffer[bufsize];
		 
		struct sockaddr_in _server_addr;
		socklen_t _size;
	public:
		Server(int port);
		~Server();
		void start();
		void acceptClient();	
		void sendToClient();
};
#endif