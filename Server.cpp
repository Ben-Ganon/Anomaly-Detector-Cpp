/* Authors:
 * Ben Ganon - 318731007
 * Sagiv Antebi - 318159282
 */
#include "Server.h"

Server::Server(int port)throw (const char*) {

}

void Server::start(ClientHandler& ch)throw(const char*){	
}

void Server::stop(){
	t->join(); // do not delete this!
}

Server::~Server() {
}

