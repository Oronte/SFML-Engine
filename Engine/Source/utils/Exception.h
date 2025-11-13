#pragma once
#include "Macro.h"

#define THROW_EXCEPTION(_msg) throw Exception(_msg, DEBUG_INFO);

namespace engine
{

    class Exception : public std::exception
    {
        using Error = std::string;
        Error message;

    public:
        Exception(const Error& _error, const Error& _debugInfo = "") :
            message(_error + " " + _debugInfo)
        {
            if (_debugInfo == "") message += DEBUG_INFO;
        }

    private:
        NO_DISCARD virtual const char* what() const noexcept override
        {
            return message.c_str();
        }
    public:
        NO_DISCARD Error What() const
        {
            return what();
        }
    };

}


/////////////////////////////////////////////////////////
// 
//  try
//  {
//      TROW_EXCEPTION("msg");
//  }
//  catch (const engine::Exception& _exception)
//  {
//      std::cerr << _exception.What() << std::endl;
//  }
// 
/////////////////////////////////////////////////////////