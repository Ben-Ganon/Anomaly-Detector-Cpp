
#include "HybridAnomalyDetector.h"
#include "minCircle.h"
#define HYBRID_PEARSON 0.5

HybridAnomalyDetector::HybridAnomalyDetector() {
    // TODO Auto-generated constructor stub

}

HybridAnomalyDetector::~HybridAnomalyDetector() {
    // TODO Auto-generated destructor stub
}

void SimpleAnomalyDetector::learnNormal(const TimeSeries &ts) {
    float m, p;
    int index;
    //iterating over the columns
    for (int i = 0; i < ts.numColumns(); i++) {
        //current max pearson coefficient
        m = 0;
        //current index of the coefficient column
        index = -1;
        //iterating over the rest of the columns
        for (int j = i + 1; j < ts.numColumns(); j++) {
            //calculating pearson of i and j
            p = pearson(ts.getColumn(i).data(), ts.getColumn(j).data(), ts.getColumn(i).size());
            if (p > m) {
                m = p;
                index = j;
            }
            if (-1 != index) {
                if (m >= PEARSON) {
                    simpleLearner(ts, m, i, index);
                }
                else if (m >= HYBRID_PEARSON) {
                    HybridLearner()
                }
            }
        }
    }
}

vector<Point> getPoints(std::vector<float> v1, std:: vector<float> v2) {
    std::vector<Point> PointArray;
    for (int i = 0; i < v1.size(); ++i) {
        Point currPoint = Point(v1.at(i), v2.at(i));
        PointArray.push_back(currPoint);
    }
    return PointArray;
}

void HybridLearner(const TimeSeries &ts, float m, int i, int index){
    correlatedFeatures correlatedFeature;
    correlatedFeature.corrlation = m;
    //need to change the function operation in timeSeries - need to return std::vector with floats
    correlatedFeature.feature1 = ts.getNameOfRaw(i);
    correlatedFeature.feature2 = ts.getNameOfRaw(index);
    correlatedFeature.col1 = i;
    correlatedFeature.col2 = index;
    std::vector<float> column1 = ts.getColumn(i);
    std::vector<float> column2 = ts.getColumn(index);
    Circle featureCircle = callMinCircle(getPoints(column1, column2));
    correlatedFeature.C  = &featureCircle;


}

