/*
*   A little class to take a log.
*   Author: necotec(Oliver ALFF)
*/

#include <iostream>
#include <fstream>
#include <time.h>
#include "LogfileWriter.h"

#include <algorithm>
#include <string>

//using namespace std;

//extern LogfileWriter log;

LogfileWriter::LogfileWriter()
{

}

LogfileWriter::LogfileWriter(std::string path, std::string filename)
{
    SetLogfilePath(path);
    SetLogfileName(filename);
}

LogfileWriter::~LogfileWriter()
{

}

void LogfileWriter::Test()
{
    std::cout << testString << std::endl;
}

bool LogfileWriter::SetLogfilePath(std::string path)
{
    bool returnval = false;

    try{
        LogfilePath = path;
        returnval = true;
    }
    catch(std::string& ex)
    {
        std::cout << "Error by set the path of the logfile: " << ex.c_str() << std::endl;
    }
    return returnval;
}

bool LogfileWriter::SetLogfileName(std::string name)
{
    bool returnval = false;

    try{
        LogfileName = name;



        returnval = true;
    }
    catch(std::string& ex)
    {
        std::cout << "Error by set the name of the logfile: " << ex.c_str() << std::endl;
    }
    return returnval;
}

std::string LogfileWriter::GetLogfilePath()
{
    return LogfilePath;
}

std::string LogfileWriter::GetLogfileName()
{
    std::string texpText = "";

    //std::cout << "First char of the logfile name: " << LogfileName[0] << std::endl;
    //std::cout << "Second char of the logfile name: " << LogfileName[1] << std::endl;

    return LogfileName;
}

bool LogfileWriter::DoLog(std::string logtext)
{
    bool returnval = true;
    std::string tempLogText = "";

    try{
        // declare time variables
        time_t currentTime = time(NULL);

        std::ofstream logfile;
        logfile.open(GetLogfilePath() + "\\" + GetLogfileName(), std::ios_base::app);

        if(logfile.is_open())
        {
            tempLogText = ctime(&currentTime);

            // delete \n from timestring
            tempLogText.erase(std::remove(tempLogText.begin(), tempLogText.end(), '\n'), tempLogText.end());

            tempLogText += " - ";
            tempLogText += logtext;
            tempLogText += "\n";

            std::cout << std::endl << "The logtext: " + tempLogText << std::endl << std::endl;

            std::cout << "Opened file from " << GetLogfilePath() + "\\" + GetLogfileName() << " successfully." << std::endl;;

            logfile << tempLogText;

            logfile.close();
        }
        returnval = true;
    }
    catch(std::string& ex)
    {
        std::cout << "Error by writing to the logfile: " << ex.c_str() << std::endl;
    }

    return returnval;
}

bool LogfileWriter::DoLog(std::string logtext, LogLevel logLevel)
{
    bool returnval = true;
    std::string tempLogText = "";

    try{
        // declare time variables
        time_t currentTime = time(NULL);

        std::ofstream logfile;
        logfile.open(GetLogfilePath() + "\\" + GetLogfileName(), std::ios_base::app);

        if(logfile.is_open())
        {
            tempLogText = ctime(&currentTime);  // set current time

            // delete \n from timestring
            tempLogText.erase(std::remove(tempLogText.begin(), tempLogText.end(), '\n'), tempLogText.end());

            tempLogText += " - ";
            tempLogText += GetLogLevelString(logLevel);
            tempLogText += " - ";
            tempLogText += logtext;
            tempLogText += "\n";

            std::cout << std::endl << "The logtext: " + tempLogText << std::endl << std::endl;

            //std::cout << "Opened file from " << getLogfilePath() + "\\" + getLogfileName() << " successfully." << std::endl;;

            logfile << tempLogText;

            logfile.close();
        }
        returnval = true;
    }
    catch(std::string& ex)
    {
        std::cout << "Error by writing to the logfile: " << ex.c_str() << std::endl;
    }

    return returnval;
}

std::string LogfileWriter::BoolToString(bool b)
{
    return b ? "true" : "false";
}

std::string LogfileWriter::GetLogLevelString(LogLevel logLevel)
{
    std::string logLevelString;

    switch(logLevel)
    {
        case 1:
            logLevelString = "Debug";
            //std::cout << "Added label Debug" << std::endl;
            break;
        case 2:
            logLevelString = "Info";
            //std::cout << "Added label Info" << std::endl;
            break;
        case 3:
            logLevelString = "Warning";
            //std::cout << "Added label Warning" << std::endl;
            break;
        case 4:
            logLevelString = "Error";
            //std::cout << "Added label Error" << std::endl;
            break;
        case 5:
            logLevelString = "Fatal";
            //std::cout << "Added label Fatal" << std::endl;
            break;
    }

    return logLevelString;
}
