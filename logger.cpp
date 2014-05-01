#include "logger.h"


void Logger::error(string tag, string message, bool writeToFile) {

    outputLogMessage("ERROR", tag, message, writeToFile, stderr, MAIN_LOGFILE_PATH);

}

void Logger::debug(string tag, string message, bool writeToFile) {
    #ifdef DEBUG_LOG_ENABLED
    outputLogMessage("DEBUG", tag, message, writeToFile, stdout, MAIN_LOGFILE_PATH);
    #endif
}

void Logger::info(string tag, string message, bool writeToFile) {

    outputLogMessage("INFO", tag, message, writeToFile, stdout, MAIN_LOGFILE_PATH);

}

void outputLogMessage(string prefix, string tag, string message, bool writeToFile, FILE *screenOutput, string fileOutput) {
    // Print log message
    fprintf (stdout, Logger::LOG_FORMAT.c_str(), prefix.c_str(), tag.c_str(), message.c_str());
    // Write log message to file
    if (writeToFile) {
        FILE * logFile = fopen (fileOutput.c_str(), "a");
        fprintf (logFile, Logger::LOG_FORMAT.c_str(), prefix.c_str(), tag.c_str(), message.c_str());
    }

}





