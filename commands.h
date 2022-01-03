/* Authors:
 * Ben Ganon - 318731007
 * Sagiv Antebi - 318159282
 */

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include<iostream>
#include <string.h>

#include <fstream>
#include <vector>
#include "timeseries.h"
#include "HybridAnomalyDetector.h"

using namespace std;

class DefaultIO {
public:
    virtual string read() = 0;

    virtual void write(string text) = 0;

    virtual void write(float f) = 0;

    virtual void read(float *f) = 0;

    virtual ~DefaultIO() {}

    // you may add additional methods here

    void readAndFile(string fileName) {
        ofstream out(fileName);
        string s = "";
        while ((s = read()) != "done") {
            out << s << endl;
        }
        out.close();
    }


};


struct blockReport {
    int start;
    int end;
    string description;
    bool tp;
};

struct currentState {
    float threshold;
    vector<AnomalyReport> report;
    vector<blockReport> blkReports;
    int rowNum;

    currentState() {
        threshold = 0.9;
        rowNum = 0;
    }
};


// you may edit this class
class Command {
protected:
    DefaultIO *dio;

public:
    const string description;

    Command(DefaultIO *dio, const string description) : dio(dio), description(description) {}

    virtual void execute(currentState *currentState) = 0;

    virtual ~Command() {}
};

// implement here your command classes

class UploadCSV : public Command {
public:
    UploadCSV(DefaultIO *dio) : Command(dio, "upload a time series csv file") {}

    virtual void execute(currentState *currState) {
        dio->write("Please upload your local train CSV file.\n");
        dio->readAndFile("anomalyTrain.csv");
        dio->write("Upload complete.\n");
        dio->write("Please upload your local test CSV file.\n");
        dio->readAndFile("anomalyTest.csv");
        dio->write("Upload complete.\n");
    }
};

class Settings : public Command {
public:
    Settings(DefaultIO *dio) : Command(dio, "algorithm settings") {}

    virtual void execute(currentState *currState) {

        float thresh;
        bool choiceFlag = true;
        while (choiceFlag) {
            dio->write("The current correlation threshold is ");
            dio->write(currState->threshold);
            dio->write("\n");
            dio->write("Type a new threshold\n");
            dio->read(&thresh);
            if (0 > thresh || thresh > 1) {
                dio->write("please choose a value between 0 and 1.\n");
            } else {
                choiceFlag = false;
                currState->threshold = thresh;
            }
        }
    }
};

class Detect : public Command {
public:
    Detect(DefaultIO *dio) : Command(dio, "detect anomalies") {}

    virtual void execute(currentState *currState) {
        TimeSeries train("anomalyTrain.csv");
        TimeSeries test("anomalyTest.csv");
        HybridAnomalyDetector had;
        currState->rowNum = test.getRowSize();
        had.setCorrelationThreshold(currState->threshold);
        had.learnNormal(train);
        currState->report = had.detect(test);
        blockReport fReport;
        int timeStepTemp = currState->report.at(0).timeStep;
        for (AnomalyReport anom: currState->report) {
            //the first report
            if (timeStepTemp == anom.timeStep) {
                fReport.start = anom.timeStep;
                fReport.end = anom.timeStep;
                fReport.description = anom.description;
                fReport.tp = false;
            }
                //additional report - another block
            else if (timeStepTemp != anom.timeStep - 1) {
                fReport.end = timeStepTemp;
                currState->blkReports.push_back(fReport);
                fReport.start = anom.timeStep;
                fReport.description = anom.description;
                fReport.tp = false;
            }
            timeStepTemp = anom.timeStep;
        }
        fReport.end = timeStepTemp;
        currState->blkReports.push_back(fReport);
        dio->write("anomaly detection complete.\n");

    }
};

class Results : public Command {
public:
    Results(DefaultIO *dio) : Command(dio, "display results") {}

    virtual void execute(currentState *sharedState) {
        for_each(sharedState->report.begin(), sharedState->report.end(), [this](AnomalyReport &anom) {
            dio->write(anom.timeStep);
            dio->write("\t " + anom.description + "\n");
        });
        dio->write("Done.\n");
    }
};


class UploadAnom : public Command {
public:
    UploadAnom(DefaultIO *dio) : Command(dio, "upload anomalies and analyze results") {}

