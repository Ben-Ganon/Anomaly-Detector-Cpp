
#include "SimpleAnomalyDetector.h"
#include "anomaly_detection_util.h"

SimpleAnomalyDetector::SimpleAnomalyDetector() {
    //TODO Auto-generated constructor stub
    this->cf = new vector<correlatedFeatures>;

}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
    //TODO Auto-generated destructor stub
    this->cf->clear();
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
        if (-1 != index) {
            //remember delete this
            correlatedFeatures *correlatedFeature = new correlatedFeatures();
            correlatedFeature->corrlation = m;
            //need to change the function operation in timeSeries - need to return vector with floats
            correlatedFeature->feature1 = ts.getNameOfRaw(i);
            correlatedFeature->feature2 = ts.getNameOfRaw(index);
            correlatedFeature->col1 = i;
            correlatedFeature->col2 = index;
            //need to add to those two:
            correlatedFeature->lin_reg = linear_reg(ts.getColumn(i), ts.getColumn(index), ts.getColumn(i).size());
            correlatedFeature->threshold = maxDev(ts.getColumn(i), ts.getColumn(index), ts.getColumn(i).size(),
                                                  correlatedFeature->lin_reg);
            cf->push_back(*correlatedFeature);
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
    this->cf->push_back(features1);
}

float SimpleAnomalyDetector::maxDev(vector<float> vector1, vector<float> vector2, unsigned int size, Line l) {
    float tempMax;
    float maxNum = 0;
    for (int i = 0; i < size; ++i) {
        //point from the two values of the specific columns
        Point *pTemp = new Point(vector1.at(i), vector2.at(i));
        //the maximum distance from the line
        tempMax = dev(*pTemp, l);
        if (maxNum < tempMax) {
            maxNum = tempMax;
        }
    }
    return maxNum;
}


