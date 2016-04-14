#include <iostream>
#include "Client.hpp"
#include "Exercice.hpp"

using namespace std;
 
Client::Client(int port, string address):_socketClient(),_port(port),_address(address),_server_addr(){
    _socketClient = socket(AF_INET, SOCK_STREAM, 0);

    if( _socketClient < 0 ){
        cerr << "Error establishing socket..." << endl;
        exit(EXIT_FAILURE);
    }

    _server_addr.sin_family = AF_INET;
    _server_addr.sin_port = htons(port);
}

void Client::start(){
	if( connect( _socketClient ,(struct sockaddr *)&_server_addr, sizeof(_server_addr)) == -1 ){
		cerr << "Connection failed to server\n" << endl;
		exit(EXIT_FAILURE);
	}
}

string Client::receive(){
	char sizeOfMessage[sizeof(long)];

	recv( _socketClient , sizeOfMessage , sizeof(long), 0);

	long size = stoi(sizeOfMessage);
 	char *exo = (char*) malloc(size);

 	recv( _socketClient , exo , size, 0);

 	string str(exo);

 	return str;
}

void Client::sendToServer(string result){
	if( send( _socketClient ,result.c_str(), sizeof(result.c_str()), 0) == -1){
		cerr << "Fail the sending to server\n" << endl;
		exit(EXIT_FAILURE);
	}
}


int main( int argc, const char* argv[] ){
	if( argc != 3 ){
		cerr << "Command for launch the client: ./client SERVER_IP SERVER_PORT" << endl;
		exit(EXIT_FAILURE);
	}

	string address(argv[1]);

	Client *client = new Client( atoi(argv[2]) ,address);

	client->start();

	string exo = client->receive();

	prepareHomework( "./exercice.txt", exo );

 	cout << "Resolve this exercice:" << endl;
 	cout << exo << endl;
 	
 	string submit = "";

 	do{
 		cout << "Write \"finish\" when you should submit your answer" << endl;
 		cin >> submit;
 	}while( submit.find("finish") == string::npos );

 	client->sendToServer( sendExercice("./exercice.txt") );

 	exo = client->receive();

 	cout << "The expected solution:" << endl;
 	cout << exo << endl;

    return 0;
}