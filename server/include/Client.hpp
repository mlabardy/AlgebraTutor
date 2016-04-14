#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>


using namespace std;

class Client{
	private:
		int _socketClient;
		int _port;
		string _address;

		struct sockaddr_in _server_addr;
	public:
		Client(int port, string address);
		~Client();
		void start();
		string receive();
		void sendToServer(string result);
};


#endif