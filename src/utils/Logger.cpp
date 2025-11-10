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

/// Logger
std::string Logger::logsPath = "Assets/Logs/log.txt";

void Logger::WriteInConsole(const std::string& _text)
{
    std::cout << _text << std::endl;
}

void Logger::WriteInLogs(const std::string& _text)
{
    std::ofstream _stream = std::ofstream(logsPath, std::ios_base::app);
    _stream << _text << std::endl;
}

void Logger::Reset()
{
    std::ofstream(logsPath, std::ios_base::trunc);
}

void Logger::PrintLog(const VerbosityType& _type, const std::string& _text, const std::string& _debug)
{
    if (WRITE_IN_LOG(_type))
    {
        const VerbosityData& _verbosity = VerbosityData(_type, _text, _debug);
        WriteInLogs(_verbosity.RetrieveFullText(false));

        if (WRITE_IN_CONSOLE(_type))
        {
            WriteInConsole(_verbosity.RetrieveFullText(true));
        }
    }

    if (_type == VerbosityType::Fatal) throw Exception("Fatal exception occurred");
}