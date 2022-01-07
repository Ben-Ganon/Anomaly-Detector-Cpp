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
    //recv(clientID,f,sizeof(float),0);
    // it will be already in the string line
}

Server::Server(int port)throw (const char*) {

}

void Server::start(ClientHandler& ch)throw(const char*){	
}

void Server::stop(){
	t->join(); // do not delete this!
}

Server::~Server() {
}

