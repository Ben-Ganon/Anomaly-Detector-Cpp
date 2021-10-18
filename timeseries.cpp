#include "timeseries.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

TimeSeries::TimeSeries(const char *CSVfileName) {
    ifstream file;
    file.open(CSVfileName);
    string line;
    string word;
    getline(file, line);
    stringstream stream (line);
    while(getline(stream, word, ',')) {

    }
    table.push_back();
    while(getline(file, line)) {
        vector<float> values;
        while(false) {

        }
    }


    file.close()
}
void addColumn(float* column, char* name){
}
void addRow(float* values, float time) {

}
float* getColumn(int column) {
    return null;
}
float* getRow(int row){

}
float getCell(int row, int cloumn) {

}
float setCell(int row, int column) {

}