//
// Created by ben on 13/12/2021.
//

#ifndef EX1TASK2_SENDCSV_H
#define EX1TASK2_SENDCSV_H
#include "../commands.h"

class sendCSV:public Command{
    string path;
    DefaultIO* io;
public:
sendCSV(string path, DefaultIO* io);
~sendCSV() = default;
void execute() override;


};


#endif //EX1TASK2_SENDCSV_H
