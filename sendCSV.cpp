//
// Created by ben on 13/12/2021.
//

#include "sendCSV.h"
#include <fstream>

sendCSV::sendCSV(string path, DefaultIO *io) : Command(nullptr) {
    this->path = path;
    this->io = io;

}
sendCSV:: ~sendCSV(){
    this->path.clear();
    delete this->io;
}
void sendCSV::execute() {
    std::ifstream file;
    file.open(this->path);
    string line;
    while (std::getline(file, line)) {
        this->io->write(line);
    }
    file.close();
}
