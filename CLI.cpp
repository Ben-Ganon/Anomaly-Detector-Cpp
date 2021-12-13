/* Authors:
 * Ben Ganon - 318731007
 * Sagiv Antebi - 318159282
 */

#include "CLI.h"

CLI::CLI(DefaultIO *dio) {
}

void CLI::start() {
    // the user choice
    char choice;
    // the csv paths
    string csvTrain, csvTest;
    // indicates if the loop need to keep runs
    bool run = true;
    while (run) {
        cout
                << "Welcome to the Anomaly Detection Server. Please choose an option: \n1. upload a time series csv"
                   " file \n2. algorithm settings \n3. detect anomalies \n4. display results \n5. upload anomalies "
                   "and analyze results \n6. exit"
                << endl
        cin >> choice;
        switch (choice) {
            case '1':
                cout << "Please upload your local train CSV file." << endl;
                // insert the paths given by the user
                cin >> csvTrain
                cout << "Upload complete." << endl;
                cout << "Please upload your local test CSV file." << endl;
                // insert the paths given by the user
                cin >> csvTest
                cout << "Upload complete." << endl;
                //TODO: need to implement here the command that sending the given csv from the client to the server
                break;
            case '2':
                float currentThreshold;
                //need to get it from the given csv
                cout << "The current correlation threshold is";
            default:
                cout << "Invalid choice!" << endl;


        }
    }

}


CLI::~CLI() {
}

