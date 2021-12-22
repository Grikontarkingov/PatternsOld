#include "FileLoggerSingleton.h"


ILogger& getInternalInstanceLogger(){
    static FileLoggerSingleton theInstance;
    return theInstance;
}

class LoggerSingleton : public ILogger{
public:
    virtual void OpenLogFile(const std::string &FN) override{
        getInternalInstanceLogger().OpenLogFile(FN);
    }

    virtual void CloseLogFile() override{
        getInternalInstanceLogger().CloseLogFile();
    }

    virtual std::string GetCurDateTime() override{
        auto cur = std::chrono::system_clock::now();
        time_t time = std::chrono::system_clock::to_time_t(cur);
        char* buf = ctime(&time);
        return std::string(buf);
    }

    virtual void WriteToLog(const std::string &str) override{
        ++m_numberOfEvent;
        std::string temp = std::to_string(m_numberOfEvent) + ": " + str;
        getInternalInstanceLogger().WriteToLog(temp);
    }

    virtual void WriteToLog(const std::string &str, int n) override{
        ++m_numberOfEvent;
        std::string temp = std::to_string(m_numberOfEvent) + ": " + str;
        getInternalInstanceLogger().WriteToLog(temp, n);
    }

    virtual void WriteToLog(const std::string &str, double d) override{
        ++m_numberOfEvent;
        std::string temp = std::to_string(m_numberOfEvent) + ": " + str;
        getInternalInstanceLogger().WriteToLog(temp, d);
    }

    static ILogger& getInstance(){
        static LoggerSingleton theInstance;
        return theInstance;
    }

private:
    int m_numberOfEvent = 0;

    LoggerSingleton() {}

    LoggerSingleton(const LoggerSingleton& root) = delete;
    LoggerSingleton& operator=(const LoggerSingleton&) = delete;
};

ILogger& FileLoggerSingleton::getInstance(){
    return LoggerSingleton::getInstance();
}

void FileLoggerSingleton::OpenLogFile(const std::string &FN) {
    logOut.open(FN, std::ios_base::out);
}

void FileLoggerSingleton::CloseLogFile() {
    if (logOut.is_open()) {
        logOut.close();
    }
}

std::string FileLoggerSingleton::GetCurDateTime() {
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char* buf = ctime(&time);
    return std::string(buf);
}

void FileLoggerSingleton::WriteToLog(const std::string &str) {
    if (logOut.is_open()) {
        logOut << GetCurDateTime() << " - " << str << std::endl;
    }
}

void FileLoggerSingleton::WriteToLog(const std::string &str, int n) {
    if (logOut.is_open()) {
        logOut << GetCurDateTime() << " - " << str << n << std::endl;
    }
}

void FileLoggerSingleton::WriteToLog(const std::string &str, double d) {
    if (logOut.is_open()) {
        logOut << GetCurDateTime() << " - " << str << d << std::endl;
    }
}