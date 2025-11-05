#pragma once
#include "Macro.h"

namespace engine
{

    class Exception : public std::exception
    {
        using Error = const std::string;
        Error message;

    public:
        Exception(const Error& _error) :
            message(CAST(Error, _error) + " " + DEBUG_INFO)
        {
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
//      throw engine::Exception("msg");
//  }
//  catch (const engine::Exception& _exception)
//  {
//      std::cerr << _exception.What() << std::endl;
//  }
// 
/////////////////////////////////////////////////////////