//
// Created by ben on 13/12/2021.
//

#ifndef EX1TASK2_RECEIVECSV_H
#define EX1TASK2_RECEIVECSV_H
#include "commands.h"

class receiveCSV : public Command{
    string path;
    DefaultIO* io;

public:
    receiveCSV(DefaultIO *dio, string path);
    ~receiveCSV() override;
    void execute(string path);
};



#endif //EX1TASK2_RECEIVECSV_H
