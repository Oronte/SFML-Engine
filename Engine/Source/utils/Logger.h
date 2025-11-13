#pragma once
#include "Exception.h"
#include "Color.h"
#include "Printable.h"

#define DEBUG
#ifdef DEBUG
#define USE_DEBUG 1
#else
#define USE_DEBUG 0
#endif // DEBUG

#define LOG(_verbosity, _msg)   engine::Logger::PrintLog(_verbosity, _msg, DEBUG_INFO)
#define WRITE_IN_LOG(_verbosity)        _verbosity >= engine::VerbosityType::Log
#define WRITE_IN_CONSOLE(_verbosity)    _verbosity > engine::VerbosityType::Log

namespace engine
{

    enum VerbosityType
    {
        VeryVerbose,
        Verbose,
        Log,
        Display,
        Warning,
        Error,
        Fatal,

        COUNT
    };

    class VerbosityData
    {
        Gradient color;
        std::string prefix;
        std::string text;
        std::string debug;
        bool useDebug;

    public:
        VerbosityData(const VerbosityType& _type, const std::string& _text, const std::string& _debug,
            const bool& _useDebug = false)
        {
            ComputeUseDebug(_type);
            ComputeColor(_type);
            ComputePrefix(_type);
            text = _text;
            debug = _debug;
        }

    private:
        void ComputeUseDebug(const VerbosityType& _type)
        {
            useDebug = std::set<VerbosityType>({ VerbosityType::Warning, VerbosityType::Error }).contains(_type);
        }
        void ComputeColor(const VerbosityType& _type)
        {
            if (_type >= VerbosityType::COUNT)
            {
                THROW_EXCEPTION(std::format("Invalid VerbosityType ! _type = {} and must be < {}", CAST(int, _type), CAST(int, VerbosityType::COUNT)));
            }

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

            color = _verbosityColors[(int)_type];
        }
        void ComputePrefix(const VerbosityType& _type)
        {
            if (_type >= VerbosityType::COUNT)
            {
                THROW_EXCEPTION(std::format("Invalid VerbosityType ! _type = {} and must be < {}", CAST(int, _type), CAST(int, VerbosityType::COUNT)));
            }

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

            prefix = _verbosityTexts[(int)_type];
        }

    public:
        std::string RetrieveFullText(const bool& _useColor = true, const bool& _useTime = true) const;
    };

    class Logger
    {
        static std::string logsPath;

    private:
        static void WriteInLogs(const std::string& _text);
        static void WriteInConsole(const std::string& _text);

    public:
        static void Reset();
        static void PrintLog(const VerbosityType& _type, const std::string& _text, const std::string& _debug = "");
        static void PrintLog(const VerbosityType& _type, const IPrintable& _object, const std::string& _debug = "");
    };

}


//////////////////////////////////////////////////////
// 
//  LOG(VerbosityType::Warning, message);
//  LOG(VerbosityType::Fatal, message);
// 
//////////////////////////////////////////////////////