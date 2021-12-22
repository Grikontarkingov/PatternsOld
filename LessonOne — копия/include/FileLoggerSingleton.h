#pragma once
#include <string>
#include <cstring>
#include <fstream>
#include <chrono>

class ILogger{
public:
    virtual ~ILogger() = default;

    virtual void OpenLogFile(const std::string& FN) = 0;

    virtual void CloseLogFile() = 0;

    virtual void WriteToLog(const std::string& str) = 0;

    virtual void WriteToLog(const std::string& str, int n) = 0;

    virtual void WriteToLog(const std::string& str, double d) = 0;

    virtual std::string GetCurDateTime() = 0;
};

class FileLoggerSingleton : public ILogger{
public:
    static ILogger& getInstance();

    virtual void OpenLogFile(const std::string& FN) override;

    virtual void CloseLogFile() override;

    virtual void WriteToLog(const std::string& str) override;

    virtual void WriteToLog(const std::string& str, int n) override;

    virtual void WriteToLog(const std::string& str, double d) override;

private:
    friend ILogger& getInternalInstanceLogger();

    std::ofstream logOut;

    FileLoggerSingleton(){};
    ~FileLoggerSingleton() = default;
    FileLoggerSingleton(const FileLoggerSingleton& root) = delete;
    FileLoggerSingleton& operator=(const FileLoggerSingleton&) = delete;
    virtual std::string GetCurDateTime() override;

};


