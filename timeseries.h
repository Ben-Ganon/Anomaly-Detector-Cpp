

#ifndef TIMESERIES_H_
#define TIMESERIES_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class TimeSeries {
private:
    vector<vector<float> *> *table;
    vector<string> *columnNames;
public:
    TimeSeries(const char *CSVfileName);

    ~TimeSeries();

    void printTable();

    void addColumn(vector<float> *column, string name);

    void addRow(vector<float> values);

    vector<float> getColumn(int column) const;

    vector<float> getRow(int row);

    float getCell(int row, int column) const;

    void setCell(int row, int column, float val);

    vector<float> *copyVector(vector<float> *v);

    int numColumns() const;

    string getNameOfRaw(int i) const;

    vector<string> * getNames() const;
};


#endif /* TIMESERIES_H_ */
