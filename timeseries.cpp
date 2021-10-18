#include "timeseries.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

TimeSeries::TimeSeries(const char *CSVfileName) {
    ifstream file;
    //openning the file given
    file.open(CSVfileName);
    //a line string to hold the current line in the file as we iterate
    string line;
    //word string to hold the current word
    string word;
    getline(file, line);
    stringstream stream (line);
    vector<string> firstLine;
    while(getline(stream, word, ',')) {
        columnNames.push_back(word);
    }
    //float to hold the current number
    float iter;
    while(getline(file, line)) {
        vector<float> values;
        stringstream floatStream(line);
        while(getline(floatStream, word, ',')) {
            values.push_back(stof(word));
        }
        table.push_back(values);
        values.clear();
    }

    file.close();
}
void TimeSeries::printTable() {
    for(string s : columnNames) {
        cout<<s;
    }
    cout<<endl;
    for(vector<float> v : table) {
        for(float f : v) {
            cout<<f<<"   ";
        }
        cout<<endl;
    }
}
void TimeSeries::addColumn(float* column, char* name){

}
void TimeSeries::addRow(float* values, float time) {

}
float* TimeSeries::getColumn(int column) {
    return 0;

}
float* getRow(int row){
    return 0;

}
float getCell(int row, int cloumn) {
    return 0;

}
float setCell(int row, int column) {
    return 0;
}