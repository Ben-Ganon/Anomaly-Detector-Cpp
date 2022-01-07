/* Authors:
 * Ben Ganon - 318731007
 * Sagiv Antebi - 318159282
 */

#include "Server.h"
string socketIO::read(){
    char c=0;
    size_t i=0;
    string s="";
    while(c!='\n'){
        recv(clientID,&c,sizeof(char),0);
        s+=c;
    }
    return s;
}
void socketIO::write(string text){
    const char* txt=text.c_str();
    send(clientID,txt,strlen(txt),0);
}

void socketIO::write(float f){
    ostringstream ss;
    ss <<f;
    string s(ss.str());
    write(s);
}

void socketIO::read(float* f){
    recv(clientID,f,sizeof(float),0);
    // it will be already in the string line
}

void sigHandler(int sigNum) {
    //cout << "sidH" << endl;
}

Server::Server(int port)throw (const char*) {
    this->stopped = false;
    this->fd= socket(AF_INET, SOCK_STREAM, 0);
    if (this->fd < 0 )
        throw;
    this->server.sin_family = AF_INET;
    this->server.sin_addr.s_addr = INADDR_ANY;
    this->server.sin_port = htons(port);
    if (bind(this->fd, (struct sockaddr*) &this->server, sizeof(this->server)) < 0)
        throw;
    if (listen(fd, 3) < 0)
        throw;
}

void Server::start(ClientHandler& ch)throw(const char*){
    this->t = new thread([&ch, this](){
        signal(SIGALRM, sigHandler);
        while (!this->stopped) {
            alarm(1);
            socklen_t clientSize = sizeof(this->client);
            int clientOne = accept(fd, (struct sockaddr *) &this->client, &clientSize);
            if (clientOne < 0)
                throw;
            ch.handle(clientOne);
            close(clientOne);
            alarm(0);
        }
        close(this->fd);
    });
}

void Server::stop(){
    this->stopped = true;
    this->t->join();
}

Server::~Server() {
}

