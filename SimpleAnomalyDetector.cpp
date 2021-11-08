
#include "SimpleAnomalyDetector.h"
#include "anomaly_detection_util.h"

SimpleAnomalyDetector::SimpleAnomalyDetector() {
	//TODO Auto-generated constructor stub
    this->cf = new vector<correlatedFeatures>;

}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
    //TODO Auto-generated destructor stub
    this->cf->clear();
    delete cf;
}


void SimpleAnomalyDetector::learnNormal(const TimeSeries &ts) {
    //TODO Auto-generated destructor stub
    float m, p;
    int index;
    for (int i = 0; i < ts.numColumns(); i++) {
        m = 0;
        index = -1;
        for (int j = i + 1; j < ts.numColumns(); j++) {
            p = pearson(convertVector(ts.getColumn(i)), convertVector(ts.getColumn(j)), ts.getColumn(i).size());
            if (p > m) {
                m = p;
                index = j;
            }
        }
        if (1 != index) {
            correlatedFeatures *correlatedFeature = new correlatedFeatures();
            correlatedFeature->correlation = m;
            //need to change the function operation in timeSeries - need to return vector with floats
            correlatedFeature->feature1 = ts.getNameOfRaw(i);
            correlatedFeature->feature2 = ts.getNameOfRaw(index);
            //need to add to those two:
            correlatedFeature->lin_reg = linear_reg(ts.getColumn(i),ts.getColumn(index),ts.getColumn(i).size());
//            correlatedFeature.threshold = ;
            cf->push_back(*correlatedFeature);
        }


    }
}
/**
 * detect iterates over the correlatedd features created in learnNormal,
 * then measures each point's distance from the linear regression line of the two cf's,
 * if a point is farther away than the threshold, detect adds an anomaly report to the vector,
 * then returns the vector.
 * @param ts - the desired timeseries to find anomalies in
 * @return
 */
vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries &ts) {
    auto anomalies = new vector<AnomalyReport>;
    //iteration over cf's
    for (correlatedFeatures currCf : *cf) {
        //the two columns from the timeseries
        vector<float> col1 = ts.getColumn(currCf.col1);
        vector<float> col2 = ts.getColumn(currCf.col2);
        //iterating over each line in the columns
        for (int i = 0; i < col1.size(); i++) {
            Point *currP = new Point(col1.at(i), col2.at(i));
            //checking if the point is too far away from lin_reg
            if (dev(*currP, currCf.lin_reg) > currCf.threshold) {
                //creating a new anomaly report
                string desc = currCf.feature1 + "-" + currCf.feature2;
                AnomalyReport anom = AnomalyReport(desc, i);
                anomalies->push_back(anom);
            }
            delete currP;
        }
    }
    return *anomalies;
}

/**
 * adds a new correlated feature to the anomaly detector.
 * @param features1
 */
void SimpleAnomalyDetector::addCf(correlatedFeatures features1) {
    this->cf->push_back(features1);
}

