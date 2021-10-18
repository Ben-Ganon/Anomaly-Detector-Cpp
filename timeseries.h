

#ifndef TIMESERIES_H_
#define TIMESERIES_H_


typedef basic_string<char> string;
using namespace std;

class TimeSeries{
private:
    float[][] table;
public:
	TimeSeries(const char* CSVfileName){
	}
    void addColumn(float[] column, String name);
    void addRow(float[] values, float time);
    float* getColumn(int column);
    float* getRow(int row);
    float getCell(int row, int cloumn);
    float setCell(int row, int column);

};



#endif /* TIMESERIES_H_ */
