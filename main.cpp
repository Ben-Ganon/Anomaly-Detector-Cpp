#include <iostream>
#include "timeseries.cpp"

int main() {

    //sagiv's path
    TimeSeries *a = new TimeSeries("C:\\Users\\sagiv\\Desktop\\Ex1Task2\\csvTest.csv");
    a->printTable();
//    vector<float> b = a->getRow(2);
//
//    for (float f: b) {
//        cout << f << endl;
//        cout << "hi";
//    }
    delete a;
    return 0;
}