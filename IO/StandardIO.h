//
// Created by ben on 13/12/2021.
//

#ifndef EX1TASK2_STANDARDIO_H
#define EX1TASK2_STANDARDIO_H
#include "../commands.h"

class StandardIO: public DefaultIO{
    StandardIO()= default;
    ~StandardIO() = default;
    virtual string read();
    virtual void write(string text);
    virtual void write(float f);
    virtual void read(float* f);
};


#endif //EX1TASK2_STANDARDIO_H
