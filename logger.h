#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"
#include <log4cpp/PatternLayout.hh>

enum DisplayType
{
    DT_CONSOLE  = 0x00000001,
    DT_FILE		= 0x00000002,
};

class LogHelper
{
public:
    LogHelper();
    ~LogHelper();

public:
    void Init(const char* file, const char* module, bool debug, int record_mask = DT_CONSOLE | DT_FILE);
    void Write(const char* content);
    void Error(const char* stringFormat, ...);
    void Warn(const char* stringFormat, ...);
    void Info(const char* stringFormat, ...);
    void Debug(const char* stringFormat, ...);

//FATAL = 0,
//ALERT = 100,
//CRIT = 200,
//ERROR = 300,
//WARN = 400,
//NOTICE = 500,
//INFO = 600,
//DEBUG = 700,
//NOTSET = 800

private:
    int _record_mask;

    log4cpp::Category* pConsoleCategory;
    log4cpp::Category* pFileCategory;
};
