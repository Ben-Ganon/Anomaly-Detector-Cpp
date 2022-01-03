/* Authors:
 * Ben Ganon - 318731007
 * Sagiv Antebi - 318159282
 */

#include "CLI.h"

CLI::CLI(DefaultIO *dio) {
    this->dio = dio;
    commands.push_back(new UploadCSV(dio));
    commands.push_back(new Settings(dio));
    commands.push_back(new Detect(dio));
    commands.push_back(new Results(dio));
    commands.push_back(new UploadAnom(dio));
    commands.push_back(new Exit(dio));
}

void CLI::start() {
    currentState sharedState;
    int validIndex = -1;
    while (validIndex != 5) {
        dio->write("Welcome to the Anomaly Detection Server.\n");
        dio->write("Please choose an option:\n");
        for (int i = 0; i < commands.size(); i++) {
            dio->write(i + 1);
            dio->write(".");
            dio->write(commands[i]->description + "\n");
        }
        string choice = dio->read();
        // calculate using ascii table
        validIndex = choice[0] - '0' - 1;
        // checking if the input is a valid choice
        if (validIndex > -1 && validIndex < 7)
            commands[validIndex]->execute(&sharedState);
    }
}


CLI::~CLI() {
    for (int i = 0; i < commands.size(); i++) {
        delete commands[i];
    }
}


