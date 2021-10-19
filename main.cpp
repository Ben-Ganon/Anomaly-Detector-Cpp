#include <iostream>
#include "timeseries.cpp"

int main() {

    //sagiv's path
    TimeSeries *a = new TimeSeries("/home/ben/Downloads/csvTest.csv");
    a->printTable();
    vector<float> newCol;
    for (int i = 0; i < 13; i++) {
        newCol.push_back(i);
    }
    a->addColumn(newCol, "New");
    a->printTable();
    delete a;
    return 0;
}
