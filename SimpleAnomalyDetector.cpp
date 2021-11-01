
#include "SimpleAnomalyDetector.h"
#include "anomaly_detection_util.h"

SimpleAnomalyDetector::SimpleAnomalyDetector() {
    //TODO Auto-generated constructor stub
    this->cf = new vector<correlatedFeatures>;

}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
    //TODO Auto-generated destructor stub
    this->cf.clear();
}


void SimpleAnomalyDetector::learnNormal(const TimeSeries &ts) {
    //TODO Auto-generated destructor stub
    float m, p;
    int c;
    for (int i = 0; i < ts.numColumns(); i++) {
        m = 0;
        c = -1;
        for (int j = i + 1; j < ts.numColumns(); j++) {
            p = pearson(convertVector(ts.getColumn(i)), convertVector(ts.getColumn(j)), ts.getColumn(i).size());
            if (p > m) {
                m = p;
                c = j;
            }
        }
        if (1 != c) {
            correlatedFeatures correlatedFeature = new correlatedFeatures();
            correlatedFeature.corrlation = m;
            //need to change the function operation in timeSeries
            correlatedFeature.feature1 = ts.getCell(0, i);
            correlatedFeature.feature2 = ts.getCell(0, c);
            //need to add to those two:
//            correlatedFeature.lin_reg = ;
//            correlatedFeature.threshold = ;
            cf->push_back()
        }


    }
}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries &ts) {
    //TODO Auto-generated destructor stub
}

/**
 * adds a new correlated feature to the anomaly detector.
 * @param features1
 */
void SimpleAnomalyDetector::addCf(correlatedFeatures features1) {
    this->cf.push_back(features1);
}

