#include <iostream>
#include "timeseries.cpp"

int main() {
    TimeSeries* a = new TimeSeries("/home/ben/Downloads/csvTest.csv");
    vector<float> b = a->getRow(13);
    for(float f : b) {
        cout<<f<<endl;
        cout<<"hi";
    }
    delete a;
    return 0;
}
