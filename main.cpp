#include <iostream>
#include "timeseries.cpp"

int main() {
    TimeSeries* a = new TimeSeries("/home/ben/Downloads/csvTest.csv");
    a->printTable();
    delete a;
    return 0;
}
