/* Authors:
 * Ben Ganon - 318731007
 * Sagiv Antebi - 318159282
 */

#include "CLI.h"

CLI::CLI(DefaultIO *dio) {
    this->dio = dio;
}

void CLI::start() {
    // the user choice
    char choice;
    // the csv paths
    string csvTrain, csvTest, localAnomFiles;
    // the csv threshold
    float threshold = 0.9;
    // indicates if the loop need to keep runs
    bool run = true;
    while (run) {
        cout
                << "Welcome to the Anomaly Detection Server. Please choose an option: \n1. upload a time series csv"
                   " file \n2. algorithm settings \n3. detect anomalies \n4. display results \n5. upload anomalies "
                   "and analyze results \n6. exit"
                << endl;
        cin >> choice;
        switch (choice) {
            // 1 - upload a time series csv file
            case '1':
                //TODO: replace the command to read the client csv
                cout << "Please upload your local train CSV file." << endl;
                // insert the paths given by the user
                cin >> csvTrain;
                cout << "Upload complete." << endl;
                cout << "Please upload your local test CSV file." << endl;
                // insert the paths given by the user
                cin >> csvTest;
                cout << "Upload complete." << endl;
                //TODO: need to implement here the command that sending the given csv from the client to the server
                break;
            // 2 - algorithm settings
            case '2':
                cout << "The current correlation threshold is " << threshold << endl;
                do {
                    cout << "Type a new threshold" << endl;
                    cin >> threshold;
                } while (threshold > 1 && threshold < 0);
                break;
            // 3 - detect anomalies
            case '3':
                //TODO: run the hybrid anomaly detection
                cout << "anomaly detection complete." << endl;
                break;
            // 4 - display results
            case '4':
                //TODO: need to initialize those variables
                float timeStep;
                string description;
                // the printing method given by the instructor
                cout << timeStep << "\t" << description << endl;
                cout << "Done." << endl;
                break;
            // 5 - upload anomalies
            case '5':
                float truePositiveRate, falsePositiveRate;
                //TODO: replace the command to read the client csv
                cout << "Please upload your local train CSV file." << endl;
                // insert the paths given by the user
                cin >> localAnomFiles;
                cout << "Upload complete." << endl;
                //TODO: do here all the calculations
                cout << "True Positive Rate: " << truePositiveRate << endl;
                cout << "False Positive Rate: " << falsePositiveRate << endl;
            case '6':
                run = false;
                break;
            default:
                cout << "Invalid choice!" << endl;


        }
    }

}


CLI::~CLI() {
}

