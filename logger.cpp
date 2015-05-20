#include "logger.h"

LogHelper::LogHelper()
{
    pConsoleCategory = NULL;
    pFileCategory = NULL;
}

LogHelper::~LogHelper()
{

}

void LogHelper::Init(const char* file, const char* module, bool debug, int record_mask/* = DT_CONSOLE | DT_FILE*/)
{
    _record_mask = record_mask;

    //显示格式
    //%c category；
    //%d 日期；日期可以进一步的设置格式，用花括号包围，例如%d{ %H:%M : %S, %l } 或者 %d{ %d %m %Y%H:%M : %S, %l }。如果不设置具体日期格式，则如下默认格式被使用“Wed Jan 02 02:03 : 55 1980”。日期的格式符号与ANSI C函数strftime中的一致。但增加了一个格式符号%l，表示毫秒，占三个十进制位。
    //%m 消息；
    //%n 换行符，会根据平台的不同而不同，但对于用户透明；
    //%p 优先级；
    //%r 自从layout被创建后的毫秒数；
    //%R 从1970年1月1日0时开始到目前为止的秒数；
    //%u 进程开始到目前为止的时钟周期数；
    //%x NDC。
    //因此，要得到上述的理想格式，可以将setConversionPattern的参数设置为“%d: %p %c %x : %m%n”，其具体含义是“时间 : 优先级 Category NDC : 消息换行”。

    if (_record_mask & DT_CONSOLE)
    {
        log4cpp::Appender *consoleAppender = new log4cpp::OstreamAppender("console", &std::cout);
        //consoleAppender->setLayout(new log4cpp::BasicLayout());
        log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
        //pLayout->setConversionPattern("%d: %p %c %x: %m%n");
        pLayout->setConversionPattern("%c--%d: %p: %m%n");
        consoleAppender->setLayout(pLayout);

        log4cpp::Category& consoleCategory = log4cpp::Category::getInstance(std::string(module));
        //默认为INFO
        if (debug)
            consoleCategory.setPriority(log4cpp::Priority::DEBUG);
        consoleCategory.addAppender(consoleAppender);

        pConsoleCategory = &consoleCategory;
    }

    if (_record_mask & DT_FILE)
    {
        log4cpp::Appender *fileAppender = new log4cpp::FileAppender("default", file);
        log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
        pLayout->setConversionPattern("%c--%d: %p: %m%n");
        fileAppender->setLayout(pLayout);

        log4cpp::Category& fileCategory = log4cpp::Category::getInstance(std::string(module));
        //默认为INFO
        if (debug)
            fileCategory.setPriority(log4cpp::Priority::DEBUG);
        fileCategory.addAppender(fileAppender);

        pFileCategory = &fileCategory;
    }
}

void LogHelper::Write(const char* content)
{
//    if (pConsoleCategory)
//        pConsoleCategory->info(content);
    if (pFileCategory)
        pFileCategory->info(content);

}
void LogHelper::Error(const char* stringFormat, ...)
{
    va_list va;
    va_start(va, stringFormat);
//    if (pConsoleCategory)
//        pConsoleCategory->error(stringFormat, va);
    if (pFileCategory)
        pFileCategory->error(stringFormat, va);
    va_end(va);
}

void LogHelper::Warn(const char* stringFormat, ...)
{
    va_list va;
    va_start(va, stringFormat);
//    if (pConsoleCategory)
//        pConsoleCategory->warn(stringFormat, va);
    if (pFileCategory)
        pFileCategory->warn(stringFormat, va);
    va_end(va);
}

void LogHelper::Info(const char* stringFormat, ...)
{
    va_list va;
    va_start(va, stringFormat);
//    if (pConsoleCategory)
//        pConsoleCategory->info(stringFormat, va);
    if (pFileCategory)
        pFileCategory->info(stringFormat, va);
    va_end(va);
}

void LogHelper::Debug(const char* stringFormat, ...)
{
    va_list va;
    va_start(va, stringFormat);
//    if (pConsoleCategory)
//        pConsoleCategory->debug(stringFormat, va);
    if (pFileCategory)
        pFileCategory->debug(stringFormat, va);
    va_end(va);
}
