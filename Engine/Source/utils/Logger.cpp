#include "Logger.h"
#include "time/TimerManager.h"

using namespace engine;

/// VerbosityData
std::string VerbosityData::RetrieveFullText(const bool& _useColor, const bool& _useTime) const
{
    std::string _fullText;

    if (_useTime)
    {
        _fullText += "[" + M_TIMER.GetCurrentRealTime() + "]";
    }

    _fullText += " " + prefix + ": " + text;

    if (USE_DEBUG || useDebug)
    {
        _fullText += " " + debug;
    }

    return _useColor ? color.GradientString(_fullText) : _fullText;
}

void engine::VerbosityData::ComputeUseDebug(const VerbosityType& _type)
{
    useDebug = std::set<VerbosityType>({ VerbosityType::Warning, VerbosityType::Error }).contains(_type);
}

void engine::VerbosityData::ComputeColor(const VerbosityType& _type)
{
    if (_type >= VerbosityType::COUNT)
        THROW_EXCEPTION(std::format("Invalid VerbosityType, _type = {} and must be < {}", CAST(int, _type), CAST(int, VerbosityType::COUNT)));

    const std::vector<Gradient>& _verbosityColors =
    {
        Gradient(ColorData(27, 27, 33), ColorData(37, 37, 51)),         //VERY VERBOSE
        Gradient(ColorData(55, 55, 61), ColorData(69, 69, 93)),         //VERBOSE
        Gradient(ColorData(100, 100, 119), ColorData(143, 143, 194)),   //LOG
        Gradient(ColorData(221, 221, 246), ColorData(122, 122, 236)),   //DISPLAY
        Gradient(ColorData(255, 231, 0), ColorData(255, 76, 17)),       //WARNING
        Gradient(ColorData(193, 6, 11), ColorData(249, 56, 67)),        //ERROR
        Gradient(ColorData(255, 0, 95), ColorData(118, 37, 184)),       //FATAL
    };

    color = _verbosityColors[CAST(int, _type)];
}

void engine::VerbosityData::ComputePrefix(const VerbosityType& _type)
{
    if (_type >= VerbosityType::COUNT)
        THROW_EXCEPTION(std::format("Invalid VerbosityType ! _type = {} and must be < {}", CAST(int, _type), CAST(int, VerbosityType::COUNT)));

    const std::vector<std::string>& _verbosityTexts =
    {
        "VeryVerbose",
        "Verbose",
        "Log",
        "Display",
        "Warning",
        "Error",
        "Fatal",
    };

    prefix = _verbosityTexts[CAST(int, _type)];
}


/// Logger
void engine::Logger::LoggingThread()
{
    std::filesystem::create_directory("../Logs");
    std::ofstream _file(logsPath, std::ios_base::app);

    while (running || !logQueue.empty())
    {
        std::unique_lock _lock(queueMutex);
        cv.wait(_lock, [] { return 
            !logQueue.empty() ||
            !consoleQueue.empty() ||
            !running; });

        while (!logQueue.empty() || !consoleQueue.empty())
        {
            if (!consoleQueue.empty())
            {
                std::string _consoleText = consoleQueue.front();
                consoleQueue.pop();
                _lock.unlock();
                std::cout << _consoleText << std::endl;
                _lock.lock();
            }

            if (!logQueue.empty())
            {
                std::string _logText = logQueue.front();
                logQueue.pop();
                _lock.unlock();
                _file << _logText << std::endl;
                _file.flush();
                _lock.lock();
            }
        }
    }
}

void engine::Logger::EnqueueLog(const std::string& _logText)
{
    std::lock_guard _lock(queueMutex);
    logQueue.push({ _logText });
    cv.notify_one();
}

void engine::Logger::EnqueueConsole(const std::string& _consoleText)
{
    std::lock_guard _lock(queueMutex);
    consoleQueue.push({ _consoleText });
    cv.notify_one();
}

bool engine::Logger::CanPrintInLog(const VerbosityType& _type)
{
    if (_type >= VerbosityType::Log) return true;

    if (verboseLogging)
    {
        if (_type >= VerbosityType::Verbose) return true;
        if (veryVerboseLogging)
        {
            if (_type >= VerbosityType::VeryVerbose) return true;
        }
    }
    return false;
}

bool engine::Logger::CanPrintInConsole(const VerbosityType& _type)
{
    return _type > VerbosityType::Log;
}

void Logger::Init()
{
    Reset();
    running = true;
    logThread = std::thread(LoggingThread);
}

void engine::Logger::Shutdown()
{
    running = false;
    cv.notify_all();
    if (logThread.joinable())
        logThread.join();
}

void Logger::Reset()
{
    std::ofstream(logsPath, std::ios_base::trunc);
}

void Logger::PrintLog(const VerbosityType& _type, const std::string& _text, const std::string& _debug)
{
    if (CanPrintInLog(_type))
    {
        const VerbosityData& _verbosity = VerbosityData(_type, _text, _debug);
        EnqueueLog(_verbosity.RetrieveFullText(false));

        if (CanPrintInConsole(_type)) EnqueueConsole(_verbosity.RetrieveFullText(true));
    }

    if (_type == VerbosityType::Fatal) THROW_EXCEPTION("Fatal exception occurred");
}

void engine::Logger::PrintLog(const VerbosityType& _type, const IPrintable& _object, const std::string& _debug)
{
    PrintLog(_type, _object.ToString(), _debug);
}
