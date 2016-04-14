#include <iostream>
#include "Server.hpp"
#include "Exercice.hpp"
 
using namespace std;

Server::Server(int port):_socketServer(),_port(port),_clients(),_mutex(),_server_addr(),_size(){
    _socketServer = socket(AF_INET, SOCK_STREAM, 0);

    if( _socketServer < 0 ){
        cerr << "Error establishing socket..." << endl;
        exit(1);
    }

    _server_addr.sin_family = AF_INET;
    _server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    _server_addr.sin_port = htons(port);
}

void Server::start(){
    if ((bind(_socketServer, (struct sockaddr*)&_server_addr,sizeof(_server_addr))) < 0){
        cerr << "Error binding connection, the socket has already been established..." << endl;
        exit(1);
    }

    if( listen(_socketServer, 0) == -1){
        cerr << strerror(errno) << endl;
        exit(1);
    }

    _size = sizeof(_server_addr);


    thread thr(&Server::acceptClient, this );
    thr.join();
}

void Server::acceptClient(){
    int fd;
    while(true){
        fd = accept(_socketServer, (struct sockaddr *)&_server_addr,&_size);

        send(fd, "Connection established\n", sizeof("Connection established\n"), 0);

        _mutex.lock();
        _clients.push_back( fd );
        _mutex.unlock();
    }
}

void Server::sendToClient(){
    _mutex.lock();

    for(vector<int>::iterator it = _clients.begin() ; it < _clients.end(); it++ ) {
        cout<< *it << endl; 
    }

    _mutex.unlock();
}

int main(void){
    //Exercice *ex = new Exercice("/home/yann/CPP/AlgebraTutor/exercices");

    cout << sendExercice("/home/yann/CPP/AlgebraTutor/exercices/test.txt") <<endl;
   /* string path;
    Server *server = new Server(8080);

    server->start();


    cout << "Path of file to send at students?" << endl;
    cin >> path;
    cout << path << endl;*/

    return 0;
}