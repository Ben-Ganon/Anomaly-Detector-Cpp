//
// Created by ben on 13/12/2021.
//
#include "StandardIO.h"

string read() {
    string input;
    cin >> input;
    return input;

}

void write(string text) {
    cout << text << endl;
}

void write(float f) {
    cout << f << endl;
}

void read(float* f) {
    float g;
    cin >> g;
    *f = g;
}