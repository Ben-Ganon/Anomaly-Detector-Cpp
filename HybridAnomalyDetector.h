

#ifndef HYBRIDANOMALYDETECTOR_H_
#define HYBRIDANOMALYDETECTOR_H_

#include "SimpleAnomalyDetector.h"
#include "minCircle.h"
#include <vector>

class HybridAnomalyDetector:public SimpleAnomalyDetector {
    std::vector<correlatedFeatures>* cf;
public:
	HybridAnomalyDetector();
	virtual ~HybridAnomalyDetector();
    void HybridLearner(const TimeSeries &ts, float m, int i, int index, std::vector<correlatedFeatures>* featureArray);
    void learnNormal(const TimeSeries &ts) override;
    std::vector<AnomalyReport> detect(const TimeSeries &ts) override;
    virtual std::vector<correlatedFeatures> getNormalModel() override;
    vector<Point> getPoints(std::vector<float> v1, std:: vector<float> v2);
    void hybridDetection(float threshold, Point p, correlatedFeatures cf, int timeStep, std::vector<AnomalyReport>* anomalies);
};

#endif /* HYBRIDANOMALYDETECTOR_H_ */
