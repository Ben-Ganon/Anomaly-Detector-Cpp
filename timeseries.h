

#ifndef TIMESERIES_H_
#define TIMESERIES_H_
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class TimeSeries{
private:
    vector<vector<float>> table;
    vector<string> columnNames;
public:
    TimeSeries(const char *CSVfileName);
    void printTable();
    void TimeSeries::addColumn(vector<float> column, char *name);
    void addRow(float* values, float time);
    vector<float> getColumn(int column);
    vector<float>  getRow(int row);
    float getCell(int row, int cloumn);
    void setCell(int row, int column);
    static vector<float> copyVector(vector<float> v);

};



#endif /* TIMESERIES_H_ */
