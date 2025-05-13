#include <fstream>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// class Logger {
//    private:
//     ofstream logFile;

//    public:
//     Logger(const string fileName) {
//         logFile.open(fileName, ios::app);  // Open in append mode

//         if (!logFile) {
//             throw runtime_error("Unable to open log file");
//         }
//     }

//     ~Logger() {
//         if (logFile.is_open()) {
//             logFile.close();
//         }
//     }

//     // & because of passing reference instead of copy
//     void log(const string& message) { logFile << message << endl; }
// };

// Singleton Logger
class Logger {
    ofstream logFile;
    static shared_ptr<Logger> instance;

    Logger() { logFile.open("./logs/log.txt", ios::app); }

   public:
    static shared_ptr<Logger> getInstance() {
        if (!instance) {
            instance = shared_ptr<Logger>(new Logger());
        }

        return instance;
    }

    void log(const string& message) { logFile << message << endl; }

    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};

shared_ptr<Logger> Logger::instance = nullptr;

int main() {
    // shared_ptr<Logger> logger = make_shared<Logger>("./logs/log.txt");

    // logger->log("Starting the application");

    // // Simulate passing it to another component
    // auto anotherComponent = logger;
    // anotherComponent->log("Another component is running");

    //  Creating Singleton logger
    Logger::getInstance()->log("Logging from anywhere");
    return 0;
}