    bool isFalseNega(unsigned long start, unsigned long end, currentState *sharedState) {
        bool fpFlag = true;
        int i = 0;
        for (blockReport report: sharedState->blkReports) {
            int startBlock = report.start;
            int endbBlock = report.end;
            if (((startBlock <= start && start <= endbBlock) || (startBlock <= end && end <= endbBlock))
                || (start < startBlock && endbBlock < end)) {
                //
                sharedState->blkReports.at(i).tp = true;
                fpFlag = false;
            }
            i++;
        }
        return fpFlag;
    }

    /**
     * the return vector is : vector[0] = Positive,  vector[1] = False Positive
     * @param sharedState
     * @return
     */
    vector<int> PosiCount(currentState *sharedState) {
        vector<int> sums;
        int sumPosi = 0;
        int sumFalsePosi = 0;
        for (blockReport report: sharedState->blkReports) {
            if (!report.tp)
                sumFalsePosi++;
            sumPosi++;
        }
        sums.push_back(sumPosi);
        sums.push_back(sumFalsePosi);
        return sums;
    }

    virtual void execute(currentState *sharedState) {
        dio->write("Please upload your local anomalies file.\n");
        string s = "";
        float TruePosiRate = 0, FalseAlarmRate = 0;
        int posiNum = 0, N = 0, FalsePosiNum, rowSum = 0, TruePosiNum = 0, FalseNegaNum = 0;
        while ((s = dio->read()) != "done") {
            unsigned long dividerIndex = s.find(',');
            string startString = s.substr(0, dividerIndex);
            string endString = s.substr(dividerIndex + 1);
            unsigned long start = stoi(startString);
            unsigned long end = stoi(endString);
            if (isFalseNega(start, end, sharedState))
                FalseNegaNum++;
            else TruePosiNum++;
            rowSum += end - start + 1;
            posiNum++;
        }
        dio->write("Upload complete.\n");
        auto posiSums = PosiCount(sharedState);
        FalsePosiNum = posiSums.at(1);
        N = sharedState->rowNum - rowSum;
        TruePosiRate = ((int) (1000.0 * TruePosiNum / posiNum)) / 1000.0f;
        FalseAlarmRate = ((int) (1000.0 * FalsePosiNum / N)) / 1000.0f;
        dio->write("True Positive Rate: ");
        dio->write(TruePosiRate);
        dio->write("\nFalse Positive Rate: ");
        dio->write(FalseAlarmRate);
        dio->write("\n");
    }
/*
        bool crossSection(int as, int ae, int bs, int be) {
            return (ae >= bs && be >= as);
        }


        bool isTP(int start, int end, currentState *sharedState) {
            for (size_t i = 0; i < sharedState->blkReports.size(); i++) {
                blockReport fr = sharedState->blkReports[i];
                if (crossSection(start, end, fr.start, fr.end)) {
                    sharedState->blkReports[i].tp = true;
                    return true;
                }
            }
            return false;
        }

        virtual void execute(currentState *sharedState) {

            for (size_t i = 0; i < sharedState->blkReports.size(); i++) {
                sharedState->blkReports[i].tp = false;
            }

            dio->write("Please upload your local anomalies file.\n");
            string s = "";
            float TP = 0, sum = 0, P = 0;
            while ((s = dio->read()) != "done") {
                size_t t = 0;
                for (; s[t] != ','; t++);
                string st = s.substr(0, t);
                string en = s.substr(t + 1, s.length());
                int start = stoi(st);
                int end = stoi(en);
                if (isTP(start, end, sharedState))
                    TP++;
                sum += end + 1 - start;
                P++;
            }
            dio->write("Upload complete.\n");
            float FP = 0;
            for (size_t i = 0; i < sharedState->blkReports.size(); i++)
                if (!sharedState->blkReports[i].tp)
                    FP++;
            float N = sharedState->rowNum - sum;
            float tpr = ((int) (1000.0 * TP / P)) / 1000.0f;
            float fpr = ((int) (1000.0 * FP / N)) / 1000.0f;
            dio->write("True Positive Rate: ");
            dio->write(tpr);
            dio->write("\nFalse Positive Rate: ");
            dio->write(fpr);
            dio->write("\n");
        }
        */
};

class Exit : public Command {
public:
    Exit(DefaultIO *dio) : Command(dio, "exit") {}

    virtual void execute(currentState *sharedState) {
        //cout<<description<<endl;
    }
};


#endif /* COMMANDS_H_ */
