/*
*   A little class to take a log.
*   Author: necotec(Oliver ALFF)
*/

#ifndef LOGFILEWRITER_H_INCLUDED
#define LOGFILEWRITER_H_INCLUDED

#include <iostream>

enum LogLevel
{
    Debug = 1,
    Info = 2,
    Warning = 3,
    Error = 4,
    Fatal = 5
};

class LogfileWriter{
protected:
    std::string testString = "teststring protected";

private:
    std::string LogfilePath = "";
    std::string LogfileName = "nctLogfile.txt";

public:
    LogfileWriter();
    LogfileWriter(std::string path, std::string filename);
    ~LogfileWriter();
    void Test();
    bool SetLogfilePath(std::string path);
    bool SetLogfileName(std::string name);
    std::string GetLogfilePath();
    std::string GetLogfileName();
    bool DoLog(std::string logtext);
    bool DoLog(std::string logtext, LogLevel logLevel);
    std::string BoolToString(bool b);

private:
    std::string GetLogLevelString(LogLevel logLevel);
};

//extern class LogfileWriter;
#endif // LOGFILEWRITER_H_INCLUDED
