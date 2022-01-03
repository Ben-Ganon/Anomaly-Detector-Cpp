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
    SharedState sharedState;
    int validIndex = -1;
    while (validIndex != 5) {
        dio->write("Welcome to the Anomaly Detection Server.\n");
        dio->write("Please choose an option:\n");
        for (size_t i = 0; i < commands.size(); i++) {
            dio->write(i + 1);
            dio->write(".");
            dio->write(commands[i]->description + "\n");
        }
        string input = dio->read();
        validIndex = input[0] - '0' - 1;
        if (validIndex >= 0 && validIndex <= 6)
            commands[validIndex]->execute(&sharedState);
    }
}


CLI::~CLI() {
    for (size_t i = 0; i < commands.size(); i++) {
        delete commands[i];
    }
}


