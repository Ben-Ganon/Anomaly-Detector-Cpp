//
// Created by ben on 13/12/2021.
//

#include "receiveCSV.h"
#include <iostream>

receiveCSV::receiveCSV(DefaultIO *dio, string path) : Command(nullptr) {
    this->path = path;
    this->io = io;

}


void receiveCSV::execute(string path) {
    io->read(path);
}

