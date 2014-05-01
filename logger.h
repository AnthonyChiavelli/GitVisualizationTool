#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Disable to disable debug logging
#define DEBUG_LOG_ENABLED

// Provides basic logging capabilities. To use, call one of the following:
//
//      Logger::info() to log basic, routine information about the running of a program
//          example: "Rendering commit nodes"
//
//      Logger::debug() to log statements needed to debug the program. These statements
//                      will only execute when the DEBUG_LOG_ENABLED macro is defined
//          example: "inside for loop, count is 0"
//
//      Logger::error() to indicate errors
//          example: "myList is null, aborting!!!"
//
// Each of these functions take three arguments: a tag, a message, and optionally, and a
// boolean indicating if the log message should also be written to the log file.
namespace Logger {

    // Relative path to log file
    //INTENTIONAL ERROR! MAKE SURE TO CHANGE PATH
    const string MAIN_LOGFILE_PATH = "~/.GitVisualizationTool/logs/main.log"; //"/home/anthony/dev/GitVisualizationTool/logs/main.log";

    // Format of log statements
    const string LOG_FORMAT = "[%s] %s | %s\n";

    // Logging functions:
    //  Write a log message to STDOUT/STDERR
    //
    //  message - the message to write to the log
    //  tag - a string that identifies the caller (e.g. function, line, file, etc)
    //  writeToFile - also output to log file? (false by default)
    void error(string tag, string message, bool writeToFile = false);
    void debug(string tag, string message, bool writeToFile = false);
    void info(string tag, string message, bool writeToFile = false);

}

// Helper method for logging methods
void outputLogMessage(string prefix, string tag, string message, bool writeToFile, FILE *screenOutput, string fileOutput);

#endif // LOGGER_H
