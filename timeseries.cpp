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
vector<float> TimeSeries::getColumn(int column) {
    vector<float> floatCol;
    for (vector<float> v : table) {
        floatCol.push_back(v.at(column));
    }
    return floatCol;

}
vector<float>  TimeSeries::getRow(int row){
    vector<float> f;
    if(table.size() <= row) {
        cout<<"not in range"<<endl;
        return f;
    }else {
        return table.at(row);
    }

}
float getCell(int row, int cloumn) {
    return 0;

}
float setCell(int row, int column) {
    return 0;
}