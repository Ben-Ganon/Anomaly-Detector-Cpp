

#ifndef TIMESERIES_H_
#define TIMESERIES_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class TimeSeries {
private:
    vector<vector<float>> table;
    vector<string> columnNames;
public:
    TimeSeries(const char *CSVfileName);

    void printTable();

    void addColumn(vector<float> column, string name);

    void addRow(vector<float> values);

    vector<float> getColumn(int column);

    vector<float> getRow(int row);

    float getCell(int row, int column);

    void setCell(int row, int column, float val);

    vector<float> copyVector(vector<float> v);
};


#endif /* TIMESERIES_H_ */
