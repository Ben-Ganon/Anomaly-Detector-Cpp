

#ifndef SIMPLEANOMALYDETECTOR_H_
#define SIMPLEANOMALYDETECTOR_H_

#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

struct correlatedFeatures {
    string feature1, feature2;// names of the correlated features
    int col1, col2;
    float correlation;
    Line lin_reg;
    float threshold;
};


class SimpleAnomalyDetector : public TimeSeriesAnomalyDetector {
    //this vector is a dynamic array of correlated features.
    vector<correlatedFeatures>* cf;
public:
    SimpleAnomalyDetector();

    void addCf(correlatedFeatures cf);

    virtual ~SimpleAnomalyDetector();

    virtual void learnNormal(const TimeSeries &ts);

    virtual vector<AnomalyReport> detect(const TimeSeries &ts);

    vector<correlatedFeatures> getNormalModel() {
        //return cf;
    }

    float maxDev(vector<float> vector1, vector<float> vector2, unsigned int size,Line l);
};


#endif /* SIMPLEANOMALYDETECTOR_H_ */
