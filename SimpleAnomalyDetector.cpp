
#include "SimpleAnomalyDetector.h"
#include "anomaly_detection_util.h"

SimpleAnomalyDetector::SimpleAnomalyDetector() {
	//TODO Auto-generated constructor stub
    this->cf = new vector<correlatedFeatures>;

}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
	//TODO Auto-generated destructor stub
    //this->cf.clear();
}


void SimpleAnomalyDetector::learnNormal(const TimeSeries& ts){
	//TODO Auto-generated destructor stub
    for(int i = 0; i < ts.numColumns(); i++) {
        for (int j = i + 1; j < ts.numColumns(); j++) {
            pearson(convertVector(ts.getColumn(i)), convertVector(ts.getColumn(j)), ts.getColumn(i).size());
        }


    }
}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){
	//TODO Auto-generated destructor stub
}

/**
 * adds a new correlated feature to the anomaly detector.
 * @param features1
 */
void SimpleAnomalyDetector::addCf(correlatedFeatures features1) {
    this->cf.push_back(features1);
}

