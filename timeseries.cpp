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
    //insert the fist line
    getline(file, line);
    stringstream stream(line);
    //the first raw , the categories
    vector<string> firstLine;

    //while loop goes through each word in the line and insert it into columnNames
    while (getline(stream, word, ',')) {
        columnNames.push_back(word);
    }
    //insert the values
    while (getline(file, line)) {
        vector<float> values;
        stringstream floatStream(line);
        while (getline(floatStream, word, ',')) {
            values.push_back(stof(word));
        }
        table.push_back(values);
        values.clear();
    }

    file.close();
}

void TimeSeries::printTable() {
    for (string s: columnNames) {
        cout << s;
    }
    cout << endl;
    for (vector<float> v: table) {
        for (float f: v) {
            cout << f << "   ";
        }
        cout << endl;
    }
}
/**
 * adds a column to the table - each row will receive a new member at the back
 * @param column - the column vector given to add
 * @param name - name of the column to add to the columnNames vector
 */
void TimeSeries::addColumn(vector<float> column, string name) {
    //adding the name to the column vector
    columnNames.push_back(name);
    //iteration over the rows and adding an element to the back
    for(int i = 0; i < table.size(); i++) {
        table[i].push_back(column[i]);
    }
}

void TimeSeries::addRow(float *values, float time) {

}

vector<float> TimeSeries::getColumn(int column) {
    //array of the given column
    vector<float> floatCol;
    //edge case
    if (columnNames.size() <= column) {
        cout << "not in range" << endl;
    }
    for (vector<float> v: table) {
        floatCol.push_back(v.at(column));
    }
    return floatCol;

}


vector<float> TimeSeries::getRow(int row) {
    vector<float> f;
    //edge case
    if (table.size() <= row) {
        cout << "not in range" << endl;
        return f;
    } else {
        return table.at(row);
    }

}

float getCell(int row, int cloumn) {
    return 0;

}

float setCell(int row, int column) {
    return 0;
}

vector<float> TimeSeries::copyVector(vector<float> v) {
    vector<float> newV;
    for(int i = 0; i < v.size(); i++) {
        newV.push_back(v[i]);
    }
    return newV;
}