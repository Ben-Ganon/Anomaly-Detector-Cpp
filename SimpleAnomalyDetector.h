/* Authors:
 * Ben Ganon - 318731007
 * Sagiv Antebi - 318159282
 */

#ifndef SIMPLEANOMALYDETECTOR_H_
#define SIMPLEANOMALYDETECTOR_H_

#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#define THRESHOLD 1.2
#define PEARSON 0.9
struct correlatedFeatures {
    std::string feature1, feature2;// names of the correlated features
    int col1, col2;
    float corrlation;
    Line lin_reg;
    float threshold;
};

class SimpleAnomalyDetector : public TimeSeriesAnomalyDetector {
    //this vector is a dynamic array of correlated features.
    std::vector<correlatedFeatures>* cf;
public:
    SimpleAnomalyDetector();

    void addCf(correlatedFeatures cf);

    virtual ~SimpleAnomalyDetector();

    virtual void learnNormal(const TimeSeries &ts);

    virtual std::vector<AnomalyReport> detect(const TimeSeries &ts);

    std::vector<correlatedFeatures> getNormalModel();

    float maxDev(std::vector<float> vector1, std::vector<float> vector2, unsigned int size,Line l);
};


#endif /* SIMPLEANOMALYDETECTOR_H_ */
