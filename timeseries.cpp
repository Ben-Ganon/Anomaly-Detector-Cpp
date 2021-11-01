#include "timeseries.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

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

    columnNames = new vector<string>;
    //while loop goes through each word in the line and insert it into columnNames
    while (getline(stream, word, ',')) {
        columnNames->push_back(word);
    }
    table = new vector<vector<float>*>;
    for(int i = 0; i < columnNames->size(); i++) {
        table->push_back(new vector<float>);
    }
    //insert the values
    while (getline(file, line)) {
        stringstream floatStream(line);
        int place = 0;
        while (getline(floatStream, word, ',')) {
           this->table->at(place)->push_back(stof(word));
           place++;
        }
    }

    file.close();
}

/**
 * prints the timeseries.
 */
void TimeSeries::printTable() {
    for (string s: *columnNames) {
        cout << s;
    }
    cout << endl;
    for (int i = 0; i < this->table->at(0)->size(); i++) {
        for (vector<float> *v: *this->table) {
            cout << v->at(i) << "   ";
        }
    cout << endl;
    }
}
/**
 * adds a column to the table - each row will receive a new member at the back
 * @param column - the column vector given to add
 * @param name - name of the column to add to the columnNames vector
 */
void TimeSeries::addColumn(vector<float>* column, string name) {
    //adding the name to the column vector
    columnNames->push_back(name);
    vector<float>* inCol = copyVector(column);
    this->table->push_back(inCol);

}

/**
 * adds a new row to the timeseries.
 * @param values
 */
void TimeSeries::addRow(vector<float> values) {
    if (values.size() > this->table->size() || values.size() < this->table->size()) {
        cout << "number of columns is mismatched!";
        exit(1);
    }
    for (int i = 0; i < this->table->size(); i++) {
        this->table->at(i)->push_back(values[i]);
    }
}

/**
 * retreives a desired column from the timeseries
 * @param column
 * @return
 */
vector<float> TimeSeries::getColumn(int column) const {
    return *this->table->at(column);
}

/**
 * retreives a desired row from the timeseries
 * @param row
 * @return
 */
vector<float> TimeSeries::getRow(int row) {
    vector<float> f;
    for (vector<float>* v : *this->table) {
        f.push_back(v->at(row));
    }
    return f;
}

/**
 * returns the desired cell's value
 * @param row
 * @param column
 * @return
 */
float TimeSeries::getCell(int row, int column) const{
    return this->table->at(column)->at(row);
}

/**
 * sets the desired cell's value to val
 * @param row
 * @param column
 * @param val
 */
void TimeSeries::setCell(int row, int column, float val) {
    this->table->at(column)->at(row) = val;
}

/**
 * copies a given vector (deep copy) and returns it.
 * @param v
 * @return
 */
vector<float>* TimeSeries::copyVector(vector<float>* v) {
    auto* newV = new vector<float>;
    for(int i = 0; i < v->size(); i++) {
        newV->push_back(v->at(i));
    }
    return newV;
}

/**
 * returns the number of columns in the timeseries.
 * @return
 */
int TimeSeries::numColumns() const {
    return this->columnNames->size();
}