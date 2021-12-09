

#ifndef HYBRIDANOMALYDETECTOR_H_
#define HYBRIDANOMALYDETECTOR_H_

#include "SimpleAnomalyDetector.h"
#include "minCircle.h"

class HybridAnomalyDetector:public SimpleAnomalyDetector {
public:
	HybridAnomalyDetector();
	virtual ~HybridAnomalyDetector();
    void HybridLearner(const TimeSeries &ts, float m, int i, int index);
    vector<Point> getPoints(std::vector<float> v1, std:: vector<float> v2);
};

#endif /* HYBRIDANOMALYDETECTOR_H_ */
