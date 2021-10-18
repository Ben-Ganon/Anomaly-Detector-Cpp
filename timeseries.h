

#ifndef TIMESERIES_H_
#define TIMESERIES_H_
#include <vector>

using namespace std;

class TimeSeries{
private:
    TimeSeries(const char *CSVfileName);

    vector<vector<float>> table;
public:
    void addColumn(float* column, char* name);
    void addRow(float* values, float time);
    float* getColumn(int column);
    float* getRow(int row);
    float getCell(int row, int cloumn);
    float setCell(int row, int column);

};



#endif /* TIMESERIES_H_ */
